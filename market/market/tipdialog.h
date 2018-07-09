#ifndef TIPDIALOG_H
#define TIPDIALOG_H
#include <QWidget>

#include "ui_tipdialog.h"
/********************************************************************************************
* 类名称  ：TipDialog
* 基本功能：实现公告栏功能
*
* 作    者：
* 完成日期：2016年4月16日
*
* 更新历史：
* 1，更新时间：
*    更新内容：
*    作    者：
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
