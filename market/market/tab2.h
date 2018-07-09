#ifndef TAB2_H
#define TAB2_H

#include <QWidget>
#include "ui_tab2.h"
#include "tipdialog.h"
#include<QString>
#include<QMessageBox>
#include<qDebug>
#include "Parameter.h"
#include "sqlOp.h"

class Tab2 : public QWidget
{
	Q_OBJECT

public:
	Tab2(QWidget *parent = 0);
	~Tab2();


	
	int isDigitStr(QString str);
	

private slots:
	void checkPprice();
	void upload();


private:
	Ui::Tab2 ui;

	//int m_vCID = 0;
	//QString m_vPname = "";
	//float m_vPprice = 0;
	//QString m_vPdes = "";
	
};

#endif // TAB2_H
