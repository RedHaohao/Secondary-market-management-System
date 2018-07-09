#ifndef TAB3_H
#define TAB3_H

#include <QWidget>
#include "ui_tab3.h"
#include "Parameter.h"
#include "sqlOp.h"
#include <QString>
#include "tipdialog.h"
#include <qsqlquerymodel.h>
#include <QMessageBox>
#include<QSqlQueryModel>
#include<QSqlTableModel>
#include<QTableView>


class Tab3 : public QWidget
{
	Q_OBJECT

public:
	Tab3(QWidget *parent = 0);
	~Tab3();

	void showBaseInfo();
	void showTable(QString selectQuery);

private slots:
	void purchaseRecord();
	void saleRecord();
	void onSaleRecord();
	void deleteProduct();
	void getProductInfo(QModelIndex);

private:
	Ui::Tab3 ui;

	QString initQuery = "";
	QSqlQueryModel *model;
	QString selectQuery = "";
	QString m_vSID;
	QString m_vPID;
};

#endif // TAB3_H
