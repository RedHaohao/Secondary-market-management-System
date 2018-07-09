#pragma execution_character_set("utf-8")
#include "register.h"

Register::Register(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setFixedSize(450, 338);                                  //固定大小
	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
	//	this->setAttribute(Qt::WA_TranslucentBackground);            //背景透明化
	//	this->setStyleSheet("background-color:white;");

	QDesktopWidget* pDw = QApplication::desktop();                 //获得桌面窗体
	move((pDw->width() - this->width()) / 2, (pDw->height() - this->height()) / 2);

	connect(ui.returnButton, SIGNAL(clicked()), this, SLOT(returnBtn()));
	connect(ui.registerButton, SIGNAL(clicked()), this, SLOT(registerBtn()));

	connect(ui.IDEdit, SIGNAL(editingFinished()), this, SLOT(checkIDEditinfo()));
	connect(ui.contactEdit, SIGNAL(editingFinished()), this, SLOT(checkContactEditinfo()));

	ui.sexBox->addItem("男孩子");
	ui.sexBox->addItem("女孩子");
}

Register::~Register()
{

}

void Register::returnBtn()
{
	this->close();
}


void Register::registerBtn()
{
	if (!ui.IDEdit->text().isEmpty() && !ui.nameEdit->text().isEmpty() && !ui.contactEdit->text().isEmpty() && !ui.passwordEdit->text().isEmpty())
	{
		int m_vID = ui.IDEdit->text().toInt();
		QString m_vName = ui.nameEdit->text();
		QString m_vSex = ui.sexBox->currentText();
		QString m_vContact = ui.contactEdit->text();
		QString m_vPassword = ui.passwordEdit->text();
		QString insertQuery = "insert into student(SID,SName,Scontact,Spassword,Ssex) values(?,?,?,?,?)";
		QVector<QVariant>bindvalue;
		bindvalue.append(m_vID);
		bindvalue.append(m_vName);
		bindvalue.append(m_vContact);
		bindvalue.append(m_vPassword);
		bindvalue.append(m_vSex);
		bool result = SqlOp::InsertQuery(insertQuery, bindvalue);
		if (result)    //如果上传成功
		{
			TipDialog *w = new TipDialog("okButtonOnly");
			w->setContent(tr("上传成功"));
			w->show();
			ui.IDEdit->clear();
			ui.nameEdit->clear();
			ui.contactEdit->clear();
			ui.passwordEdit->clear();
		}
		else
		{
			TipDialog *w = new TipDialog("okButtonOnly");
			w->setContent(tr("添加失败，请输入其他学号"));
			w->show();
		}
	}
	else
	{
		TipDialog *w = new TipDialog("okButtonOnly");
		w->setContent(tr("请填写信息"));
		w->show();
	}
	
}



void Register::checkContactEditinfo()
{
	if (isDigital(ui.contactEdit->text()) == 0)
	{
		ui.contactEdit->clear();
		TipDialog *w = new TipDialog("okButtonOnly");
		w->setContent(tr("请输入联系方式"));
		w->show();
	}
}


void Register::checkIDEditinfo()
{
	if (isDigital(ui.IDEdit->text()) == 0)
	{
		ui.IDEdit->clear();
		TipDialog *w = new TipDialog("okButtonOnly");
		w->setContent(tr("请输入学号"));
		w->show();
	}
}





int Register::isDigital(QString str)   //判断是否为纯数字
{
	QByteArray ba = str.toLatin1();//QString 转换为 char*  
	const char *s = ba.data();
	while (*s && *s >= '0' && *s <= '9') s++;
	if (*s)
	{ //不是纯数字  
		return 0;
	}
	else
	{ //纯数字  
		return 1;
	}
}
