#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>
#include "ui_register.h"
#include <QtWidgets/QApplication>
#include <QDesktopWidget>
#include "tipdialog.h"
#include "sqlOp.h"

class Register : public QWidget
{
	Q_OBJECT

public:
	Register(QWidget *parent = 0);
	~Register();
	int isDigital(QString);


private:
	Ui::Register ui;

private slots:
	void returnBtn();
	void registerBtn();
	void checkContactEditinfo();
	void checkIDEditinfo();

	


};

#endif // REGISTER_H
