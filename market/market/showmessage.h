#ifndef SHOWMESSAGE_H
#define SHOWMESSAGE_H

#include <QWidget>
#include "ui_showmessage.h"

class ShowMessage : public QWidget
{
	Q_OBJECT

public:
	ShowMessage(QWidget *parent = 0);
	~ShowMessage();

private:
	Ui::ShowMessage ui;
};

#endif // SHOWMESSAGE_H
