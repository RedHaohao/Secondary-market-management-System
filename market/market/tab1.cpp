#pragma execution_character_set("utf-8")
#include "tab1.h"

//Tab1(QString UserID = "", QWidget *parent = 0);
Tab1::Tab1(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	
	//管理员界面与用户界面区别：管理员界面有删除按钮,而没有购买
	if (Parameter::getInstance()->userFlag == 0)//用户界面
		ui.deleteButton->setVisible(false);
	else//管理员界面
	{ 
		ui.buyButton->setVisible(false);
		ui.messageButton->setVisible(false);
	}
		
	
	m_vUserID = Parameter::getInstance()->m_vUserID;

	//初始化

	showTable(initQuery2);

	ui.searhEdit->setPlaceholderText("请输入商品名");

	ui.CLIDBox->addItem(tr("所有"));
	ui.CLIDBox->addItem(tr("书籍"));
	ui.CLIDBox->addItem(tr("家具"));
	ui.CLIDBox->addItem(tr("服饰"));
	ui.CLIDBox->addItem(tr("零食"));
	ui.CLIDBox->addItem(tr("化妆品"));
	ui.CLIDBox->addItem(tr("电子设备"));
	ui.CLIDBox->addItem(tr("其他"));

	ui.CIDBox->addItem(tr("所有"));
	ui.CIDBox->addItem(tr("全新"));
	ui.CIDBox->addItem(tr("九成新"));
	ui.CIDBox->addItem(tr("八成新"));
	ui.CIDBox->addItem(tr("七成新"));
	ui.CIDBox->addItem(tr("六成新"));
	ui.CIDBox->addItem(tr("五成新"));

	connect(ui.tableView, SIGNAL(clicked(QModelIndex)), this, SLOT(getProductInfo(QModelIndex)));
	connect(ui.buyButton, SIGNAL(clicked()), this, SLOT(buyProduct()));
	connect(ui.searchButton, SIGNAL(clicked()), this, SLOT(search()));
	connect(ui.CLIDBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(refreshDate()));
	connect(ui.CIDBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(refreshDate()));
	connect(ui.deleteButton, SIGNAL(clicked()), this, SLOT(deleteProduct()));
	connect(ui.messageButton, SIGNAL(clicked()), this, SLOT(message()));

}

Tab1::~Tab1()
{

}

void Tab1::message()
{
	m_pMessage = new Message;
	m_pMessage->show();

	
	
	showTable(initQuery2);
}

void Tab1::refreshDate()
{	
	QString selectQuery = "";
	
	int m_vCLID = 0;
	QString s1 = ui.CLIDBox->currentText();
	
	int m_vCID = 0;
	QString s2 = ui.CIDBox->currentText();

	if (s1 == "书籍")
		m_vCLID = 0;
	else if (s1 == "家具")
		m_vCLID = 1;
	else if (s1 == "服饰")
		m_vCLID = 2;
	else if (s1 == "零食")
		m_vCLID = 3;
	else if (s1 == "化妆品")
		m_vCLID = 4;
	else if (s1 == "电子设备")
		m_vCLID = 5;
	else if (s1 == "其他")
		m_vCLID = 6;


	if (s2 == "全新")
		m_vCID = 10;
	else if (s2 == "九成新")
		m_vCID = 9;
	else if (s2 == "八成新")
		m_vCID = 8;
	else if (s2 == "七成新")
		m_vCID = 7;
	else if (s2 == "六成新")
		m_vCID = 6;
	else if (s2 == "五成新")
		m_vCID = 5;
	
	if (s1 == "所有"&&s2 == "所有")
		selectQuery = initQuery2;
	else if (s1 == "所有"&&s2 != "所有")
		selectQuery =QString(initQuery+" and CID = '%1';").arg(m_vCID);
	else if (s1 != "所有"&&s2 == "所有")
		selectQuery = QString(initQuery + " and CLID = '%1' ;").arg(m_vCLID);
	else
		selectQuery = QString(initQuery + " and CLID = '%1' and CID = '%2';").arg(m_vCLID).arg(m_vCID);

	showTable(selectQuery);
}


void Tab1::getProductInfo(QModelIndex)//获取选中行的PID和SID
{
	int row = ui.tableView->currentIndex().row();
	QModelIndex index = model->index(row, 0);
	m_vPID = model->data(index).toString();
	Parameter::getInstance()->m_vPID = m_vPID;
	index = model->index(row, 4);
	m_vSID = model->data(index).toInt();
	
	//int row = ui.tableView->currentIndex().row();
	//QModelIndex index1 = model->index(row, 4, QModelIndex());
	//m_vSID = index1.data().toString();
	//QModelIndex index2 = model->index(row, 0, QModelIndex());
	//m_vPID = index2.data().toString();
	

}


void Tab1::deleteProduct()
{
	QString deleteQuery = "delete from product where PID=?";
	QVector<QVariant>bindvalue;
	bindvalue.append(m_vPID);
	bool result = SqlOp::Delete_UpdateQuery(deleteQuery, bindvalue);
	if (result)    //如果删除成功
		QMessageBox::warning(this, "提示", "删除成功", QMessageBox::Yes);
	else
		QMessageBox::warning(this, "提示", "删除失败", QMessageBox::Yes);
	showTable(initQuery2);

}

void Tab1::buyProduct()
{
	QString m_vTID = UUid::getUUid();   //系统自动生成UUid,作为TID

	//将购买商品的信息插入交易表
	QString insertQuery = "insert into trade_record(TID,SID1,SID2,PID) values(?,?,?,?)";
	QVector<QVariant>bindvalue;
	bindvalue.append(m_vTID);
	bindvalue.append(m_vUserID);
	bindvalue.append(m_vSID);
	bindvalue.append(m_vPID);
	SqlOp::InsertQuery(insertQuery, bindvalue);
	

	showTable(initQuery2);

}

void Tab1::search()
{
	QString selectQuery = initQuery+ " and Pname  LIKE '%";
	selectQuery.append(ui.searhEdit->text());
	selectQuery.append("%'");
	showTable(selectQuery);

	QModelIndex index = model->index(0, 0, QModelIndex());
	QString str1 = index.data().toString();
	if (str1 == "")
	{
		QMessageBox::warning(this, "提示", "商品还在来的路上！", QMessageBox::Yes);
	}

}

void Tab1::showTable(QString selectQuery)
{
	model = new QSqlQueryModel(this);
	model->setQuery(selectQuery, SqlOp::GetDatabase());
	model->setHeaderData(0, Qt::Horizontal, "商品号");
	model->setHeaderData(1, Qt::Horizontal, "商品名");
	model->setHeaderData(2, Qt::Horizontal, "商品价格");
	model->setHeaderData(3, Qt::Horizontal, "商品描述");
	model->setHeaderData(4, Qt::Horizontal, "卖家号");
	model->setHeaderData(5, Qt::Horizontal, "卖家姓名");
	model->setHeaderData(6, Qt::Horizontal, "联系方式");

	ui.tableView->setModel(model);
	QHeaderView* headerView = ui.tableView->verticalHeader();
	headerView->setHidden(true);
	ui.tableView->horizontalHeader()->setStretchLastSection(true);

}
