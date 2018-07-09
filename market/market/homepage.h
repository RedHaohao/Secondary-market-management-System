#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>
#include "ui_homepage.h"
#include<QLabel>
#include<QLineEdit>
#include<QComboBox>
#include<QTabWidget>
#include<QPushButton>
#include<QMouseEvent>
#include<QString>
#include<QKeyEvent>
#include <QDesktopWidget>
#include <QDebug>
#include "tab1.h"
#include "tab2.h"
#include "tab3.h"

#include "sqlOp.h"


class HomePage : public QWidget
{
	Q_OBJECT

public:
	HomePage(QString UserID="", QWidget *parent = 0);
	~HomePage();


	private slots:
	
	void narrowbuttonclicked();
	void closebuttonclicked();
//	void tabBarclicked(int a);


protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);

private:
	QPoint offset;
	Ui::HomePage ui;

	QString m_vUserID;

	Tab1 * m_pTab1;
	Tab2 * m_pTab2;
	Tab3 * m_pTab3;
	//Tab4 * m_pTab4;
};

#endif // HOMEPAGE_H
