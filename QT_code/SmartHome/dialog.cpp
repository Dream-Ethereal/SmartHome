#include "dialog.h"
#include "ui_dialog.h"
#include "mainwindow.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);


    //设置窗体样式
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);
    //设置窗体最大化和最小化
    Qt::WindowFlags windowFlag  = Qt::Dialog;
    windowFlag                  |= Qt::WindowMinimizeButtonHint;
    windowFlag                  |= Qt::WindowMaximizeButtonHint;
    windowFlag                  |= Qt::WindowCloseButtonHint;
    setWindowFlags(windowFlag);



}

Dialog::~Dialog()
{
    delete ui;
}

//点击按钮进行连接服务器
void Dialog::on_pushButton_clicked()
{
    //根据输入的ip和port，传参给主窗口进行服务器连接，进行窗口切换
    mainwindow = new MainWindow(ui->ip_text->text(), ui->port_text->text().toUShort());
    //mainwindow = new MainWindow("47.98.153.253", 10086);
    this->close();
    mainwindow->show();
}
