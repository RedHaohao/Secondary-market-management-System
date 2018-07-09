#ifndef TAB_H
#define TAB_H

#include <QWidget>
#include "ui_tab.h"
#include "sqlOp.h"
//#include "market.h"
//#include "getUUID.cpp"


class Tab : public QWidget
{
	Q_OBJECT

public:
	Tab(QWidget *parent = 0);
	~Tab();

private:
	Ui::Tab ui;

//	int m_vUserID;
};

#endif // TAB_H
