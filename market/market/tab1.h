#ifndef TAB1_H
#define TAB1_H

#include <QWidget>
#include "ui_tab1.h"
#include<Qstring>
#include<QSqlQueryModel>
#include<QTableView>
#include<QDebug>
#include<QMessageBox>
#include<QSqlError>
#include "sqlOp.h"
#include"parameter.h"
#include "getUUID.cpp"
#include"message.h"




class Tab1 : public QWidget
{
	Q_OBJECT

public:
	Tab1(QWidget *parent = 0 );
	~Tab1();
	

private:
	Ui::Tab1 ui;

	int m_vUserID;//我
	QString m_vPID;//产品号
	int m_vSID;//卖家
	QSqlQueryModel *model;
	
	Message *m_pMessage;
	
	
	
	//复杂查询的基本查询语句 
	QString initQuery = "select PID ,Pname, Pprice, Pdescription,product.SID,Sname,Scontact from product,student where product.PID not in (select PID from trade_record) and product.SID=student.SID";
	//刷新时查询语句
	QString initQuery2 = initQuery + ";";

private slots:
	
	void getProductInfo(QModelIndex);


	void buyProduct();
	void deleteProduct();
	void message();
	void search();
	void showTable(QString selectQuery);


	void refreshDate();



};

#endif // TAB1_H
