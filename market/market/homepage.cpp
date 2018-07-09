#pragma execution_character_set("utf-8")
#include "homepage.h"
//HomePage(QString m_vUserID = "", QWidget *parent = 0);
HomePage::HomePage(QString UserID, QWidget *parent )
	: QWidget(parent)
{


	ui.setupUi(this);
	//setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);

	setWindowFlags(Qt::FramelessWindowHint);  //消除运行边框
	m_vUserID = UserID;
	m_pTab1 = new Tab1();
	ui.tabWidget->addTab(m_pTab1, "所有商品");
	if (Parameter::getInstance()->userFlag == 0)
	{
		m_pTab2 = new Tab2();
		ui.tabWidget->addTab(m_pTab2, "上传商品");
		m_pTab3 = new Tab3();
		ui.tabWidget->addTab(m_pTab3, "个人信息");
	}
	 
	ui.tabWidget->currentIndex();
	connect(ui.narrowbutton, SIGNAL(clicked()), this, SLOT(narrowbuttonclicked()));
	connect(ui.closebutton, SIGNAL(clicked()), this, SLOT(closebuttonclicked()));
//	connect(ui.tabWidget, SIGNAL(tabBarClicked(int)), this, SLOT(tabBarclicked(int)));
	

	QDesktopWidget* pDw = QApplication::desktop();                 //获得桌面窗体
	move((pDw->width() - this->width()) / 2, (pDw->height() - this->height()) / 2);      //居中显示
}
//void HomePage::tabBarclicked(int index)
//{
//	if (index == 1)
//	{
//		m_pTabDataOutput->Update();
//	}
//	if (index == 0)
//	{
//		m_pTabStartSell->Refresh();
//	}
//}
void HomePage::narrowbuttonclicked()//最小化
{
	QWidget::showMinimized();
}
void HomePage::closebuttonclicked()//关闭窗口
{
	QApplication *a;
	a->exit();
	//close();
}
void HomePage::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		offset = QCursor::pos() - frameGeometry().topLeft();
	}
	QWidget::mousePressEvent(event);
}

void HomePage::mouseMoveEvent(QMouseEvent *event)
{
	if (event->buttons() & Qt::LeftButton)
	{
		QRect desktopRc = QApplication::desktop()->availableGeometry();
		QPoint curPoint = event->globalPos() - offset;
		if (event->globalY() > desktopRc.height())
		{
			curPoint.setY(desktopRc.height() - offset.y());
		}
		move(curPoint);
	}
	QWidget::mouseMoveEvent(event);
}
void HomePage::mouseReleaseEvent(QMouseEvent *event)
{
	event->accept();
}


HomePage::~HomePage()
{

}
