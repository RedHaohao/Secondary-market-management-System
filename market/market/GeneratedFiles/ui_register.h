/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *IDEdit;
    QLineEdit *nameEdit;
    QLineEdit *contactEdit;
    QPushButton *registerButton;
    QPushButton *returnButton;
    QComboBox *sexBox;
    QLineEdit *passwordEdit;
    QLabel *label_6;

    void setupUi(QWidget *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QStringLiteral("Register"));
        Register->resize(448, 338);
        label = new QLabel(Register);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(180, 60, 81, 21));
        label_2 = new QLabel(Register);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(110, 100, 81, 18));
        label_3 = new QLabel(Register);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(110, 130, 81, 18));
        label_4 = new QLabel(Register);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(110, 190, 81, 18));
        label_5 = new QLabel(Register);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(110, 160, 81, 18));
        IDEdit = new QLineEdit(Register);
        IDEdit->setObjectName(QStringLiteral("IDEdit"));
        IDEdit->setGeometry(QRect(200, 100, 113, 25));
        nameEdit = new QLineEdit(Register);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));
        nameEdit->setGeometry(QRect(200, 130, 113, 25));
        contactEdit = new QLineEdit(Register);
        contactEdit->setObjectName(QStringLiteral("contactEdit"));
        contactEdit->setGeometry(QRect(200, 190, 113, 25));
        registerButton = new QPushButton(Register);
        registerButton->setObjectName(QStringLiteral("registerButton"));
        registerButton->setGeometry(QRect(170, 260, 112, 34));
        returnButton = new QPushButton(Register);
        returnButton->setObjectName(QStringLiteral("returnButton"));
        returnButton->setGeometry(QRect(370, 10, 71, 34));
        sexBox = new QComboBox(Register);
        sexBox->setObjectName(QStringLiteral("sexBox"));
        sexBox->setGeometry(QRect(200, 160, 113, 25));
        passwordEdit = new QLineEdit(Register);
        passwordEdit->setObjectName(QStringLiteral("passwordEdit"));
        passwordEdit->setGeometry(QRect(200, 220, 113, 25));
        label_6 = new QLabel(Register);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(110, 220, 81, 18));

        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QWidget *Register)
    {
        Register->setWindowTitle(QApplication::translate("Register", "Register", 0));
        label->setText(QApplication::translate("Register", "\347\224\250\346\210\267\346\263\250\345\206\214", 0));
        label_2->setText(QApplication::translate("Register", "\345\255\246  \345\217\267", 0));
        label_3->setText(QApplication::translate("Register", "\347\224\250\346\210\267\345\220\215", 0));
        label_4->setText(QApplication::translate("Register", "\350\201\224\347\263\273\346\226\271\345\274\217", 0));
        label_5->setText(QApplication::translate("Register", "\346\200\247  \345\210\253", 0));
        registerButton->setText(QApplication::translate("Register", "\346\263\250\345\206\214", 0));
        returnButton->setText(QApplication::translate("Register", "\350\277\224\345\233\236", 0));
        label_6->setText(QApplication::translate("Register", "\345\257\206  \347\240\201", 0));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
