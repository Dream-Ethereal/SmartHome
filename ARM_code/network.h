#ifndef __NETWORK_H__
#define __NETWORK_H__

#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "led.h"

#define SERVER_IPADDRESS    "47.98.153.253"
#define SERVER_IPPORT       11157

int sockfd;
char ans[4];

//阈值
int threshold_value[3];

extern int cur_data[5];//传感器数据

extern int door_status;
extern int led_status;
extern int curtain_status;
extern int airc_status;


int init_network(void);
void *send_data(void *arg);
void *reci_data(void *arg);
#endif 