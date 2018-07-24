/********************************************************************************
** Form generated from reading UI file 'message.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGE_H
#define UI_MESSAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Message
{
public:
    QFrame *frame;
    QTextEdit *messageEdit;
    QLabel *label_2;
    QPushButton *okButton;
    QTableView *tableView;

    void setupUi(QWidget *Message)
    {
        if (Message->objectName().isEmpty())
            Message->setObjectName(QStringLiteral("Message"));
        Message->resize(486, 359);
        frame = new QFrame(Message);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 481, 351));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        messageEdit = new QTextEdit(frame);
        messageEdit->setObjectName(QStringLiteral("messageEdit"));
        messageEdit->setGeometry(QRect(60, 280, 291, 31));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(200, 20, 91, 31));
        QFont font;
        font.setFamily(QStringLiteral("Adobe Arabic"));
        font.setPointSize(12);
        label_2->setFont(font);
        okButton = new QPushButton(frame);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(350, 280, 81, 31));
        tableView = new QTableView(frame);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(60, 70, 371, 181));

        retranslateUi(Message);

        QMetaObject::connectSlotsByName(Message);
    } // setupUi

    void retranslateUi(QWidget *Message)
    {
        Message->setWindowTitle(QApplication::translate("Message", "Message", 0));
        label_2->setText(QApplication::translate("Message", "\347\225\231\350\250\200\346\235\277", 0));
        okButton->setText(QApplication::translate("Message", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class Message: public Ui_Message {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGE_H
