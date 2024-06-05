#include "led.h"
#include <pthread.h>
#include "network.h"

extern int cur_data[5];//传感器数据
extern int led1_fd_tg, led2_fd_tg, led3_fd_tg;
extern int led1_fd_bn, led2_fd_bn, led3_fd_bn;

int door_status = 0;
int led_status = 0;
int curtain_status = 0;
int airc_status = 0;


int main()
{
	//屏幕初始化
	lcd_init();
	lcd_draw_bmp(0,0,"bg.bmp", 1);

	

	//串口初始化
	int se_ret = init_serial("/dev/ttySAC1", 9600);
	if(se_ret == -1)
	{
		perror("serial open error\n");
		return -1;
	}

	//led初始化
	init_led();

	//网络初始化
	init_network();

	pthread_t pid, pid2, pid3, pid4;
	pthread_create(&pid, NULL, config_set, NULL);
	pthread_create(&pid2, NULL, check, NULL);
	pthread_create(&pid3, NULL, send_data, NULL);
	pthread_create(&pid4, NULL, reci_data, NULL);

	char cmd[3] = {0XA5, 0X83, 0X28};
	write(se_ret, cmd, 3);


	//此处就可以通过操作内存直接操作屏幕
	lcd_show_btn();
	while (1)
	{
		//接受传感器数据
		sleep(1);
		char ack[32] = {0};
		int r = read(se_ret, ack, 32);

		// if(r != 9 && r!=15)
		// {
		// 	perror("read CY39 error\n");
		// 	continue;
		// }

		//检测数据是否合法
		int show_x = 589;
		int show_y[5] = {130,197,264,334,404};

		if(ack[0] == 0X5A && ack[1] == 0X5A)
		{
			//光照强度
			cur_data[4] = (ack[4] << 24 | ack[5] << 16 | ack[6] << 8 | ack[7]) / 100;
			lcd_refresh(show_x, show_y[4], show_x + 32 * 2, show_y[4] + 32, 1);
			lcd_draw_num(show_x, show_y[4], cur_data[4], 0X00000000);

			//温度
			cur_data[3] = (ack[4 + 9] << 8 | ack[5 + 9] ) / 100;
			lcd_refresh(show_x, show_y[3], show_x + 32 * 2, show_y[3] + 32, 1);
			lcd_draw_num(show_x, show_y[3], cur_data[3], 0X00000000);

			//大气压强
			cur_data[2] = ((ack[6 + 9] << 24) | (ack[7 + 9] << 16) | (ack[8 + 9] << 8) | ack[9 + 9])/ 100 / 1000;
			lcd_refresh(show_x, show_y[2], show_x + 32 * 2, show_y[2] + 32, 1);
			lcd_draw_num(show_x, show_y[2], cur_data[2], 0X00000000);

			//海拔
			cur_data[1] = ((ack[12 + 9] << 8) | ack[13 + 9]);
			lcd_refresh(show_x, show_y[1], show_x + 32 * 2, show_y[1] + 32, 1);
			lcd_draw_num(show_x, show_y[1], cur_data[1], 0X00000000);

			//湿度
			cur_data[0] = ((ack[10 + 9] << 8) | ack[11 + 9]) / 100;
			lcd_refresh(show_x, show_y[0], show_x + 32 * 2, show_y[0] + 32, 1);
			lcd_draw_num(show_x, show_y[0], cur_data[0], 0X00000000);

			//printf("lux = %d, tem = %d, pas = %d, height = %d, wet = %d\n", cur_data[4], cur_data[3], cur_data[2], cur_data[1], cur_data[0]);
		}
	}
	
	//pthread_join(&pid,)

	//关闭串口
	close(se_ret);

	//关闭屏幕 
	lcd_close();

	close(sockfd);
	
	close(led1_fd_bn);
	close(led1_fd_tg);
	close(led2_fd_bn);
	close(led2_fd_tg);
	close(led3_fd_bn);
	close(led3_fd_tg);
	return 0;
}