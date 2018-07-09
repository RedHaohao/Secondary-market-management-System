#pragma execution_character_set("utf-8")
#include "market.h"

market::market(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setFixedSize(450, 338);                                  //固定大小
	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
	//	this->setAttribute(Qt::WA_TranslucentBackground);            //背景透明化
	//	this->setStyleSheet("background-color:white;");

	QDesktopWidget* pDw = QApplication::desktop();                 //获得桌面窗体
	move((pDw->width() - this->width()) / 2, (pDw->height() - this->height()) / 2);      //居中显示

	ui.userIDEdit->setPlaceholderText("请输入账号");
	ui.passWordEdit->setPlaceholderText("请输入密码");
	ui.passWordEdit->setEchoMode(QLineEdit::Password);             //设置密码格式


	connect(ui.loginBtn, SIGNAL(clicked()), this, SLOT(loginBtnSlot()));      //登录槽函数
	connect(ui.registerButton, SIGNAL(clicked()), this, SLOT(registerBtnSlot()));      //登录槽函数
	connect(ui.narrowBtn, SIGNAL(clicked()), this, SLOT(narrowBtnSlot()));    //缩小槽函数
	connect(ui.closeBtn, SIGNAL(clicked()), this, SLOT(closeBtnSlot()));      //关闭槽函数

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
	m_vUserID = ui.userIDEdit->text();               //将输入的用户名赋值给变量
	m_vUserPWD = ui.passWordEdit->text();
	Parameter::getInstance()->m_vUserID = m_vUserID.toInt();

	if (m_vUserID == "" || m_vUserPWD == "")           //判断用户名或密码是否为空
	{
		TipDialog *w = new TipDialog("okButtonOnly");
		w->setContent(tr("账号或密码为空，请重新输入"));
		w->show();
		//	QMessageBox::warning(this, "提示", "用户名或密码为空，请重新输入", QMessageBox::Yes);
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
			HomePage * homepage = new HomePage(m_vUserID);                    //登录成功，则跳转到homepage
			homepage->show();
			this->hide();
		}


		else
		{
			TipDialog *w = new TipDialog("okButtonOnly");
			//		w->setContent(tr("学号或密码错误，请重新输入"));
			//		w->show();
			QMessageBox::warning(this, "提示", "账号或密码错误，请重新输入", QMessageBox::Yes);
			ui.userIDEdit->clear();
			ui.passWordEdit->clear();

		}
	}
}

void market::narrowBtnSlot()                            //最小化
{

	QWidget::showMinimized();
}


void market::closeBtnSlot()                             //关闭
{
	QApplication *app;
	app->exit();

}



void market::keyPressEvent(QKeyEvent  *event)           //回车键和小键盘的Enter键
{
	if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
	{
		loginBtnSlot();
	}
}

