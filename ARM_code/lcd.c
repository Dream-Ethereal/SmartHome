#include"lcd.h"

//屏幕初始化
void lcd_init()
{
	//1.打开LCD屏幕
	fd = open("/dev/fb0",O_RDWR);
	if(-1 == fd)
	{
		printf("open lcd error!\n");
		return ;
	}
	//2.把屏幕映射到内存(mmap)
	plcd = mmap(NULL, width*height*4, PROT_READ | PROT_WRITE, MAP_SHARED,fd,0);
	if(plcd == MAP_FAILED)
	{
		printf("mmap failed!\n");
		return ;
	}
}

//关闭屏幕 
void lcd_close()
{
	//3.解映射(munmap)
	munmap(plcd,width*height*4);
	//4.关闭屏幕
	close(fd);
}

void lcd_refresh(int x0, int y0, int x, int y, int flag)
{
	for (int w_index = x0; w_index <= x; w_index++)
	{
		for (int h_index = y0; h_index <= y; h_index++)
		{
			if(flag == 1)
			{
				if(*(plcd + width * h_index + w_index) == 0X00000000)
					*(plcd + width * h_index + w_index) = bg_color[h_index][w_index];
			}else if(flag == 0)
			{
				*(plcd + width * h_index + w_index) = bg_color[h_index][w_index];
			}
			
		}
	}
	
}




//画点函数,可以在LCD屏幕指定的位置,指定颜色的点
void lcd_draw_point(int x0,int y0,int color)
{
	if(x0<0 || x0 >=width || y0<0 || y0 >=height)
	{
		printf("bro,you point out of the screen!\n");
		return;
	}
	*(plcd+width * y0+x0)= color; 
}

//清屏,可以把屏幕刷成指定的颜色
void lcd_clear(int color)
{
	int x,y;
	for(y=0;y<height;y++)
	{
		for(x=0;x<width;x++)
		{
			lcd_draw_point(x,y,color);
		}
	}
	
}

//画矩形,可以在指定的位置,显示一个指定大小,指定颜色的矩形
void lcd_draw_rect(int x0,int y0,int w,int h,int color)
{
	int x,y;
	for(y=y0;y<y0+h;y++)
	{
		for(x=x0;x<x0+w;x++)
		{
			lcd_draw_point(x,y,color);
		}
	}
}

//把名字为name的图片显示到(x0,y0)的位置
void lcd_draw_bmp(int x0,int y0,char *name,int flag)
{
	//1.打开图片文件
	int fd_bmp = open(name,O_RDWR);
	if(fd_bmp == -1)
	{
		printf("open bmp error!\n");
		return ;
	}
	//2.读取图片的像素点信息
	char buf[width*height*4+54];//准备足够大的空间
	read(fd_bmp,buf,width*height*4+54);
	//3.关闭图片文件
	close(fd_bmp);
	

    //读取图片的宽度和高度
    int w = (buf[21]<<24) | (buf[20]<<16) | (buf[19]<<8) | buf[18];
    int h = (buf[25]<<24) | (buf[24]<<16) | (buf[23]<<8) | buf[22];
    printf("w = %d,h = %d\n",w,h);

    //4.处理读取到的每一个点的信息
    int x,y;
    char a=0,r,g,b;
    int color;
    int p = 54;
    for(y=h-1;y>=0;y--) //图片有h行
    {
        for(x=0;x<w;x++) //每一行有w个点
        {
            b = buf[p++];
            g = buf[p++];
            r = buf[p++];
            color = a<<24 | r<<16 | g << 8 | b;
			if(flag == 1)
			{
				bg_color[y + y0][x + x0] = color;
			}
			if(color == 0X00FFFFFF)
			{
				continue;
			}else
            	lcd_draw_point(x+x0,y+y0,color);
        }
        //如果图片不是4的倍数,跳过填充字节
        if((w*3)%4 != 0)
        {
            p = p + 4 - (w*3)%4;
        }
    }

}

//显示屏幕的大部分功能按钮、文字
void lcd_show_btn()
{
	char text[20];
	//模式按钮
	sprintf(text, "%s_on.bmp", mode == OFF ? "automode" : "manualmode");
	lcd_refresh(8, 30, 58, 80, 0);
	lcd_draw_bmp(8, 30, text, 0);

	//空调
	sprintf(text, "airc_%s.bmp", airc_status == 1 ? "on" : "off");
	lcd_refresh(43, 90, 213, 260, 0);
	lcd_draw_bmp(43, 90, text, 0);

	//窗帘
	sprintf(text, "curtain_%s.bmp", curtain_status == 1 ? "on" : "off");
	lcd_refresh(237, 85, 407, 255, 0);
	lcd_draw_bmp(237, 85, text, 0);

	//灯泡
	sprintf(text, "led_%s.bmp", led_status == 1 ? "on" : "off");
	lcd_refresh(60, 285, 260, 350, 0);
	lcd_draw_bmp(60, 285, text, 0);

	//门
	sprintf(text, "door_%s.bmp", door_status == 1 ? "on" : "off");
	lcd_refresh(250, 303, 450, 470, 0);
	lcd_draw_bmp(250, 303, text, 0);
	
}

