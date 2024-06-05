#ifndef __LCD_H__
#define __LCD_H__

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <linux/input.h>
#include <stdlib.h>
#include "word.h"

enum touch_type{
    DEFAULT,
    UP,
    DOWN,
    LEFT,
    RIGHT,
    LEFTBTN,
    RIGHTBTN,
    MODEBTN,
    POWERBTN
};

enum mode_type{
    OFF,
    ON
};

extern int mode;
extern int door_status;
extern int led_status;
extern int curtain_status;
extern int airc_status;

static int width = 800;
static int height = 480;
static int left_x = 200;
static int left_y = 380;
static int right_x = 500;
static int right_y = 380;
static int fd = 0;//屏幕的文件描述符
static int *plcd = NULL; //屏幕映射后的地址

static int bg_color[480][800] = {0};


void lcd_init();
 
void lcd_close();

void lcd_refresh(int x0, int y0, int x, int y, int flag);

void lcd_draw_point(int x0,int y0,int color);

void lcd_clear(int color);

void lcd_draw_rect(int x0,int y0,int w,int h,int color);

void lcd_show_btn();

void lcd_draw_bmp(int x0,int y0,char *name, int flag);

int get_touch();


int get_dec();

int check_tap_type(int px,int py,int x,int y,int x0,int y0,int res);

int check_swipe(int x,int y,int x0,int y0);

int open_screen();

void lcd_draw_word(int x0,int y0,char *buf,int w,int h,int color);

void lcd_draw_num(int x0,int y0,int num,int color);

#endif 