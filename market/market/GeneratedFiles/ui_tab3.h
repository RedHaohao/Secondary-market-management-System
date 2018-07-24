/********************************************************************************
** Form generated from reading UI file 'tab3.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB3_H
#define UI_TAB3_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tab3
{
public:
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *SIDEdit;
    QLineEdit *SnameEdit;
    QPushButton *purchaseButton;
    QPushButton *saleButton;
    QPushButton *onSaleButton;
    QTableView *tableView;
    QPushButton *deleteButton;

    void setupUi(QWidget *Tab3)
    {
        if (Tab3->objectName().isEmpty())
            Tab3->setObjectName(QStringLiteral("Tab3"));
        Tab3->resize(1046, 752);
        label_4 = new QLabel(Tab3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 50, 71, 41));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(12);
        label_4->setFont(font);
        label_5 = new QLabel(Tab3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(240, 50, 91, 31));
        label_5->setFont(font);
        SIDEdit = new QLineEdit(Tab3);
        SIDEdit->setObjectName(QStringLiteral("SIDEdit"));
        SIDEdit->setGeometry(QRect(90, 50, 121, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Bahnschrift"));
        font1.setPointSize(12);
        font1.setItalic(false);
        SIDEdit->setFont(font1);
        SnameEdit = new QLineEdit(Tab3);
        SnameEdit->setObjectName(QStringLiteral("SnameEdit"));
        SnameEdit->setGeometry(QRect(300, 50, 141, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Bahnschrift"));
        font2.setPointSize(12);
        SnameEdit->setFont(font2);
        purchaseButton = new QPushButton(Tab3);
        purchaseButton->setObjectName(QStringLiteral("purchaseButton"));
        purchaseButton->setGeometry(QRect(40, 130, 112, 34));
        saleButton = new QPushButton(Tab3);
        saleButton->setObjectName(QStringLiteral("saleButton"));
        saleButton->setGeometry(QRect(180, 130, 112, 34));
        onSaleButton = new QPushButton(Tab3);
        onSaleButton->setObjectName(QStringLiteral("onSaleButton"));
        onSaleButton->setGeometry(QRect(320, 130, 112, 34));
        tableView = new QTableView(Tab3);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(40, 180, 861, 371));
        deleteButton = new QPushButton(Tab3);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setGeometry(QRect(620, 130, 112, 34));

        retranslateUi(Tab3);

        QMetaObject::connectSlotsByName(Tab3);
    } // setupUi

    void retranslateUi(QWidget *Tab3)
    {
        Tab3->setWindowTitle(QApplication::translate("Tab3", "Tab3", 0));
        label_4->setText(QApplication::translate("Tab3", "\345\255\246\345\217\267\357\274\232", 0));
        label_5->setText(QApplication::translate("Tab3", "\345\247\223\345\220\215\357\274\232", 0));
        purchaseButton->setText(QApplication::translate("Tab3", "\350\264\255\344\271\260\350\256\260\345\275\225", 0));
        saleButton->setText(QApplication::translate("Tab3", "\345\207\272\345\224\256\350\256\260\345\275\225", 0));
        onSaleButton->setText(QApplication::translate("Tab3", "\345\234\250\345\224\256\350\256\260\345\275\225", 0));
        deleteButton->setText(QApplication::translate("Tab3", "\345\210\240\351\231\244\345\234\250\345\224\256\345\225\206\345\223\201", 0));
    } // retranslateUi

};

namespace Ui {
    class Tab3: public Ui_Tab3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB3_H
