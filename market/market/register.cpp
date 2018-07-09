#pragma execution_character_set("utf-8")
#include "register.h"

Register::Register(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setFixedSize(450, 338);                                  //�̶���С
	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
	//	this->setAttribute(Qt::WA_TranslucentBackground);            //����͸����
	//	this->setStyleSheet("background-color:white;");

	QDesktopWidget* pDw = QApplication::desktop();                 //������洰��
	move((pDw->width() - this->width()) / 2, (pDw->height() - this->height()) / 2);

	connect(ui.returnButton, SIGNAL(clicked()), this, SLOT(returnBtn()));
	connect(ui.registerButton, SIGNAL(clicked()), this, SLOT(registerBtn()));

	connect(ui.IDEdit, SIGNAL(editingFinished()), this, SLOT(checkIDEditinfo()));
	connect(ui.contactEdit, SIGNAL(editingFinished()), this, SLOT(checkContactEditinfo()));

	ui.sexBox->addItem("�к���");
	ui.sexBox->addItem("Ů����");
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
		if (result)    //����ϴ��ɹ�
		{
			TipDialog *w = new TipDialog("okButtonOnly");
			w->setContent(tr("�ϴ��ɹ�"));
			w->show();
			ui.IDEdit->clear();
			ui.nameEdit->clear();
			ui.contactEdit->clear();
			ui.passwordEdit->clear();
		}
		else
		{
			TipDialog *w = new TipDialog("okButtonOnly");
			w->setContent(tr("���ʧ�ܣ�����������ѧ��"));
			w->show();
		}
	}
	else
	{
		TipDialog *w = new TipDialog("okButtonOnly");
		w->setContent(tr("����д��Ϣ"));
		w->show();
	}
	
}



void Register::checkContactEditinfo()
{
	if (isDigital(ui.contactEdit->text()) == 0)
	{
		ui.contactEdit->clear();
		TipDialog *w = new TipDialog("okButtonOnly");
		w->setContent(tr("��������ϵ��ʽ"));
		w->show();
	}
}


void Register::checkIDEditinfo()
{
	if (isDigital(ui.IDEdit->text()) == 0)
	{
		ui.IDEdit->clear();
		TipDialog *w = new TipDialog("okButtonOnly");
		w->setContent(tr("������ѧ��"));
		w->show();
	}
}





int Register::isDigital(QString str)   //�ж��Ƿ�Ϊ������
{
	QByteArray ba = str.toLatin1();//QString ת��Ϊ char*  
	const char *s = ba.data();
	while (*s && *s >= '0' && *s <= '9') s++;
	if (*s)
	{ //���Ǵ�����  
		return 0;
	}
	else
	{ //������  
		return 1;
	}
}
