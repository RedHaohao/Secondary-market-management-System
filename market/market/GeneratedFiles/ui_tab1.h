/********************************************************************************
** Form generated from reading UI file 'tab1.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB1_H
#define UI_TAB1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tab1
{
public:
    QTableView *tableView;
    QPushButton *buyButton;
    QLineEdit *searhEdit;
    QPushButton *searchButton;
    QPushButton *deleteButton;
    QComboBox *CLIDBox;
    QComboBox *CIDBox;
    QLabel *label;
    QLabel *label_2;
    QPushButton *messageButton;

    void setupUi(QWidget *Tab1)
    {
        if (Tab1->objectName().isEmpty())
            Tab1->setObjectName(QStringLiteral("Tab1"));
        Tab1->resize(1072, 862);
        tableView = new QTableView(Tab1);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(20, 100, 711, 441));
        buyButton = new QPushButton(Tab1);
        buyButton->setObjectName(QStringLiteral("buyButton"));
        buyButton->setGeometry(QRect(790, 420, 131, 41));
        buyButton->setStyleSheet(QStringLiteral("font: 75 14pt \"Microsoft YaHei UI\";"));
        searhEdit = new QLineEdit(Tab1);
        searhEdit->setObjectName(QStringLiteral("searhEdit"));
        searhEdit->setGeometry(QRect(790, 310, 131, 31));
        searchButton = new QPushButton(Tab1);
        searchButton->setObjectName(QStringLiteral("searchButton"));
        searchButton->setGeometry(QRect(790, 360, 131, 41));
        searchButton->setStyleSheet(QStringLiteral("font: 75 14pt \"Microsoft YaHei UI\";"));
        deleteButton = new QPushButton(Tab1);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setGeometry(QRect(790, 420, 131, 41));
        deleteButton->setStyleSheet(QLatin1String("\n"
"font: 14pt \"Microsoft YaHei UI\";"));
        CLIDBox = new QComboBox(Tab1);
        CLIDBox->setObjectName(QStringLiteral("CLIDBox"));
        CLIDBox->setGeometry(QRect(20, 70, 131, 31));
        QFont font;
        font.setFamily(QStringLiteral("Adobe Arabic"));
        font.setPointSize(10);
        CLIDBox->setFont(font);
        CIDBox = new QComboBox(Tab1);
        CIDBox->setObjectName(QStringLiteral("CIDBox"));
        CIDBox->setGeometry(QRect(180, 70, 131, 31));
        CIDBox->setFont(font);
        label = new QLabel(Tab1);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 111, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Adobe Arabic"));
        font1.setPointSize(12);
        label->setFont(font1);
        label_2 = new QLabel(Tab1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(180, 30, 111, 31));
        label_2->setFont(font1);
        messageButton = new QPushButton(Tab1);
        messageButton->setObjectName(QStringLiteral("messageButton"));
        messageButton->setGeometry(QRect(790, 480, 131, 41));
        messageButton->setStyleSheet(QLatin1String("\n"
"font: 14pt \"Microsoft YaHei UI\";"));

        retranslateUi(Tab1);

        QMetaObject::connectSlotsByName(Tab1);
    } // setupUi

    void retranslateUi(QWidget *Tab1)
    {
        Tab1->setWindowTitle(QApplication::translate("Tab1", "Tab1", 0));
        buyButton->setText(QApplication::translate("Tab1", "\350\264\255\344\271\260", 0));
        searchButton->setText(QApplication::translate("Tab1", "\346\220\234\347\264\242", 0));
        deleteButton->setText(QApplication::translate("Tab1", "\345\210\240\351\231\244", 0));
        label->setText(QApplication::translate("Tab1", "\345\225\206\345\223\201\347\261\273\345\210\253\357\274\232", 0));
        label_2->setText(QApplication::translate("Tab1", "\345\225\206\345\223\201\346\226\260\346\227\247\357\274\232", 0));
        messageButton->setText(QApplication::translate("Tab1", "\347\225\231\350\250\200", 0));
    } // retranslateUi

};

namespace Ui {
    class Tab1: public Ui_Tab1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB1_H
