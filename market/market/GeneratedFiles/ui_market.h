/********************************************************************************
** Form generated from reading UI file 'market.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MARKET_H
#define UI_MARKET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_marketClass
{
public:
    QFrame *frame;
    QLabel *passWordLabel;
    QLineEdit *passWordEdit;
    QLineEdit *userIDEdit;
    QLabel *userNameLabel;
    QPushButton *loginBtn;
    QPushButton *narrowBtn;
    QPushButton *closeBtn;
    QCheckBox *stuBox;
    QCheckBox *adminBox;
    QPushButton *registerButton;

    void setupUi(QWidget *marketClass)
    {
        if (marketClass->objectName().isEmpty())
            marketClass->setObjectName(QStringLiteral("marketClass"));
        marketClass->resize(450, 338);
        frame = new QFrame(marketClass);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 450, 338));
        frame->setStyleSheet(QLatin1String("#frame{\n"
"border-image: url(:/login/image/login/background_a.png);\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        passWordLabel = new QLabel(frame);
        passWordLabel->setObjectName(QStringLiteral("passWordLabel"));
        passWordLabel->setGeometry(QRect(90, 168, 71, 31));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(9);
        passWordLabel->setFont(font);
        passWordLabel->setStyleSheet(QStringLiteral("border-image: url(:/login/image/login/password.png);"));
        passWordEdit = new QLineEdit(frame);
        passWordEdit->setObjectName(QStringLiteral("passWordEdit"));
        passWordEdit->setGeometry(QRect(172, 169, 164, 28));
        passWordEdit->setStyleSheet(QString::fromUtf8("border-image: url(:/login/image/login/input_box_a.png);\n"
"font: 8pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        userIDEdit = new QLineEdit(frame);
        userIDEdit->setObjectName(QStringLiteral("userIDEdit"));
        userIDEdit->setGeometry(QRect(172, 123, 164, 28));
        userIDEdit->setStyleSheet(QString::fromUtf8("border-image: url(:/login/image/login/input_box_a.png);\n"
"font: 8pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        userNameLabel = new QLabel(frame);
        userNameLabel->setObjectName(QStringLiteral("userNameLabel"));
        userNameLabel->setGeometry(QRect(90, 130, 61, 20));
        userNameLabel->setStyleSheet(QStringLiteral("border-image: url(:/login/image/login/username.png);"));
        loginBtn = new QPushButton(frame);
        loginBtn->setObjectName(QStringLiteral("loginBtn"));
        loginBtn->setGeometry(QRect(160, 220, 133, 34));
        loginBtn->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/login/image/login/land.png);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"border-image: url(:/login/image/login/landing.png);\n"
"}"));
        narrowBtn = new QPushButton(frame);
        narrowBtn->setObjectName(QStringLiteral("narrowBtn"));
        narrowBtn->setGeometry(QRect(396, 0, 24, 16));
        narrowBtn->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/login/image/login/j.png);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"border-image: url(:/login/image/login/j_a.png);\n"
"}\n"
""));
        closeBtn = new QPushButton(frame);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));
        closeBtn->setGeometry(QRect(420, 0, 24, 16));
        closeBtn->setStyleSheet(QLatin1String("QPushButton{\n"
"border-image: url(:/login/image/login/x.png);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"border-image: url(:/login/image/login/x_a.png);\n"
"}"));
        stuBox = new QCheckBox(frame);
        stuBox->setObjectName(QStringLiteral("stuBox"));
        stuBox->setGeometry(QRect(90, 80, 105, 22));
        adminBox = new QCheckBox(frame);
        adminBox->setObjectName(QStringLiteral("adminBox"));
        adminBox->setGeometry(QRect(220, 80, 121, 22));
        registerButton = new QPushButton(frame);
        registerButton->setObjectName(QStringLiteral("registerButton"));
        registerButton->setGeometry(QRect(332, 290, 101, 34));

        retranslateUi(marketClass);

        QMetaObject::connectSlotsByName(marketClass);
    } // setupUi

    void retranslateUi(QWidget *marketClass)
    {
        marketClass->setWindowTitle(QApplication::translate("marketClass", "market", 0));
        passWordLabel->setText(QApplication::translate("marketClass", "\345\257\206     \347\240\201\357\274\232", 0));
        passWordEdit->setText(QString());
        userNameLabel->setText(QApplication::translate("marketClass", "\350\264\246  \345\217\267\357\274\232", 0));
        loginBtn->setText(QApplication::translate("marketClass", "\347\231\273\345\275\225", 0));
        narrowBtn->setText(QApplication::translate("marketClass", "-", 0));
        closeBtn->setText(QApplication::translate("marketClass", "X", 0));
        stuBox->setText(QApplication::translate("marketClass", "\347\224\250\346\210\267\347\231\273\345\275\225", 0));
        adminBox->setText(QApplication::translate("marketClass", "\347\256\241\347\220\206\345\221\230\347\231\273\345\275\225", 0));
        registerButton->setText(QApplication::translate("marketClass", "\347\224\250\346\210\267\346\263\250\345\206\214", 0));
    } // retranslateUi

};

namespace Ui {
    class marketClass: public Ui_marketClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MARKET_H
