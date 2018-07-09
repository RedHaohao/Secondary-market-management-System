#ifndef MARKET_H
#define MARKET_H

#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include "ui_market.h"
#include <QObject.h>
#include <QSqlQuery>
#include <qmessagebox.h>
#include "homepage.h"
#include <QDesktopWidget>
#include <qdatetime.h>
#include "tipdialog.h"
#include"Parameter.h"
#include<QKeyEvent>
#include<qDebug>
#include <QSqlDatabase>
#include <QString>
#include <QtSql>  
#include "sqlOp.h"
#include "register.h"

class market : public QWidget
{
	Q_OBJECT

public:
	market(QWidget *parent = 0);
	~market();
	void keyPressEvent(QKeyEvent*);          //按键事件
	void closeEvent();
     QString GetUserId(){ return m_vUserID ;}
	      

private:
	Ui::marketClass ui;
	QString m_vUserID;
	 QString m_vUserPWD;			    //密码变量
	 Register *m_pRegister;

	public slots:
	void loginBtnSlot();
	void registerBtnSlot();
	void narrowBtnSlot();
	void closeBtnSlot();
};

#endif // MARKET_H
