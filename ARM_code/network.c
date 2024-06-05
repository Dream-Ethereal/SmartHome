#include "network.h"


int init_network(void)
{
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {0};

    if(0 > sockfd)
    {
        perror("socket error");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family  = AF_INET;
    server_addr.sin_port = htons(SERVER_IPPORT);
    inet_pton(AF_INET, SERVER_IPADDRESS, &server_addr.sin_addr);

    int ret = connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if(0 > ret)
    {
        perror("connect error");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("服务器连接成功...\n");
    return 0;
}



void *send_data(void *arg)
{
    //网络初始化
	//init_network();
    int index = 0;
    char buf[17];
    while (1)
    {
        sleep(1);
        memset(buf, 0x0, sizeof(buf));
        index = 0;
        buf[index ++] = 0X00;

        //大气压强
        buf[index ++] = (cur_data[2] >> 8) & 0XFF;
        buf[index ++] = cur_data[2] & 0XFF;
        buf[index ++] = 0X7F;

        //海拔
        buf[index ++] = (cur_data[1] >> 8) & 0XFF;
        buf[index ++] = cur_data[1] & 0XFF;
        buf[index ++] = 0X7F;

        //温度
        buf[index ++] = (cur_data[3] >> 8) & 0XFF;
        buf[index ++] = cur_data[3] & 0XFF;
        buf[index ++] = 0X7F;

        //光照
        buf[index ++] = (cur_data[4] >> 8) & 0XFF;
        buf[index ++] = cur_data[4] & 0XFF;
        buf[index ++] = 0X7F;

        //湿度
        buf[index ++] = (cur_data[0] >> 8) & 0XFF;
        buf[index ++] = cur_data[0] & 0XFF;
        buf[index ++] = 0X7F;
        buf[index] = 0X7F;
        //printf("lux = %d, tem = %d, pas = %d, height = %d, wet = %d\n", cur_data[4], cur_data[3], cur_data[2], cur_data[1], cur_data[0]);
        // printf("bits : %d\n", index + 1);
        // for (int i = 0; i <= index; i++)
        // {
        //     printf("%02X ", buf[i]);
        // }
        // printf("\n");
        int ret = send(sockfd, buf, sizeof(buf), 0);
        if(0 > ret)
        {
            perror("send error");
            break;
        }
    }
    
}


void *reci_data(void *arg)
{
    //网络初始化
	//init_network();
    char text[20];
    char reci_buf[17];
    while(1)
    {
        memset(reci_buf, 0x0, sizeof(reci_buf));

        //读取数据
        int ret = recv(sockfd, reci_buf, sizeof(reci_buf), 0);
        if(0 >= ret)
        {
            perror("recv data error");
            close(sockfd);
            break;
        }

        //调试信息
        // printf("reci data : ");
        // for(int i = 0; i < 17; i++)
        // {
        //     printf("%02X ", reci_buf[i]);
        // }
        // printf("\n");


        //对接受的数据进行处理
        if(reci_buf[0] == 0X01)          //对于门状态的获取
        {
            door_status = reci_buf[1];
            //显示对应图片
            sprintf(text, "door_%s.bmp", door_status == 1 ? "on" : "off");
            lcd_refresh(250, 303, 450, 470, 0);
			lcd_draw_bmp(250, 303, text, 0);
        }else if(reci_buf[0] == 0X02)    //对于灯泡状态的获取
        {
            led_status = reci_buf[1];
            sprintf(text, "led_%s.bmp", led_status == 1 ? "on" : "off");
            lcd_refresh(60, 285, 260, 350, 0);
			lcd_draw_bmp(60, 285, text, 0);
        }else if(reci_buf[0] == 0X03)    //对于窗帘状态的获取
        {
            curtain_status = reci_buf[1];
            sprintf(text, "curtain_%s.bmp", curtain_status == 1 ? "on" : "off");
            lcd_refresh(237, 85, 407, 255, 0);
			lcd_draw_bmp(237, 85, text, 0);
        }else if(reci_buf[0] == 0X04)    //对于空调状态的获取
        {
            airc_status = reci_buf[1];
            sprintf(text, "airc_%s.bmp", airc_status == 1 ? "on" : "off");
            lcd_refresh(43, 90, 213, 260, 0);
			lcd_draw_bmp(43, 90, text, 0);
        }else if (reci_buf[0] == 0X05)  //阈值获取
        {
            threshold_value[0] = (reci_buf[1] << 8) + reci_buf[2];  //湿度阈值
            threshold_value[1] = (reci_buf[4] << 8) + reci_buf[5];  //温度阈值
            threshold_value[2] = (reci_buf[7] << 8) + reci_buf[8];  //光照阈值
            printf("wet = %d, temp = %d, lux = %d\n", threshold_value[0], threshold_value[1], threshold_value[2]);
        }
    }
    
}