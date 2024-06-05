#ifndef __SERIAL_H__
#define __SERIAL_H__

#include <termios.h>
#include "lcd.h"

//初始化串口
int init_serial(const char *file, int baudrate);


#endif 