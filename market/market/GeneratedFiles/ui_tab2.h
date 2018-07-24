/********************************************************************************
** Form generated from reading UI file 'tab2.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB2_H
#define UI_TAB2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tab2
{
public:
    QLabel *label_2;
    QLineEdit *PnameEdit;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_1;
    QPushButton *uploadButton;
    QComboBox *CLIDBox;
    QTextEdit *PdesEdit;
    QComboBox *CIDBox;
    QLabel *label_6;
    QLabel *label_4;
    QLineEdit *PpriceEdit;

    void setupUi(QWidget *Tab2)
    {
        if (Tab2->objectName().isEmpty())
            Tab2->setObjectName(QStringLiteral("Tab2"));
        Tab2->resize(1024, 699);
        label_2 = new QLabel(Tab2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(180, 214, 81, 21));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(12);
        label_2->setFont(font);
        PnameEdit = new QLineEdit(Tab2);
        PnameEdit->setObjectName(QStringLiteral("PnameEdit"));
        PnameEdit->setGeometry(QRect(250, 260, 181, 31));
        label_3 = new QLabel(Tab2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(180, 267, 81, 21));
        label_3->setFont(font);
        label_5 = new QLabel(Tab2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(180, 310, 91, 31));
        label_5->setFont(font);
        label_1 = new QLabel(Tab2);
        label_1->setObjectName(QStringLiteral("label_1"));
        label_1->setGeometry(QRect(180, 100, 151, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("Agency FB"));
        font1.setPointSize(14);
        label_1->setFont(font1);
        uploadButton = new QPushButton(Tab2);
        uploadButton->setObjectName(QStringLiteral("uploadButton"));
        uploadButton->setGeometry(QRect(690, 420, 101, 41));
        uploadButton->setFont(font);
        CLIDBox = new QComboBox(Tab2);
        CLIDBox->setObjectName(QStringLiteral("CLIDBox"));
        CLIDBox->setGeometry(QRect(250, 210, 181, 31));
        PdesEdit = new QTextEdit(Tab2);
        PdesEdit->setObjectName(QStringLiteral("PdesEdit"));
        PdesEdit->setGeometry(QRect(250, 310, 401, 151));
        CIDBox = new QComboBox(Tab2);
        CIDBox->setObjectName(QStringLiteral("CIDBox"));
        CIDBox->setGeometry(QRect(560, 210, 181, 31));
        label_6 = new QLabel(Tab2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(490, 214, 81, 21));
        label_6->setFont(font);
        label_4 = new QLabel(Tab2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(490, 260, 91, 31));
        label_4->setFont(font);
        PpriceEdit = new QLineEdit(Tab2);
        PpriceEdit->setObjectName(QStringLiteral("PpriceEdit"));
        PpriceEdit->setGeometry(QRect(560, 260, 181, 31));

        retranslateUi(Tab2);

        QMetaObject::connectSlotsByName(Tab2);
    } // setupUi

    void retranslateUi(QWidget *Tab2)
    {
        Tab2->setWindowTitle(QApplication::translate("Tab2", "Tab2", 0));
        label_2->setText(QApplication::translate("Tab2", "\345\210\206\347\261\273\357\274\232", 0));
        label_3->setText(QApplication::translate("Tab2", "\345\220\215\347\247\260\357\274\232", 0));
        label_5->setText(QApplication::translate("Tab2", "\346\217\217\350\277\260\357\274\232", 0));
        label_1->setText(QApplication::translate("Tab2", "\345\225\206\345\223\201\344\277\241\346\201\257", 0));
        uploadButton->setText(QApplication::translate("Tab2", "\344\270\212\344\274\240", 0));
        PdesEdit->setHtml(QApplication::translate("Tab2", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        label_6->setText(QApplication::translate("Tab2", "\346\226\260\346\227\247\357\274\232", 0));
        label_4->setText(QApplication::translate("Tab2", "\344\273\267\346\240\274\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class Tab2: public Ui_Tab2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB2_H
