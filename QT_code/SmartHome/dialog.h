#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTcpSocket>


namespace Ui {
class Dialog;
}

class MainWindow;

class Dialog : public QDialog
{
    Q_OBJECT
public:
    Ui::Dialog *ui;
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();


private slots:
    void on_pushButton_clicked();       //连接服务器


private:
    MainWindow *mainwindow;

};

#endif // DIALOG_H
