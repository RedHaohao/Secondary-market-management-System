/********************************************************************************
** Form generated from reading UI file 'tipdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIPDIALOG_H
#define UI_TIPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tipdialog
{
public:
    QLabel *textlable;
    QFrame *frame;
    QPushButton *CloseButton;
    QPushButton *OKButton;
    QLabel *titilelabel;
    QPushButton *CancelButton;

    void setupUi(QWidget *tipdialog)
    {
        if (tipdialog->objectName().isEmpty())
            tipdialog->setObjectName(QStringLiteral("tipdialog"));
        tipdialog->resize(334, 211);
        tipdialog->setStyleSheet(QLatin1String("#frame { \n"
"	border-image: url(:/tipdialog/image/tipdialog/cd.png);\n"
"	}\n"
"#frame * { \n"
"border-image:url(); \n"
"}\n"
""));
        textlable = new QLabel(tipdialog);
        textlable->setObjectName(QStringLiteral("textlable"));
        textlable->setGeometry(QRect(45, 55, 244, 70));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei UI"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        textlable->setFont(font);
        textlable->setStyleSheet(QLatin1String("font: 12pt \"Microsoft YaHei UI\";\n"
"font:bold;"));
        textlable->setAlignment(Qt::AlignCenter);
        frame = new QFrame(tipdialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 382, 214));
        frame->setStyleSheet(QStringLiteral(""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        CloseButton = new QPushButton(frame);
        CloseButton->setObjectName(QStringLiteral("CloseButton"));
        CloseButton->setGeometry(QRect(302, 14, 15, 12));
        CloseButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-image: url(:/tipdialog/image/tipdialog/no2.png);\n"
"}\n"
"QPushButton:hover{\n"
"	border-image: url(:/tipdialog/image/tipdialog/no1.png);\n"
"}\n"
"\n"
"/*QPushButton:pressed{\n"
"	border-image: url(:/\351\200\232\351\201\223\351\200\211\346\213\251/images/\345\201\234\346\255\242\346\243\200\346\265\213\345\257\271\350\257\235\346\241\206/btn_close_down.png);\n"
"}*/\n"
""));
        OKButton = new QPushButton(frame);
        OKButton->setObjectName(QStringLiteral("OKButton"));
        OKButton->setGeometry(QRect(54, 149, 78, 26));
        OKButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	\n"
"	border-image: url(:/tipdialog/image/tipdialog/yes_a.png);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"   \n"
"	border-image: url(:/tipdialog/image/tipdialog/yes1.png);\n"
"}\n"
"\n"
"/*QPushButton:pressed{\n"
"	border-image: url(:/\351\200\232\351\201\223\351\200\211\346\213\251/images/\345\201\234\346\255\242\346\243\200\346\265\213\345\257\271\350\257\235\346\241\206/btn_sure_down.png);\n"
"}*/\n"
""));
        titilelabel = new QLabel(frame);
        titilelabel->setObjectName(QStringLiteral("titilelabel"));
        titilelabel->setGeometry(QRect(125, 13, 84, 15));
        titilelabel->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font:bold;"));
        titilelabel->setAlignment(Qt::AlignCenter);
        CancelButton = new QPushButton(frame);
        CancelButton->setObjectName(QStringLiteral("CancelButton"));
        CancelButton->setGeometry(QRect(186, 149, 78, 26));
        CancelButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	\n"
"	\n"
"	border-image: url(:/tipdialog/image/tipdialog/cancel_a.png);\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"   \n"
"	border-image: url(:/tipdialog/image/tipdialog/cancel.png);\n"
"}\n"
""));
        frame->raise();
        textlable->raise();
        QWidget::setTabOrder(OKButton, CancelButton);
        QWidget::setTabOrder(CancelButton, CloseButton);

        retranslateUi(tipdialog);

        QMetaObject::connectSlotsByName(tipdialog);
    } // setupUi

    void retranslateUi(QWidget *tipdialog)
    {
        tipdialog->setWindowTitle(QApplication::translate("tipdialog", "tipdialog", 0));
        textlable->setText(QString());
        CloseButton->setText(QString());
        OKButton->setText(QString());
        titilelabel->setText(QString());
        CancelButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class tipdialog: public Ui_tipdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIPDIALOG_H