//触摸屏函数,可以获取手指的滑动方向
//返回值表示具体的方向1--->向上,2---->向下
int open_screen(){
	int fd_touch = open("/dev/input/event0",O_RDWR);
	if(fd_touch == -1)
	{
		printf("open event0 error!\n");
		return -1;
	}
	return fd_touch;
}

int check_swipe(int x,int y,int x0,int y0){
	if(abs(y - y0) > 10 || abs(x - x0) > 10)	//滑动
	{
		if(y < y0  && abs(y - y0) > abs(x - x0))
		{
			printf("up!\n");
			return UP;
		}else if(y > y0  && abs(y - y0) > abs(x - x0))
		{
			printf("down!\n");
			return DOWN;
		}else if (x < x0 && abs(x - x0) > abs(y - y0))
		{
			printf("left!\n");
			return LEFT;
		}else if (x0 < x && abs(x - x0) > abs(y - y0))
		{
			printf("right!\n");
			return RIGHT;
		}
	}
}

int check_tap_type(int px,int py,int x,int y,int x0,int y0,int res){
	int nx = px/1.28;
	int ny = py/1.25;
	if(nx >= x && nx <= x0 && ny >= y && ny <= y0)	//left
	{
		return res;
	}else{
		return 0;
	}
}

int get_dec()
{
	// //1.打开触摸屏
	int fd_touch = open_screen();

	//定义一个结构体,保存读取到的输入信息
	struct input_event ev;
	int x0=-1,y0=-1;
	int x,y;
	while(1)
	{
		//2.读取输入事件
		//read是一个阻塞的函数,没有数据可读的时候,会一直等待
		int ret = read(fd_touch,&ev,sizeof(ev));
		if(ret != sizeof(ev))
		{
			continue;
		}
		//3.解析输入事件
		if(ev.type == EV_ABS && ev.code == ABS_X)
		{
			if(x0 == -1)
			{
				x0 = ev.value;
			}
			x = ev.value; //记录得到的x坐标
		}
		if(ev.type == EV_ABS && ev.code == ABS_Y)
		{
			if(y0 == -1)
			{
				y0 = ev.value;
			}
			y = ev.value; //记录得到的y坐标
		}
		//当手指离开触摸屏的时候结束
		if(ev.type == EV_KEY && ev.code == BTN_TOUCH && ev.value == 0)
		{
			break;
		}
	}
	
	//4.得到坐标
	printf("x0 = %d,y0 = %d\n",x0,y0);
	printf("x = %d,y = %d\n",x,y);

	
	//根据起点和终点得到方向
	if(abs(y - y0) > 10 || abs(x - x0) > 10)	//滑动
	{
		return check_swipe(x,y,x0,y0);
	}else if(abs(y - y0) <= 10 && abs(x - x0) <= 10)	//点按
	{
		x = x / 1.28;
		y = y / 1.25;
		//得到坐标,完成什么逻辑,由用户控制
		if(x >= 8 && x <= 58 && y >= 30 && y <= 80)		//模式切换
		{
			return 1;
		}else if (x >= 43 && x <= 243 && y >= 93 && y <= 293)	//空调
		{
			return 2;
		}else if (x >= 247 && x <= 447 && y >= 113 && y <= 313)	//窗帘
		{
			return 3;
		}else if (x >= 60 && x <= 260 && y >= 285 && y <= 480)	//灯泡
		{
			return 4;
		}else if (x >= 270 && x <= 470 && y >= 303 && y <= 480)	//门
		{
			return 5;
		}
		
		
		
	}	
}


//调用这个函数就可以在指定的位置显示一个指定的位置
void lcd_draw_word(int x0,int y0,char *buf,int w,int h,int color)
{
	int index,i;
	int size = (w/8)*h;
	int len = w/8;  //一行的字节数量
	for(index = 0;index<size;index++)
	{
		//解析word[index]的8个bit
		for(i=7;i>=0;i--)
		{
			if((buf[index] & 1<<i) != 0)
			{
				//word[index]的第i个bit是1
				lcd_draw_point(8*(index%len) + 7-i  +x0,index/len + y0,color);
			}
		}
	}
}


//可以在指定的位置显示一个指定的四位数以内的数字
void lcd_draw_num(int x0,int y0,int num,int color)
{
	int x=0; //表示num的位数
	int tmp = num;
	while(tmp)
	{
		x++;
		tmp = tmp/10;
	}
	//printf("x = %d\n",x);
	while(x>0)
	{
		x--;
		int t = num%10;  //把最后一位取出来
		num = num/10;	//把最后一位去掉
		lcd_draw_word(x0+x*16,y0,dig_32x32[t],32,32,color);
	}
	
}

