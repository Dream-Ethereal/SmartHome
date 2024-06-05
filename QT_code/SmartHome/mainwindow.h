#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include <QString>
#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void show_data(int index);      //根据收到的数据显示在界面上
    explicit MainWindow(const QString &ip_address, qint16 ip_port, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_connected();                //连接成功会触发该函数
    void on_disconnected();             //连接失败会触发该函数
    void on_readData();                 //读取数据并处理

    void on_btn_airc_clicked();         //手动控制空调
    void on_btn_curtain_clicked();      //手动控制窗帘
    void on_btn_led_clicked();          //手动控制灯泡
    void on_btn_door_clicked();         //手动控制门锁

    void on_btn_disconnect_clicked();   //断开连接/重新连接
    void sockedStateChange(QAbstractSocket::SocketState);//检测并展示连接状态
    void on_btn_mode_clicked();         //模式切换：手动/自动

private:
    Ui::MainWindow *ui;             //ui界面
    QTcpSocket *socket;             //网络通信
    Dialog *dialog;                 //子窗口：连接服务器
    QString ip_address;             //子窗口传来的ip地址参数
    quint16 ip_port;                //子窗口传来的端口号参数

    quint16 value[5] = {0};         //传感器的数据，分别是：大气压强、海拔、温度、光照强度、湿度
    QString value_name[5] = {"pasc_value", "hum_value", "tmp_value", "lux_value", "wet_value"};//Label名数组
    bool mode = false;              //模式控制：初始为自动模式

    bool connect_status = false;    //连接标志

    //电器状态
    bool led_status = false;        //灯泡
    bool door_status = false;       //门
    bool curtain_status = false;    //窗帘
    bool airc_status = false;       //空调
};
#endif // MAINWINDOW_H
