#pragma execution_character_set("utf-8")
#include "message.h"

Message::Message(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);


	showTable(selectQuery);
	connect(ui.okButton, SIGNAL(clicked()), this, SLOT(finish()));
}

Message::~Message()
{

}

void Message::finish()
{
	qDebug() << "!!!!!!!!!!!okbutton";
	Parameter::getInstance()->m_vMessage = ui.messageEdit->toPlainText();//textEdit��ȡ�ı�
	QString insertQuery = "insert into message(SID,PID,Mess) values(?,?,?)";
	QVector<QVariant>bindvalue;
	bindvalue.append(Parameter::getInstance()->m_vUserID);
	bindvalue.append(Parameter::getInstance()->m_vPID);
	bindvalue.append(Parameter::getInstance()->m_vMessage);
	bool result = SqlOp::InsertQuery(insertQuery, bindvalue);
	if (result)    
		QMessageBox::warning(this, "��ʾ", "���Գɹ�", QMessageBox::Yes);
	else
		QMessageBox::warning(this, "��ʾ", "����ʧ��", QMessageBox::Yes);
	showTable(selectQuery);
}

void Message::showTable(QString selectQuery)
{
	model = new QSqlQueryModel(this);
	model->setQuery(selectQuery, SqlOp::GetDatabase());
	model->setHeaderData(0, Qt::Horizontal, "�û���");
	model->setHeaderData(1, Qt::Horizontal, "�û�����");
	ui.tableView->setModel(model);
	QHeaderView* headerView = ui.tableView->verticalHeader();
	headerView->setHidden(true);
	ui.tableView->horizontalHeader()->setStretchLastSection(true);

}
