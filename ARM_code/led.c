#include "led.h"


int flag_data = 20;
int mode = OFF;//手动模式关

int cur_data[5] = {0};

void init_led(void)
{
	//LED 1
	led1_fd_tg = open("/sys/class/leds/led1/trigger", O_RDWR);
	if(led1_fd_tg == -1)
	{
		perror("trigger open error\n");
		return;
	}
	led1_fd_bn = open("/sys/class/leds/led1/brightness", O_RDWR);
	if(led1_fd_bn == -1)
	{
		perror("brightness open error\n");
		return;
	}
	//LED 2
	led2_fd_tg = open("/sys/class/leds/led2/trigger", O_RDWR);
	if(led2_fd_tg == -1)
	{
		perror("trigger open error\n");
		return;
	}
	led2_fd_bn = open("/sys/class/leds/led2/brightness", O_RDWR);
	if(led2_fd_bn == -1)
	{
		perror("brightness open error\n");
		return;
	}
	//LED 3
	led3_fd_tg = open("/sys/class/leds/led3/trigger", O_RDWR);
	if(led3_fd_tg == -1)
	{
		perror("trigger open error\n");
		return;
	}
	led3_fd_bn = open("/sys/class/leds/led3/brightness", O_RDWR);
	if(led3_fd_bn == -1)
	{
		perror("brightness open error\n");
		return;
	}
}

void led_control(int tg, int bn, int state)
{
	write(tg, "none", 4);
	if(state == ON)
		write(bn, "1", 1);
	else
		write(bn, "0", 1);
}

void *config_set(void *arg)
{
	char text[20];
	char buf[2];
	while (1)
	{
		memset(buf, 0x0, sizeof(buf));
		int ret = get_dec();
		printf("ret = %d\n", ret);
		if (ret == 1)	//模式切换
		{
			mode = !mode;
			sprintf(text, "%s_on.bmp", mode == OFF ? "automode" : "manualmode");
			lcd_refresh(8, 30, 58, 80, 0);
			lcd_draw_bmp(8, 30, text, 0);

			buf[0] = 0X06;
			buf[1] = mode;
			write(sockfd, buf, sizeof(buf));
		}else if (ret == 2 && mode == ON)
		{
			airc_status = !airc_status;
			sprintf(text, "airc_%s.bmp", airc_status == 1 ? "on" : "off");
			lcd_refresh(43, 90, 213, 260, 0);
			lcd_draw_bmp(43, 90, text, 0);

			buf[0] = 0X04;
			buf[1] = airc_status;
			write(sockfd, buf, sizeof(buf));
		}else if (ret == 3 && mode == ON)
		{
			curtain_status = !curtain_status;
			sprintf(text, "curtain_%s.bmp", curtain_status == 1 ? "on" : "off");
			lcd_refresh(237, 85, 407, 255, 0);
			lcd_draw_bmp(237, 85, text, 0);
			
			buf[0] = 0X03;
			buf[1] = curtain_status;
			write(sockfd, buf, sizeof(buf));
		}else if (ret == 4 && mode == ON)
		{
			led_status = !led_status;
			sprintf(text, "led_%s.bmp", led_status == 1 ? "on" : "off");
			lcd_refresh(60, 285, 260, 350, 0);
			lcd_draw_bmp(60, 285, text, 0);

			buf[0] = 0X02;
			buf[1] = led_status;
			write(sockfd, buf, sizeof(buf));
		}else if (ret == 5 && mode == ON)
		{
			door_status = !door_status;
			sprintf(text, "door_%s.bmp", door_status == 1 ? "on" : "off");
			lcd_refresh(250, 303, 450, 470, 0);
			lcd_draw_bmp(250, 303, text, 0);

			buf[0] = 0X01;
			buf[1] = door_status;
			write(sockfd, buf, sizeof(buf));
		}
		
	}
	
}

//检测阈值
void *check(void *arg)
{
	while (1)
	{
		//当当前湿度超过阈值的时候，并且模式为自动模式，进行LED1亮
		if(threshold_value[1] < cur_data[0] && mode == OFF)
		{
			led_control(led1_fd_tg, led1_fd_bn, ON);
			if(curtain_status != 0)
			{
				curtain_status = 0;
				char buf[2] = {0X03, curtain_status};
				write(sockfd, buf, sizeof(buf));
			}
		}
		else if(threshold_value[1] >= cur_data[0] && mode == OFF)
		{
			led_control(led1_fd_tg, led1_fd_bn, OFF);
			if(curtain_status != 1)
			{
				curtain_status = 1;
				char buf[2] = {0X03, curtain_status};
				write(sockfd, buf, sizeof(buf));
			}
		}
			

		//当当前温度超过阈值的时候，并且模式为自动模式，进行LED2亮
		if(threshold_value[0] < cur_data[3] && mode == OFF)
		{
			led_control(led2_fd_tg, led2_fd_bn, ON);
			if(airc_status != 1)
			{
				airc_status = 1;
				char buf[2] = {0X04, airc_status};
				write(sockfd, buf, sizeof(buf));
			}			
		}
		else if(threshold_value[0] >= cur_data[3] && mode == OFF)
		{
			led_control(led2_fd_tg, led2_fd_bn, OFF);
			if(airc_status != 0)
			{
				airc_status = 0;
				char buf[2] = {0X04, airc_status};
				write(sockfd, buf, sizeof(buf));
			}		
		}
		
		//当当前光照强度超过阈值的时候，并且模式为自动模式，进行LED3亮
		if(threshold_value[2] < cur_data[4] && mode == OFF)
		{
			led_control(led3_fd_tg, led3_fd_bn, ON);
			if(led_status != 1)
			{
				led_status = 1;
				char buf[2] = {0X02, led_status};
				write(sockfd, buf, sizeof(buf));
			}
		}
		else if(threshold_value[2] >= cur_data[4] && mode == OFF)
		{
			led_control(led3_fd_tg, led3_fd_bn, OFF);
			if(led_status != 0)
			{
				led_status = 0;
				char buf[2] = {0X02, led_status};
				write(sockfd, buf, sizeof(buf));
			}
		}
	}

}