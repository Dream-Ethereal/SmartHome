/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *btn_curtain;
    QPushButton *btn_door;
    QPushButton *btn_airc;
    QPushButton *btn_led;
    QPushButton *btn_disconnect;
    QLabel *info;
    QLabel *pasc_value;
    QLabel *hum_value;
    QLabel *tmp_value;
    QLabel *lux_value;
    QLabel *wet_value;
    QLabel *pasc_union;
    QLabel *hum_union;
    QLabel *tmp_union;
    QLabel *lux_union;
    QLabel *wet_union;
    QPushButton *btn_mode;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 600);
        MainWindow->setMinimumSize(QSize(1000, 600));
        MainWindow->setMaximumSize(QSize(1000, 600));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/pm.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 1000, 600));
        widget->setMinimumSize(QSize(1000, 600));
        widget->setMaximumSize(QSize(1000, 600));
        widget->setStyleSheet(QString::fromUtf8("#widget{\n"
"	background-image: url(:/images/bg.png);\n"
"}"));
        layoutWidget = new QWidget(widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(470, 140, 489, 448));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btn_curtain = new QPushButton(layoutWidget);
        btn_curtain->setObjectName(QString::fromUtf8("btn_curtain"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_curtain->sizePolicy().hasHeightForWidth());
        btn_curtain->setSizePolicy(sizePolicy);
        btn_curtain->setMinimumSize(QSize(200, 200));
        btn_curtain->setMaximumSize(QSize(200, 200));
        btn_curtain->setStyleSheet(QString::fromUtf8("QPushButton#btn_curtain\n"
"{\n"
"	background-image: url(:/images/curtain_off.png);\n"
"	background-color: transparent;\n"
"}"));
        btn_curtain->setFlat(true);

        gridLayout->addWidget(btn_curtain, 0, 1, 1, 1);

        btn_door = new QPushButton(layoutWidget);
        btn_door->setObjectName(QString::fromUtf8("btn_door"));
        sizePolicy.setHeightForWidth(btn_door->sizePolicy().hasHeightForWidth());
        btn_door->setSizePolicy(sizePolicy);
        btn_door->setMinimumSize(QSize(200, 200));
        btn_door->setMaximumSize(QSize(200, 200));
        btn_door->setStyleSheet(QString::fromUtf8("QPushButton#btn_door\n"
"{\n"
"	background-image: url(:/images/door_off.png);\n"
"	background-color: transparent;\n"
"}"));
        btn_door->setFlat(true);

        gridLayout->addWidget(btn_door, 1, 1, 1, 1);

        btn_airc = new QPushButton(layoutWidget);
        btn_airc->setObjectName(QString::fromUtf8("btn_airc"));
        btn_airc->setEnabled(true);
        sizePolicy.setHeightForWidth(btn_airc->sizePolicy().hasHeightForWidth());
        btn_airc->setSizePolicy(sizePolicy);
        btn_airc->setMinimumSize(QSize(200, 200));
        btn_airc->setMaximumSize(QSize(200, 200));
        btn_airc->setStyleSheet(QString::fromUtf8("QPushButton#btn_airc\n"
"{\n"
"	background-image: url(:/images/airc_off.png);\n"
"	background-color: transparent;\n"
"}"));
        btn_airc->setFlat(true);

        gridLayout->addWidget(btn_airc, 0, 0, 1, 1);

        btn_led = new QPushButton(layoutWidget);
        btn_led->setObjectName(QString::fromUtf8("btn_led"));
        sizePolicy.setHeightForWidth(btn_led->sizePolicy().hasHeightForWidth());
        btn_led->setSizePolicy(sizePolicy);
        btn_led->setMinimumSize(QSize(200, 200));
        btn_led->setMaximumSize(QSize(200, 200));
        btn_led->setStyleSheet(QString::fromUtf8("QPushButton#btn_led\n"
"{\n"
"	background-image: url(:/images/led_off.png);\n"
"	background-color: transparent;\n"
"}"));
        btn_led->setFlat(true);

        gridLayout->addWidget(btn_led, 1, 0, 1, 1);

        btn_disconnect = new QPushButton(widget);
        btn_disconnect->setObjectName(QString::fromUtf8("btn_disconnect"));
        btn_disconnect->setGeometry(QRect(870, 30, 50, 50));
        btn_disconnect->setStyleSheet(QString::fromUtf8("QPushButton#btn_disconnect\n"
"{\n"
"	background-image: url(:/images/connect.png);\n"
"	background-color: transparent;\n"
"}"));
        btn_disconnect->setAutoDefault(false);
        btn_disconnect->setFlat(true);
        info = new QLabel(widget);
        info->setObjectName(QString::fromUtf8("info"));
        info->setGeometry(QRect(760, 80, 271, 21));
        sizePolicy.setHeightForWidth(info->sizePolicy().hasHeightForWidth());
        info->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        font.setPointSize(8);
        font.setBold(true);
        font.setWeight(75);
        info->setFont(font);
        info->setAlignment(Qt::AlignCenter);
        pasc_value = new QLabel(widget);
        pasc_value->setObjectName(QString::fromUtf8("pasc_value"));
        pasc_value->setGeometry(QRect(210, 162, 130, 50));
        pasc_value->setMinimumSize(QSize(130, 50));
        pasc_value->setMaximumSize(QSize(130, 50));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Bahnschrift SemiLight"));
        font1.setPointSize(30);
        font1.setBold(true);
        font1.setWeight(75);
        pasc_value->setFont(font1);
        pasc_value->setAlignment(Qt::AlignCenter);
        hum_value = new QLabel(widget);
        hum_value->setObjectName(QString::fromUtf8("hum_value"));
        hum_value->setGeometry(QRect(210, 242, 130, 50));
        hum_value->setMinimumSize(QSize(130, 50));
        hum_value->setMaximumSize(QSize(130, 50));
        hum_value->setFont(font1);
        hum_value->setAlignment(Qt::AlignCenter);
        tmp_value = new QLabel(widget);
        tmp_value->setObjectName(QString::fromUtf8("tmp_value"));
        tmp_value->setGeometry(QRect(210, 324, 130, 50));
        tmp_value->setMinimumSize(QSize(130, 50));
        tmp_value->setMaximumSize(QSize(130, 50));
        tmp_value->setFont(font1);
        tmp_value->setAlignment(Qt::AlignCenter);
        lux_value = new QLabel(widget);
        lux_value->setObjectName(QString::fromUtf8("lux_value"));
        lux_value->setGeometry(QRect(210, 406, 130, 50));
        lux_value->setMinimumSize(QSize(130, 50));
        lux_value->setMaximumSize(QSize(130, 50));
        lux_value->setFont(font1);
        lux_value->setAlignment(Qt::AlignCenter);
        wet_value = new QLabel(widget);
        wet_value->setObjectName(QString::fromUtf8("wet_value"));
        wet_value->setGeometry(QRect(210, 492, 130, 50));
        wet_value->setMinimumSize(QSize(130, 50));
        wet_value->setMaximumSize(QSize(130, 50));
        wet_value->setFont(font1);
        wet_value->setAlignment(Qt::AlignCenter);
        pasc_union = new QLabel(widget);
        pasc_union->setObjectName(QString::fromUtf8("pasc_union"));
        pasc_union->setGeometry(QRect(330, 150, 100, 70));
        pasc_union->setMinimumSize(QSize(100, 70));
        pasc_union->setMaximumSize(QSize(100, 70));
        pasc_union->setFont(font1);
        pasc_union->setAlignment(Qt::AlignCenter);
        hum_union = new QLabel(widget);
        hum_union->setObjectName(QString::fromUtf8("hum_union"));
        hum_union->setGeometry(QRect(330, 230, 100, 70));
        hum_union->setMinimumSize(QSize(100, 70));
        hum_union->setMaximumSize(QSize(100, 70));
        hum_union->setFont(font1);
        hum_union->setAlignment(Qt::AlignCenter);
        tmp_union = new QLabel(widget);
        tmp_union->setObjectName(QString::fromUtf8("tmp_union"));
        tmp_union->setGeometry(QRect(323, 315, 100, 70));
        tmp_union->setMinimumSize(QSize(100, 70));
        tmp_union->setMaximumSize(QSize(100, 70));
        tmp_union->setFont(font1);
        tmp_union->setAlignment(Qt::AlignCenter);
        lux_union = new QLabel(widget);
        lux_union->setObjectName(QString::fromUtf8("lux_union"));
        lux_union->setGeometry(QRect(330, 398, 100, 70));
        lux_union->setMinimumSize(QSize(100, 70));
        lux_union->setMaximumSize(QSize(100, 70));
        lux_union->setFont(font1);
        lux_union->setAlignment(Qt::AlignCenter);
        wet_union = new QLabel(widget);
        wet_union->setObjectName(QString::fromUtf8("wet_union"));
        wet_union->setGeometry(QRect(330, 480, 100, 70));
        wet_union->setMinimumSize(QSize(100, 70));
        wet_union->setMaximumSize(QSize(100, 70));
        wet_union->setFont(font1);
        wet_union->setAlignment(Qt::AlignCenter);
        btn_mode = new QPushButton(widget);
        btn_mode->setObjectName(QString::fromUtf8("btn_mode"));
        btn_mode->setGeometry(QRect(50, 30, 50, 50));
        btn_mode->setMinimumSize(QSize(50, 50));
        btn_mode->setMaximumSize(QSize(50, 50));
        btn_mode->setStyleSheet(QString::fromUtf8("#btn_mode{\n"
"	\n"
"	background-image: url(:/images/automode_on.png);\n"
"	background-color:transparent;\n"
"}"));
        btn_mode->setFlat(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 0, 0));
        menubar->setMaximumSize(QSize(0, 0));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setEnabled(false);
        statusbar->setMaximumSize(QSize(0, 0));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        btn_disconnect->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\345\260\230\346\255\214\345\243\266\345\256\266\345\205\267\346\216\247\345\210\266\346\250\241\345\235\227\342\200\224\342\200\224\346\264\276\350\222\231\346\250\241\345\235\227", nullptr));
        btn_curtain->setText(QString());
        btn_door->setText(QString());
        btn_airc->setText(QString());
        btn_led->setText(QString());
        btn_disconnect->setText(QString());
        info->setText(QApplication::translate("MainWindow", " \350\277\236\346\216\245\345\244\261\350\264\245\357\274\214\347\202\271\345\207\273\351\207\215\346\226\260\350\277\236\346\216\245 ", nullptr));
        pasc_value->setText(QApplication::translate("MainWindow", "20", nullptr));
        hum_value->setText(QApplication::translate("MainWindow", "15", nullptr));
        tmp_value->setText(QApplication::translate("MainWindow", "30", nullptr));
        lux_value->setText(QApplication::translate("MainWindow", "15", nullptr));
        wet_value->setText(QApplication::translate("MainWindow", "65", nullptr));
        pasc_union->setText(QApplication::translate("MainWindow", "kpa", nullptr));
        hum_union->setText(QApplication::translate("MainWindow", "m", nullptr));
        tmp_union->setText(QApplication::translate("MainWindow", "\342\204\203", nullptr));
        lux_union->setText(QApplication::translate("MainWindow", "lux", nullptr));
        wet_union->setText(QApplication::translate("MainWindow", "%", nullptr));
        btn_mode->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
