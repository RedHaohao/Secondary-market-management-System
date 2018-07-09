#pragma execution_character_set("utf-8")
#include "market.h"

market::market(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setFixedSize(450, 338);                                  //�̶���С
	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
	//	this->setAttribute(Qt::WA_TranslucentBackground);            //����͸����
	//	this->setStyleSheet("background-color:white;");

	QDesktopWidget* pDw = QApplication::desktop();                 //������洰��
	move((pDw->width() - this->width()) / 2, (pDw->height() - this->height()) / 2);      //������ʾ

	ui.userIDEdit->setPlaceholderText("�������˺�");
	ui.passWordEdit->setPlaceholderText("����������");
	ui.passWordEdit->setEchoMode(QLineEdit::Password);             //���������ʽ


	connect(ui.loginBtn, SIGNAL(clicked()), this, SLOT(loginBtnSlot()));      //��¼�ۺ���
	connect(ui.registerButton, SIGNAL(clicked()), this, SLOT(registerBtnSlot()));      //��¼�ۺ���
	connect(ui.narrowBtn, SIGNAL(clicked()), this, SLOT(narrowBtnSlot()));    //��С�ۺ���
	connect(ui.closeBtn, SIGNAL(clicked()), this, SLOT(closeBtnSlot()));      //�رղۺ���

	QButtonGroup* pButtonGroup = new QButtonGroup(this);
	pButtonGroup->addButton(ui.stuBox, 1);
	pButtonGroup->addButton(ui.adminBox, 2);
	ui.stuBox->setCheckState(Qt::Checked);
}

market::~market()
{

}

void market::registerBtnSlot()
{
	m_pRegister = new Register;
	m_pRegister->show();

}
void market::loginBtnSlot()
{
	m_vUserID = ui.userIDEdit->text();               //��������û�����ֵ������
	m_vUserPWD = ui.passWordEdit->text();
	Parameter::getInstance()->m_vUserID = m_vUserID.toInt();

	if (m_vUserID == "" || m_vUserPWD == "")           //�ж��û����������Ƿ�Ϊ��
	{
		TipDialog *w = new TipDialog("okButtonOnly");
		w->setContent(tr("�˺Ż�����Ϊ�գ�����������"));
		w->show();
		//	QMessageBox::warning(this, "��ʾ", "�û���������Ϊ�գ�����������", QMessageBox::Yes);
		ui.userIDEdit->clear();
		ui.passWordEdit->clear();

	}
	else
	{
		QString searchUser = "";
		if (ui.stuBox->isChecked())
			searchUser = "select SID,Spassword from student where SID = ? and Spassword = ?";
		 else if(ui.adminBox->isChecked())
		 { 
			searchUser = "select AID,Apassword from admin where AID = ? and Apassword = ?";
			Parameter::getInstance()->userFlag = 1;
		}

		QVector<QString > bindValue;
		bindValue.append(m_vUserID);
		bindValue.append(m_vUserPWD);

		QVector<QVector<QString> > result;
		QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL", "market.db");
		result = SqlOp::SelectQuery(searchUser, 3, bindValue);

		if (result.size() > 0)
		{

			qDebug() << "---------------";
			HomePage * homepage = new HomePage(m_vUserID);                    //��¼�ɹ�������ת��homepage
			homepage->show();
			this->hide();
		}


		else
		{
			TipDialog *w = new TipDialog("okButtonOnly");
			//		w->setContent(tr("ѧ�Ż������������������"));
			//		w->show();
			QMessageBox::warning(this, "��ʾ", "�˺Ż������������������", QMessageBox::Yes);
			ui.userIDEdit->clear();
			ui.passWordEdit->clear();

		}
	}
}

void market::narrowBtnSlot()                            //��С��
{

	QWidget::showMinimized();
}


void market::closeBtnSlot()                             //�ر�
{
	QApplication *app;
	app->exit();

}



void market::keyPressEvent(QKeyEvent  *event)           //�س�����С���̵�Enter��
{
	if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
	{
		loginBtnSlot();
	}
}

