#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QTcpSocket>


extern quint16 value[5];
extern quint16 thresholod_tmp;
extern quint16 thresholod_wet;
extern quint16 thresholod_lux;
extern bool mode;              //模式控制：初始为自动模式
extern bool led_status;        //灯泡
extern bool door_status;       //门
extern bool curtain_status;    //窗帘
extern bool airc_status;       //空调
class MainWindow;

namespace Ui {
class settings;
}

class settings : public QDialog
{
    Q_OBJECT

public:
    explicit settings(QTcpSocket *socket, QWidget *parent = nullptr);
    ~settings();

private slots:


    void on_btn_up1_clicked();

    void on_btn_down1_clicked();

    void on_btn_up2_clicked();

    void on_btn_down2_clicked();

    void on_btn_up3_clicked();

    void on_btn_down3_clicked();

    void on_btn_confirm_clicked();


private:
    Ui::settings *ui;
    QTcpSocket *socket;
    MainWindow *parent;


    void show_data();
    void continue_add();
};

#endif // SETTINGS_H
