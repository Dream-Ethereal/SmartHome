/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_settings
{
public:
    QWidget *widget;
    QPushButton *btn_confirm;
    QLabel *tmp_value;
    QLabel *wet_value;
    QLabel *lux_value;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *tmp_union;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_up1;
    QPushButton *btn_down1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *wet_union;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_up2;
    QPushButton *btn_down2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lux_union;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn_up3;
    QPushButton *btn_down3;

    void setupUi(QDialog *settings)
    {
        if (settings->objectName().isEmpty())
            settings->setObjectName(QString::fromUtf8("settings"));
        settings->resize(582, 385);
        settings->setMinimumSize(QSize(582, 385));
        settings->setMaximumSize(QSize(582, 385));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/pm.png"), QSize(), QIcon::Normal, QIcon::Off);
        settings->setWindowIcon(icon);
        settings->setStyleSheet(QString::fromUtf8(""));
        widget = new QWidget(settings);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 582, 385));
        widget->setMinimumSize(QSize(582, 385));
        widget->setMaximumSize(QSize(582, 385));
        widget->setStyleSheet(QString::fromUtf8("QWidget#widget{\n"
"	background-image: url(:/images/setbg.png);\n"
"}"));
        btn_confirm = new QPushButton(widget);
        btn_confirm->setObjectName(QString::fromUtf8("btn_confirm"));
        btn_confirm->setGeometry(QRect(460, 140, 103, 103));
        btn_confirm->setStyleSheet(QString::fromUtf8("#btn_confirm{\n"
"	\n"
"	background-image: url(:/images/confirm.png);\n"
"	background-color:transparent;\n"
"}"));
        tmp_value = new QLabel(widget);
        tmp_value->setObjectName(QString::fromUtf8("tmp_value"));
        tmp_value->setGeometry(QRect(123, 103, 120, 30));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tmp_value->sizePolicy().hasHeightForWidth());
        tmp_value->setSizePolicy(sizePolicy);
        tmp_value->setMinimumSize(QSize(120, 30));
        tmp_value->setMaximumSize(QSize(120, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        tmp_value->setFont(font);
        tmp_value->setAlignment(Qt::AlignCenter);
        wet_value = new QLabel(widget);
        wet_value->setObjectName(QString::fromUtf8("wet_value"));
        wet_value->setGeometry(QRect(123, 174, 120, 30));
        sizePolicy.setHeightForWidth(wet_value->sizePolicy().hasHeightForWidth());
        wet_value->setSizePolicy(sizePolicy);
        wet_value->setMinimumSize(QSize(120, 30));
        wet_value->setMaximumSize(QSize(120, 30));
        wet_value->setFont(font);
        wet_value->setAlignment(Qt::AlignCenter);
        lux_value = new QLabel(widget);
        lux_value->setObjectName(QString::fromUtf8("lux_value"));
        lux_value->setGeometry(QRect(123, 245, 120, 30));
        sizePolicy.setHeightForWidth(lux_value->sizePolicy().hasHeightForWidth());
        lux_value->setSizePolicy(sizePolicy);
        lux_value->setMinimumSize(QSize(120, 30));
        lux_value->setMaximumSize(QSize(120, 30));
        lux_value->setFont(font);
        lux_value->setAlignment(Qt::AlignCenter);
        widget1 = new QWidget(widget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(260, 90, 171, 201));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tmp_union = new QLabel(widget1);
        tmp_union->setObjectName(QString::fromUtf8("tmp_union"));
        sizePolicy.setHeightForWidth(tmp_union->sizePolicy().hasHeightForWidth());
        tmp_union->setSizePolicy(sizePolicy);
        tmp_union->setMinimumSize(QSize(35, 40));
        tmp_union->setMaximumSize(QSize(35, 40));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(20);
        tmp_union->setFont(font1);
        tmp_union->setStyleSheet(QString::fromUtf8("#tmp_union{\n"
"	background-color: transparent;\n"
"}"));

        horizontalLayout->addWidget(tmp_union);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_up1 = new QPushButton(widget1);
        btn_up1->setObjectName(QString::fromUtf8("btn_up1"));
        btn_up1->setMinimumSize(QSize(35, 35));
        btn_up1->setMaximumSize(QSize(35, 35));
        btn_up1->setStyleSheet(QString::fromUtf8("#btn_up1{\n"
"	\n"
"	background-image: url(:/images/anniu_add_up.png);\n"
"	background-color:transparent;\n"
"}\n"
"#btn_up1::pressed{\n"
"	\n"
"	background-image: url(:/images/anniu_add_down.png);\n"
"	background-color:transparent;\n"
"}\n"
""));

        horizontalLayout->addWidget(btn_up1);

        btn_down1 = new QPushButton(widget1);
        btn_down1->setObjectName(QString::fromUtf8("btn_down1"));
        btn_down1->setMinimumSize(QSize(35, 35));
        btn_down1->setMaximumSize(QSize(35, 35));
        btn_down1->setStyleSheet(QString::fromUtf8("#btn_down1{\n"
"	\n"
"	background-image: url(:/images/anniu_div_up.png);\n"
"	background-color:transparent;\n"
"}\n"
"#btn_down1::pressed{\n"
"	\n"
"	background-image: url(:/images/anniu_div_down.png);\n"
"	background-color:transparent;\n"
"}"));

        horizontalLayout->addWidget(btn_down1);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        wet_union = new QLabel(widget1);
        wet_union->setObjectName(QString::fromUtf8("wet_union"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(35);
        sizePolicy1.setVerticalStretch(40);
        sizePolicy1.setHeightForWidth(wet_union->sizePolicy().hasHeightForWidth());
        wet_union->setSizePolicy(sizePolicy1);
        wet_union->setMinimumSize(QSize(35, 40));
        wet_union->setFont(font1);

        horizontalLayout_2->addWidget(wet_union);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        btn_up2 = new QPushButton(widget1);
        btn_up2->setObjectName(QString::fromUtf8("btn_up2"));
        btn_up2->setMinimumSize(QSize(35, 35));
        btn_up2->setMaximumSize(QSize(35, 35));
        btn_up2->setStyleSheet(QString::fromUtf8("#btn_up2{\n"
"	\n"
"	background-image: url(:/images/anniu_add_up.png);\n"
"	background-color:transparent;\n"
"}\n"
"#btn_up2::pressed{\n"
"	\n"
"	background-image: url(:/images/anniu_add_down.png);\n"
"	background-color:transparent;\n"
"}"));

        horizontalLayout_2->addWidget(btn_up2);

        btn_down2 = new QPushButton(widget1);
        btn_down2->setObjectName(QString::fromUtf8("btn_down2"));
        btn_down2->setMinimumSize(QSize(35, 35));
        btn_down2->setMaximumSize(QSize(35, 35));
        btn_down2->setStyleSheet(QString::fromUtf8("#btn_down2{\n"
"	\n"
"	background-image: url(:/images/anniu_div_up.png);\n"
"	background-color:transparent;\n"
"}\n"
"#btn_down2::pressed{\n"
"	\n"
"	background-image: url(:/images/anniu_div_down.png);\n"
"	background-color:transparent;\n"
"}"));

        horizontalLayout_2->addWidget(btn_down2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lux_union = new QLabel(widget1);
        lux_union->setObjectName(QString::fromUtf8("lux_union"));
        sizePolicy.setHeightForWidth(lux_union->sizePolicy().hasHeightForWidth());
        lux_union->setSizePolicy(sizePolicy);
        lux_union->setMinimumSize(QSize(50, 40));
        lux_union->setMaximumSize(QSize(50, 40));
        lux_union->setFont(font1);
        lux_union->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(lux_union);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        btn_up3 = new QPushButton(widget1);
        btn_up3->setObjectName(QString::fromUtf8("btn_up3"));
        btn_up3->setMinimumSize(QSize(35, 35));
        btn_up3->setMaximumSize(QSize(35, 35));
        btn_up3->setStyleSheet(QString::fromUtf8("#btn_up3{\n"
"	\n"
"	background-image: url(:/images/anniu_add_up.png);\n"
"	background-color:transparent;\n"
"}\n"
"#btn_up3::pressed{\n"
"	\n"
"	background-image: url(:/images/anniu_add_down.png);\n"
"	background-color:transparent;\n"
"}"));

        horizontalLayout_3->addWidget(btn_up3);

        btn_down3 = new QPushButton(widget1);
        btn_down3->setObjectName(QString::fromUtf8("btn_down3"));
        btn_down3->setMinimumSize(QSize(35, 35));
        btn_down3->setMaximumSize(QSize(35, 35));
        btn_down3->setStyleSheet(QString::fromUtf8("#btn_down3{\n"
"	\n"
"	background-image: url(:/images/anniu_div_up.png);\n"
"	background-color:transparent;\n"
"}\n"
"#btn_down3::pressed{\n"
"	\n"
"	background-image: url(:/images/anniu_div_down.png);\n"
"	background-color:transparent;\n"
"}"));

        horizontalLayout_3->addWidget(btn_down3);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(settings);

        QMetaObject::connectSlotsByName(settings);
    } // setupUi

    void retranslateUi(QDialog *settings)
    {
        settings->setWindowTitle(QApplication::translate("settings", "\345\260\230\344\270\226\344\270\203\346\211\247\346\224\277", nullptr));
        btn_confirm->setText(QString());
        tmp_value->setText(QApplication::translate("settings", "10", nullptr));
        wet_value->setText(QApplication::translate("settings", "30", nullptr));
        lux_value->setText(QApplication::translate("settings", "23", nullptr));
        tmp_union->setText(QApplication::translate("settings", "\342\204\203", nullptr));
        btn_up1->setText(QString());
        btn_down1->setText(QString());
        wet_union->setText(QApplication::translate("settings", "%", nullptr));
        btn_up2->setText(QString());
        btn_down2->setText(QString());
        lux_union->setText(QApplication::translate("settings", "lux", nullptr));
        btn_up3->setText(QString());
        btn_down3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class settings: public Ui_settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
