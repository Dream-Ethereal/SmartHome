#include "mainwindow.h"
#include "ui_mainwindow.h"


//显示数据
void MainWindow::show_data(int index)
{
    switch (index) {
    case 0:                 //压强
        ui->pasc_value->setText(QString::number(value[index]));
        break;
    case 1:                 //海拔
        ui->hum_value->setText(QString::number(value[index]));
        break;
    case 2:                 //温度
        ui->tmp_value->setText(QString::number(value[index]));
        break;
    case 3:                 //光照
        ui->lux_value->setText(QString::number(value[index]));
        break;
    case 4:                 //湿度
        ui->wet_value->setText(QString::number(value[index]));
        break;
    }
}

MainWindow::MainWindow(const QString &ip_address, qint16 ip_port, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), ip_address(ip_address), ip_port(ip_port)
{
    ui->setupUi(this);


    socket = new QTcpSocket(this);

    //建立信号与槽的连接
    connect(socket, SIGNAL(connected()), this, SLOT(on_connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(on_disconnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(on_readData()));
    connect(socket, SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this, SLOT(sockedStateChange(QAbstractSocket::SocketState)));

    //连接服务器ip和端口
    socket->connectToHost(ip_address, ip_port);
}
MainWindow::~MainWindow()
{
    delete ui;
    //断开连接
    socket->disconnectFromHost();
}

void MainWindow::on_connected()
{
    qDebug() << "连接成功！\n";
}

void MainWindow::on_disconnected()
{
    qDebug() << "连接失败！\n";
}

//读取数据
void MainWindow::on_readData()
{
    //开始读取数据
    while(socket->bytesAvailable() > 0)
    {
        //  类型|压强   |海拔     |温度     |光照    |湿度    |结束
        //0X 00 00 14 7F 00 14 7F 00 14 7F 00 14 7F 00 14 7F 7F
        char buf[17];//17位数据，
        socket->read(buf, sizeof(buf));

        if(buf[0] == 0x01)//门状态改变
        {
            door_status = buf[1];
            QString style = "QPushButton#btn_door{background-image: url(:/images/door_%1.png);background-color: transparent;}";
            ui->btn_door->setStyleSheet(style.arg(door_status == 0 ? "off" : "on")); //切换开关状态
        }else if(buf[0] == 0x02)//灯状态改变
        {
            led_status = buf[1];
            QString style = "QPushButton#btn_led{background-image: url(:/images/led_%1.png);background-color: transparent;}";
            ui->btn_led->setStyleSheet(style.arg(led_status == 0 ? "off" : "on")); //切换开关状态
        }else if(buf[0] == 0x03)//窗帘状态改变
        {
            curtain_status = buf[1];
            QString style = "QPushButton#btn_curtain{background-image: url(:/images/curtain_%1.png);background-color: transparent;}";
            ui->btn_curtain->setStyleSheet(style.arg(curtain_status == 0 ? "off" : "on"));//切换开关状态
        }else if (buf[0] == 0x04) {//空调状态改变
            airc_status = buf[1];
            QString style = "QPushButton#btn_airc{background-image: url(:/images/airc_%1.png);background-color: transparent;}";
            ui->btn_airc->setStyleSheet(style.arg(airc_status == 0 ? "off" : "on"));//切换开关状态
        }else if(buf[0] == 0x00)    //获取传感器数据
        {

            QString temp;
            int cnt = 0;
            for(int i = 1; i < 17; i++)//从1开始读数据
            {
                if(buf[i] == 0X7F)//分隔符
                {
                    value[cnt] = (quint16)temp.toUInt();//16进制转换10进制
                    show_data(cnt);//展示
                    cnt++;
                    temp.clear();
                    if(buf[i + 1] == 0X7F)//结束
                    {
                        break;
                    }
                }else
                {
                    temp.append(QString::number(buf[i]));//数据未读完
                }
            }
        }
    }
}


//检测并展示连接状态
void MainWindow::sockedStateChange(QAbstractSocket::SocketState socketState)
{
    switch (socketState) {
    case QAbstractSocket::UnconnectedState:
        qDebug() << "未连接服务器！\n";
        qDebug() << "连接失败！\n";
        connect_status = false;
        ui->btn_disconnect->setStyleSheet("QPushButton#btn_disconnect{background-image: url(:/images/connect.png);background-color: transparent;}");
        ui->info->setText("连接失败，点击重新连接");
        break;
    case QAbstractSocket::ConnectedState:
        qDebug() << "已经连接服务器\n";
        qDebug() << "连接成功！\n";
        connect_status = true;
        ui->btn_disconnect->setStyleSheet("QPushButton#btn_disconnect{background-image: url(:/images/disconnect.png);background-color: transparent;}");
        ui->info->setText("连接成功，点击断开连接");
        break;
    default:
        break;
    }
}

//点击空调按钮，实现状态反转，改变图片
void MainWindow::on_btn_airc_clicked()
{
    if(mode == true && connect_status == true)  //当模式为手动模式，才可以手动点击开关
    {
        airc_status =! airc_status;
        QString style = "QPushButton#btn_airc{background-image: url(:/images/airc_%1.png);background-color: transparent;}";
        ui->btn_airc->setStyleSheet(style.arg(airc_status == false ? "off" : "on"));
        char buf[2] = {4, airc_status};
        socket->write(buf, sizeof (buf));
    }else if(connect_status == false)           //当前还未连接，下同
    {
        QMessageBox::critical(this, tr("错误！"), tr("当前还未连接服务器，请先连接！"));
    }else if(mode == false)                     //当前处于自动模式，下同
    {
        QMessageBox::critical(this, tr("错误！"), tr("当前属于自动模式，请先关闭自动模式再进行手动操作！"));
    }

}

//点击窗帘按钮，实现状态反转，改变图片
void MainWindow::on_btn_curtain_clicked()
{
    if(mode == true && connect_status == true)//当模式为手动模式，才可以手动点击开关
    {
        curtain_status =! curtain_status;
        QString style = "QPushButton#btn_curtain{background-image: url(:/images/curtain_%1.png);background-color: transparent;}";
        ui->btn_curtain->setStyleSheet(style.arg(curtain_status == false ? "off" : "on"));
        char buf[2] = {3, curtain_status};
        socket->write(buf, sizeof (buf));
    }else if(connect_status == false)
    {
        QMessageBox::critical(this, tr("错误！"), tr("当前还未连接服务器，请先连接！"));
    }else if(mode == false)
    {
        QMessageBox::critical(this, tr("错误！"), tr("当前属于自动模式，请先关闭自动模式再进行手动操作！"));
    }

}

//点击灯泡按钮，实现状态反转，改变图片
void MainWindow::on_btn_led_clicked()
{
    if(mode == true && connect_status == true)//当模式为手动模式，才可以手动点击开关
    {
        led_status =! led_status;
        QString style = "QPushButton#btn_led{background-image: url(:/images/led_%1.png);background-color: transparent;}";
        ui->btn_led->setStyleSheet(style.arg(led_status == false ? "off" : "on"));
        char buf[2] = {2, led_status};
        socket->write(buf, sizeof (buf));
    }else if(connect_status == false)
    {
        QMessageBox::critical(this, tr("错误！"), tr("当前还未连接服务器，请先连接！"));
    }else if(mode == false)
    {
        QMessageBox::critical(this, tr("错误！"), tr("当前属于自动模式，请先关闭自动模式再进行手动操作！"));
    }

}

//点击门按钮，实现状态反转，改变图片
void MainWindow::on_btn_door_clicked()
{
    if(mode == true && connect_status == true)//当模式为手动模式，才可以手动点击开关
    {
        door_status =! door_status;
        QString style = "QPushButton#btn_door{background-image: url(:/images/door_%1.png);background-color: transparent;}";
        ui->btn_door->setStyleSheet(style.arg(door_status == false ? "off" : "on"));
        char buf[2] = {1, door_status};
        socket->write(buf, sizeof (buf));
    }else if(connect_status == false)
    {
        QMessageBox::critical(this, tr("错误！"), tr("当前还未连接服务器，请先连接！"));
    }else if(mode == false)
    {
        QMessageBox::critical(this, tr("错误！"), tr("当前属于自动模式，请先关闭自动模式再进行手动操作！"));
    }

}

//断开连接/开始连接
void MainWindow::on_btn_disconnect_clicked()
{
    if(connect_status == false)         //当前断开连接，点击需要重新连接
    {
        qDebug() << "重新连接！\n";
    }else if(connect_status == true)    //当前已经连接，点击需要断开连接
    {
        socket->disconnectFromHost();
        qDebug() << "断开连接！\n";
    }
    dialog = new Dialog();
    this->close();
    dialog->show();
}

//模式切换
void MainWindow::on_btn_mode_clicked()
{
    if(connect_status == true)
    {
        mode = !mode;
        QString style = "#btn_mode{background-image: url(:/images/%1_on.png);background-color: transparent;}";
        ui->btn_mode->setStyleSheet(style.arg(mode == false ? "automode" : "manualmode"));
    }else
    {
        QMessageBox::critical(this, tr("错误！"), tr("当前还未连接服务器，请先连接！"));
    }

}
