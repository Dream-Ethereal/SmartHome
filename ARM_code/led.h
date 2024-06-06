#ifndef __LED_H__
#define __LED_H__

#include "serial.h"
#include "lcd.h"
#include "network.h"

extern int threshold_value[3];

extern int door_status;
extern int led_status;
extern int curtain_status;
extern int airc_status;

int led1_fd_tg, led2_fd_tg, led3_fd_tg;
int led1_fd_bn, led2_fd_bn, led3_fd_bn;
extern int sockfd;

void led_control(int tg, int bn, int state);
void init_led(void);
void *config_set(void *arg);//调整阈值
void *check(void *arg);

#endif