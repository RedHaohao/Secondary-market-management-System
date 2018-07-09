#ifndef TAB4_H
#define TAB4_H

#include <QWidget>
#include "ui_tab4.h"

class Tab4 : public QWidget
{
	Q_OBJECT

public:
	Tab4(QWidget *parent = 0);
	~Tab4();

private:
	Ui::Tab4 ui;
};

#endif // TAB4_H
