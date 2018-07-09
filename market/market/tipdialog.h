#ifndef TIPDIALOG_H
#define TIPDIALOG_H
#include <QWidget>

#include "ui_tipdialog.h"
/********************************************************************************************
* ������  ��TipDialog
* �������ܣ�ʵ�ֹ���������
*
* ��    �ߣ�
* ������ڣ�2016��4��16��
*
* ������ʷ��
* 1������ʱ�䣺
*    �������ݣ�
*    ��    �ߣ�
* *********************************************************************************************/

class TipDialog : public QWidget
{
	Q_OBJECT

public:
	TipDialog(QWidget *parent = 0, QString func = "");
	//TipDialog(int i, QWidget *parent = 0, QString func = "");
	TipDialog(QString pattern, QWidget *parent = 0, QString func = "");

	~TipDialog();

	void setContent(QString text);
	void setTitle(QString title);
	void hidebutton();
	void releasebutton();
	Ui::tipdialog getUi();

private:
	Ui::tipdialog ui;
	QString function;

signals:
	void closeButtonClicked();
	void cancleButtonClicked();
	void okButtonClicked();
	void tipDialogClose();
	void tipDialogCancel();

public slots:
	void closeDialog();
	void onCloseButtonClicked();
	void onCancleButtonClicked();
	void onOkButtonClicked();
};

#endif // TIPDIALOG_H
