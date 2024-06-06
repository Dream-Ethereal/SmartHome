#include "mainwindow.h"
#include "dialog.h"
#include <QApplication>
#include "settings.h"

quint16 thresholod_tmp = 40;
quint16 thresholod_wet = 90;
quint16 thresholod_lux = 100;
quint16 value[5] = {0};         //传感器的数据，分别是：大气压强、海拔、温度、光照强度、湿度
bool mode = false;              //模式控制：初始为自动模式

bool led_status = false;        //灯泡
bool door_status = false;       //门
bool curtain_status = true;    //窗帘
bool airc_status = false;       //空调

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog login;
    login.show();
    return a.exec();
}
