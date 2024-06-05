/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *widget;
    QLineEdit *ip_text;
    QLineEdit *port_text;
    QPushButton *pushButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->setWindowModality(Qt::NonModal);
        Dialog->resize(583, 385);
        Dialog->setMinimumSize(QSize(583, 385));
        Dialog->setMaximumSize(QSize(583, 385));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/pm.png"), QSize(), QIcon::Normal, QIcon::Off);
        Dialog->setWindowIcon(icon);
        Dialog->setModal(false);
        widget = new QWidget(Dialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 583, 385));
        widget->setMinimumSize(QSize(583, 385));
        widget->setMaximumSize(QSize(583, 385));
        widget->setStyleSheet(QString::fromUtf8("QWidget#widget\n"
"{\n"
"	background-image: url(:/images/login.png);\n"
"}"));
        ip_text = new QLineEdit(widget);
        ip_text->setObjectName(QString::fromUtf8("ip_text"));
        ip_text->setGeometry(QRect(220, 140, 150, 30));
        ip_text->setMinimumSize(QSize(150, 30));
        ip_text->setMaximumSize(QSize(150, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        font.setBold(true);
        font.setWeight(75);
        ip_text->setFont(font);
        ip_text->setFocusPolicy(Qt::ClickFocus);
        ip_text->setAutoFillBackground(false);
        ip_text->setStyleSheet(QString::fromUtf8("QLineEdit#ip_text\n"
"{	\n"
"	border:none;\n"
"	background-image: url(:/images/line.png);\n"
"	background-color: transparent;\n"
"\n"
"}"));
        ip_text->setAlignment(Qt::AlignCenter);
        ip_text->setClearButtonEnabled(false);
        port_text = new QLineEdit(widget);
        port_text->setObjectName(QString::fromUtf8("port_text"));
        port_text->setGeometry(QRect(220, 190, 150, 30));
        port_text->setMinimumSize(QSize(150, 30));
        port_text->setMaximumSize(QSize(150, 30));
        port_text->setFont(font);
        port_text->setFocusPolicy(Qt::ClickFocus);
        port_text->setStyleSheet(QString::fromUtf8("QLineEdit#port_text\n"
"{	\n"
"	border:none;\n"
"	background-image: url(:/images/line.png);\n"
"	background-color: transparent;\n"
"\n"
"}"));
        port_text->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(260, 260, 50, 50));
        pushButton->setMinimumSize(QSize(50, 50));
        pushButton->setMaximumSize(QSize(50, 50));
        pushButton->setFocusPolicy(Qt::StrongFocus);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-image:url(:/images/connect.png);\n"
"	background-color:transparent;\n"
"}"));
        pushButton->setAutoDefault(false);
        pushButton->setFlat(true);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "\345\260\230\346\255\214\345\243\266\345\256\266\345\205\267\346\216\247\345\210\266\346\250\241\345\235\227\342\200\224\342\200\224\346\264\276\350\222\231\346\250\241\345\235\227[\347\231\273\345\275\225\347\225\214\351\235\242]", nullptr));
        ip_text->setInputMask(QString());
        ip_text->setText(QApplication::translate("Dialog", "47.98.153.253", nullptr));
        ip_text->setPlaceholderText(QApplication::translate("Dialog", "\350\257\267\350\276\223\345\205\245IP\345\234\260\345\235\200", nullptr));
        port_text->setInputMask(QString());
        port_text->setText(QApplication::translate("Dialog", "11157", nullptr));
        port_text->setPlaceholderText(QApplication::translate("Dialog", "\350\257\267\350\276\223\345\205\245\347\253\257\345\217\243\345\217\267", nullptr));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
