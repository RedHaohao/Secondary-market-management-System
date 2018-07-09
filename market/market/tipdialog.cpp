#include "tipdialog.h"
#include "qprocess.h"


TipDialog::TipDialog(QWidget *parent, QString func)
: QWidget(parent)
{
	ui.setupUi(this);
	ui.textlable->setWordWrap(true);

	this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::Tool);	//�����ޱ߿򡢴����ö����������޴���

	this->setWindowModality(Qt::ApplicationModal);//���������������
	this->setAttribute(Qt::WA_TranslucentBackground);  //����͸����

	function = func;
	connect(ui.CloseButton, SIGNAL(clicked()), this, SLOT(onCloseButtonClicked()));
	connect(ui.CancelButton, SIGNAL(clicked()), this, SLOT(onCancleButtonClicked()));
	connect(ui.OKButton, SIGNAL(clicked()), this, SLOT(onOkButtonClicked()));
}



//TipDialog::TipDialog(int i, QWidget *parent, QString func)
//	: QWidget(parent)
//{
//
//}

TipDialog::TipDialog(QString pattern, QWidget *parent, QString func)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.textlable->setWordWrap(true);
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::Tool);
	//this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
	this->setAttribute(Qt::WA_TranslucentBackground);  //����͸����
	function = func;
	if (0 == pattern.compare("okButtonOnly"))
	{
		this->setWindowModality(Qt::ApplicationModal);//���������������
		ui.CancelButton->setEnabled(false);
		ui.CancelButton->setVisible(false);
		ui.CloseButton->setEnabled(false);
		ui.CloseButton->setVisible(false);
		ui.OKButton->setGeometry(QRect(124, 149, 78, 26));

		connect(ui.OKButton, SIGNAL(clicked()), this, SLOT(closeDialog()));

		return;
		
	}
	if (0 == pattern.compare("noButton"))
	{
		ui.OKButton->setEnabled(false);
		ui.OKButton->setVisible(false);
		ui.CancelButton->setEnabled(false);
		ui.CancelButton->setVisible(false);
		ui.CloseButton->setEnabled(false);
		ui.CloseButton->setVisible(false);
		return;
	}
}

TipDialog::~TipDialog()
{

}

void TipDialog::setTitle(QString title)
{
	ui.titilelabel->setText(title);
}

void TipDialog::setContent(QString text)
{
	ui.textlable->setText(text);
}

void TipDialog::onCloseButtonClicked()
{
	emit tipDialogCancel();
	this->close();
	emit closeButtonClicked();
}

void TipDialog::onCancleButtonClicked()
{
	this->close();
	emit cancleButtonClicked();
}

void TipDialog::onOkButtonClicked()
{
	this->close();
	emit okButtonClicked();
}

void TipDialog::closeDialog()
{
	if (function == "Reset")
	{
		//��������ϵͳ
		qApp->quit();
		QProcess::startDetached(qApp->applicationFilePath(), QStringList());
	}
	else
	{
		emit tipDialogClose();
		this->close();
	}	
}
void TipDialog::hidebutton()
{
	ui.OKButton->setVisible(false);
}

void TipDialog::releasebutton()
{
	ui.OKButton->setVisible(true);
}

Ui::tipdialog TipDialog::getUi()
{
	return ui;
}