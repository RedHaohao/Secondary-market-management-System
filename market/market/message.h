#ifndef MESSAGE_H
#define MESSAGE_H

#include <QWidget>
#include "ui_message.h"
#include<QDebug>
#include<QMessageBox>
#include "sqlOp.h"
#include"parameter.h"

class Message : public QWidget
{
	Q_OBJECT

public:
	Message(QWidget *parent = 0);
	~Message();
	void showTable(QString selectQuery);

private slots:
	void finish();
private:
	Ui::Message ui;

	QSqlQueryModel *model;
	QString selectQuery = QString("select student.Sname,Mess from message,student where PID='%1' and student.SID=message.SID;").arg(Parameter::getInstance()->m_vPID);

};

#endif // MESSAGE_H
