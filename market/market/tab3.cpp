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

void Tab3::getProductInfo(QModelIndex)//��ȡѡ���е�PID��SID
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
	if (result)    //���ɾ���ɹ�
		QMessageBox::warning(this, "��ʾ", "ɾ���ɹ�", QMessageBox::Yes);
	else
		QMessageBox::warning(this, "��ʾ", "ɾ��ʧ��", QMessageBox::Yes);
	showTable(initQuery);
}

void Tab3::showTable(QString selectQuery)
{
	model = new QSqlQueryModel(this);
	model->setQuery(selectQuery, SqlOp::GetDatabase());
	model->setHeaderData(0, Qt::Horizontal, "��Ʒ��");
	model->setHeaderData(1, Qt::Horizontal, "��Ʒ��");
	model->setHeaderData(2, Qt::Horizontal, "��Ʒ�۸�");
	model->setHeaderData(3, Qt::Horizontal, "��Ʒ����");

	ui.tableView->setModel(model);
	QHeaderView* headerView = ui.tableView->verticalHeader();
	headerView->setHidden(true);
	ui.tableView->horizontalHeader()->setStretchLastSection(true);

}



void Tab3::showBaseInfo()
{
	selectQuery = "select Sname from student where student.SID= ?";
	QVector<QVector<QString>>result;     //������Ų�ѯ�õ��Ĳ�Ʒ����
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
