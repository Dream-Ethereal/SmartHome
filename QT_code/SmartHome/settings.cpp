#include "settings.h"
#include "ui_settings.h"
#include "mainwindow.h"



settings::settings(QTcpSocket *socket, QWidget *parent)
    : QDialog(parent),
    ui(new Ui::settings), socket(socket)
{
    ui->setupUi(this);

    parent = static_cast<MainWindow*>(parent);

    //设置窗体样式
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);
    //设置窗体最大化和最小化
    Qt::WindowFlags windowFlag  = Qt::Dialog;
    windowFlag                  |= Qt::WindowMinimizeButtonHint;
    windowFlag                  |= Qt::WindowMaximizeButtonHint;
    windowFlag                  |= Qt::WindowCloseButtonHint;
    setWindowFlags(windowFlag);

    //    thresholod_tmp = 10;
    //    thresholod_wet = 100;
    //    thresholod_lux = 23;
    show_data();
    continue_add();
}

settings::~settings()
{
    delete ui;
}


void settings::show_data()
{
    ui->tmp_value->setText(QString::number(thresholod_tmp));
    ui->wet_value->setText(QString::number(thresholod_wet));
    ui->lux_value->setText(QString::number(thresholod_lux));

}






void settings::continue_add()
{
    //btn_up1
    ui->btn_up1->setAutoRepeat(true); //启用长按
    ui->btn_up1->setAutoRepeatDelay(400);//触发长按的时间
    ui->btn_up1->setAutoRepeatInterval(50);//长按时click信号间隔

    //btn_down1
    ui->btn_down1->setAutoRepeat(true); //启用长按
    ui->btn_down1->setAutoRepeatDelay(400);//触发长按的时间
    ui->btn_down1->setAutoRepeatInterval(50);//长按时click信号间隔

    //btn_up2
    ui->btn_up2->setAutoRepeat(true); //启用长按
    ui->btn_up2->setAutoRepeatDelay(400);//触发长按的时间
    ui->btn_up2->setAutoRepeatInterval(50);//长按时click信号间隔

    //btn_down2
    ui->btn_down2->setAutoRepeat(true); //启用长按
    ui->btn_down2->setAutoRepeatDelay(400);//触发长按的时间
    ui->btn_down2->setAutoRepeatInterval(50);//长按时click信号间隔

    //btn_up3
    ui->btn_up3->setAutoRepeat(true); //启用长按
    ui->btn_up3->setAutoRepeatDelay(400);//触发长按的时间
    ui->btn_up3->setAutoRepeatInterval(50);//长按时click信号间隔

    //btn_down3
    ui->btn_down3->setAutoRepeat(true); //启用长按
    ui->btn_down3->setAutoRepeatDelay(400);//触发长按的时间
    ui->btn_down3->setAutoRepeatInterval(50);//长按时click信号间隔
}



void settings::on_btn_up1_clicked()
{
    if(thresholod_tmp > 0)
        thresholod_tmp --;
    show_data();
}

void settings::on_btn_down1_clicked()
{
    if(thresholod_tmp < 100)
        thresholod_tmp ++;
    show_data();
}

void settings::on_btn_up2_clicked()
{
    if(thresholod_wet > 0)
        thresholod_wet --;
    show_data();
}

void settings::on_btn_down2_clicked()
{
    if(thresholod_wet < 100)
        thresholod_wet ++;
    show_data();
}

void settings::on_btn_up3_clicked()
{
    if(thresholod_lux > 0)
        thresholod_lux --;
    show_data();
}

void settings::on_btn_down3_clicked()
{
    if(thresholod_lux < 200)
        thresholod_lux ++;
    show_data();
}

void settings::on_btn_confirm_clicked()
{
    thresholod_tmp = ui->tmp_value->text().toUInt();
    thresholod_wet = ui->wet_value->text().toUInt();
    thresholod_lux = ui->lux_value->text().toUInt();

    char str[11];
    str[0] = 0X05;
    str[1] = (thresholod_wet >> 8) & 0XFF;
    str[2] = thresholod_wet & 0XFF;
    str[3] = 0X7F;

    str[4] = (thresholod_tmp >> 8) & 0XFF;
    str[5] = thresholod_tmp & 0XFF;
    str[6] = 0X7F;

    str[7] = (thresholod_lux >> 8) & 0XFF;
    str[8] = thresholod_lux & 0XFF;
    str[9] = 0X7F;
    str[10] = 0X7F;

//    //光照阈值检测
//    if(thresholod_lux < value[3] && mode == false)
//    {
//        if(led_status != 1)
//        {
//            led_status = 1;
//            char buf[2] = {2, led_status};
//            socket->write(buf, sizeof (buf));
//        }
//    }
//    else if(thresholod_lux >= value[3] && mode == false)
//    {
//        if(led_status != 0)
//        {
//            led_status = 0;
//            char buf[2] = {2, led_status};
//            socket->write(buf, sizeof (buf));
//        }
//    }

//    //温度阈值检测
//    if(thresholod_tmp < value[2] && mode == false)
//    {
//        if(airc_status != 1)
//        {
//            airc_status = 1;
//            char buf[2] = {4, airc_status};
//            socket->write(buf, sizeof (buf));
//        }
//    }
//    else if(thresholod_tmp >= value[2] && mode == false)
//    {
//        if(airc_status != 0)
//        {
//            airc_status = 0;
//            char buf[2] = {4, airc_status};
//            socket->write(buf, sizeof (buf));
//        }
//    }


//    //湿度阈值检测
//    if(thresholod_wet < value[4] && mode == false)
//    {
//        if(curtain_status != 0)
//        {
//            curtain_status = 0;
//            char buf[2] = {3, curtain_status};
//            socket->write(buf, sizeof (buf));
//        }
//    }
//    else if(thresholod_wet >= value[4] && mode == false)
//    {
//        if(curtain_status != 1)
//        {
//            curtain_status = 1;
//            char buf[2] = {3, curtain_status};
//            socket->write(buf, sizeof (buf));
//        }
//    }



    socket->write(str,sizeof(str));
    this->close();
}
