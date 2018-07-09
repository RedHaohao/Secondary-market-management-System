#pragma execution_character_set("utf-8")
#include "tab3.h"

Tab3::Tab3(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

    m_vSID = QString::number(Parameter::getInstance()->m_vUserID, 10);

	QString str("select PID, Pname, Pprice,Pdescription from product where PID in(select PID from trade_record where trade_record.SID1 = ");
	str.append(m_vSID);
	str.append(")");
	initQuery = str;
	showTable(initQuery);

	connect(ui.purchaseButton, SIGNAL(clicked()), this, SLOT(purchaseRecord()));
	connect(ui.saleButton, SIGNAL(clicked()), this, SLOT(saleRecord()));
	connect(ui.onSaleButton, SIGNAL(clicked()), this, SLOT(onSaleRecord()));
	connect(ui.deleteButton, SIGNAL(clicked()), this, SLOT(deleteProduct()));
	connect(ui.tableView, SIGNAL(clicked(QModelIndex)), this, SLOT(getProductInfo(QModelIndex)));


	showBaseInfo();


}

Tab3::~Tab3()
{

}

void Tab3::getProductInfo(QModelIndex)//获取选中行的PID和SID
{
	int row = ui.tableView->currentIndex().row();
	QModelIndex index = model->index(row, 0);
	m_vPID= model->data(index).toString();
}

void Tab3::deleteProduct()
{
	QString deleteQuery = "delete from product where PID=? and SID= ?";
	QVector<QVariant>bindvalue;
	bindvalue.append(m_vPID);
	bindvalue.append(m_vSID.toInt());
	bool result = SqlOp::Delete_UpdateQuery(deleteQuery, bindvalue);
	if (result)    //如果删除成功
		QMessageBox::warning(this, "提示", "删除成功", QMessageBox::Yes);
	else
		QMessageBox::warning(this, "提示", "删除失败", QMessageBox::Yes);
	showTable(initQuery);
}

void Tab3::showTable(QString selectQuery)
{
	model = new QSqlQueryModel(this);
	model->setQuery(selectQuery, SqlOp::GetDatabase());
	model->setHeaderData(0, Qt::Horizontal, "商品号");
	model->setHeaderData(1, Qt::Horizontal, "商品名");
	model->setHeaderData(2, Qt::Horizontal, "商品价格");
	model->setHeaderData(3, Qt::Horizontal, "商品描述");

	ui.tableView->setModel(model);
	QHeaderView* headerView = ui.tableView->verticalHeader();
	headerView->setHidden(true);
	ui.tableView->horizontalHeader()->setStretchLastSection(true);

}



void Tab3::showBaseInfo()
{
	selectQuery = "select Sname from student where student.SID= ?";
	QVector<QVector<QString>>result;     //用来存放查询得到的产品名称
	QVector<QString>bindValue;
	bindValue.append(m_vSID);
	result = SqlOp::SelectQuery(selectQuery, 1, bindValue);
	ui.SIDEdit->setPlaceholderText(m_vSID);
	ui.SnameEdit->setPlaceholderText(result[0][0]);
	ui.SIDEdit->setEnabled(false);
	ui.SnameEdit->setEnabled(false);
}

void Tab3::purchaseRecord()
{
	selectQuery = QString("select PID, Pname, Pprice ,Pdescription from product where PID in(select PID from trade_record where trade_record.SID1 = '%1')").arg(m_vSID);
	showTable(selectQuery);

}

void Tab3::saleRecord()
{
	selectQuery = QString("select PID, Pname, Pprice,Pdescription from product where PID in(select PID from trade_record where trade_record.SID2 ='%1') ").arg(m_vSID);
	showTable(selectQuery);

}

void Tab3::onSaleRecord()
{
	selectQuery = QString("select PID, Pname, Pprice,Pdescription from product where product.SID='%1' and PID not in(select PID from trade_record where trade_record.SID2 ='%2') ").arg(m_vSID).arg(m_vSID);
	showTable(selectQuery);
}
