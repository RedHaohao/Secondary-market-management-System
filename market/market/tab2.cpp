#pragma execution_character_set("utf-8")
#include "tab2.h"
#include "getUUID.cpp"
Tab2::Tab2(QWidget *parent)
	: QWidget(parent)
{

	ui.setupUi(this);
//	connect(ui.collectBox, SIGNAL(currentIndexChanged(int)), this, SLOT(captureCardSlot(int)));
	connect(ui.PpriceEdit, SIGNAL(editingFinished()), this, SLOT(checkPprice()));    //检查商品价格
	connect(ui.PpriceEdit, SIGNAL(returnPressed()), this, SLOT(checkPprice()));
	connect(ui.uploadButton, SIGNAL(clicked()), this, SLOT(upload()));  //上传

	ui.CLIDBox->addItem(tr("书籍"));   
	ui.CLIDBox->addItem(tr("家具"));
	ui.CLIDBox->addItem(tr("服饰"));
	ui.CLIDBox->addItem(tr("零食"));
	ui.CLIDBox->addItem(tr("化妆品"));
	ui.CLIDBox->addItem(tr("电子设备"));
	ui.CLIDBox->addItem(tr("其他"));

	ui.CIDBox->addItem(tr("全新"));   
	ui.CIDBox->addItem(tr("九成新"));
	ui.CIDBox->addItem(tr("八成新"));
	ui.CIDBox->addItem(tr("七成新"));
	ui.CIDBox->addItem(tr("六成新"));
	ui.CIDBox->addItem(tr("五成新"));

}


Tab2::~Tab2()
{

}

void Tab2::checkPprice()   //检查价格
{	
	if (isDigitStr(ui.PpriceEdit->text()) == 0)
	{
		ui.PpriceEdit->clear();
		TipDialog *w = new TipDialog("okButtonOnly");
		w->setContent(tr("请输入正确的数值"));
		w->show();
	}
}
int Tab2::isDigitStr(QString str)  //判断输入的数值是否为正确的小数
{
	QByteArray ba = str.toLatin1();//QString 转换为 char*  
	const char *s = ba.data();
	int point = 1;    //小数点数量最多只有1个
	int num = 0;     //数字的个数
	for (int i = 0; i < str.size(); i++)
	{
		if (i == 0 && s[i] == 0)
		{
			if ((str.size()>2 && s[i + 1] != '.') || str.size() == 1)
				//如果输入值为0，则判断为输入格式错误。如果输入第一个数字为0，0后面不是小数点也判断为格式错误。
				return 0;
		}
		if (s[i] == '.')
		{
			point--;
			if (i == str.size() - 1 || i == 0)   //如果小数点后面没有数字，说明输入的数值格式错误
				return 0;
		}
		if (point < 0)
			return 0;   //如果小数点数量大于1个，说明输入的数值格式错误
		if (s[i] >= '0' && s[i] <= '9')
			num = num + 1;
	}
	if (point == 1)
	{
		if (num == str.size())
			return 1;
		else return 0;
	}
	else if (point == 0)
	{
		if (num + 1 == str.size())
			return 1;
		else return 0;
	}
}

void Tab2::upload()
{
	if (!ui.PnameEdit->text().isEmpty() && !ui.PpriceEdit->text().isEmpty())  //描述可以为空
	{
		int m_vSID = 0;
		QString m_vPID = "";
		int m_vCLID = 0;
		int m_vCID = 0;
		QString m_vPname = "";
		float m_vPprice = 0;
		QString m_vPdes = "";


		QString s1 = ui.CLIDBox->currentText();
		if (s1 == "书籍")
			m_vCLID = 0;
		else if (s1 == "家具")
			m_vCLID = 1;
		else if (s1 == "服饰")
			m_vCLID = 2;
		else if (s1 == "零食")
			m_vCLID = 3;
		else if (s1 == "化妆品")
			m_vCLID = 4;
		else if (s1 == "电子设备")
			m_vCLID = 5;
		else if (s1 == "其他")
			m_vCLID = 6;

		QString s2 = ui.CIDBox->currentText();
		if (s2 == "全新")
			m_vCID = 10;
		else if (s2== "九成新")
			m_vCID = 9;
		else if (s2 == "八成新")
			m_vCID = 8;
		else if (s2 == "七成新")
			m_vCID = 7;
		else if (s2 == "六成新")
			m_vCID = 6;
		else if (s2 == "五成新")
			m_vCID = 5;


        m_vSID = Parameter::getInstance()->m_vUserID;
		m_vPID = UUid::getUUid();   //系统自动生成UUid,作为PID
		m_vPname = ui.PnameEdit->text();
		m_vPprice = ui.PpriceEdit->text().toFloat();
		m_vPdes = ui.PdesEdit->toPlainText();//textEdit获取文本



		QString insertQuery = "insert into product(PID,Pname,Pprice,Pdescription,CLID,CID,SID) values(?,?,?,?,?,?,?)";
		qDebug() << insertQuery;
		QVector<QVariant>bindvalue;
		bindvalue.append(m_vPID);
		bindvalue.append(m_vPname);
		bindvalue.append(m_vPprice);
		bindvalue.append(m_vPdes);
		bindvalue.append(m_vCLID);
		bindvalue.append(m_vCID);
		bindvalue.append(m_vSID);
		



		bool result = SqlOp::InsertQuery(insertQuery, bindvalue);
		if (result)    //如果上传成功
		{
			TipDialog *w = new TipDialog("okButtonOnly");
			w->setContent(tr("上传成功"));
			w->show();
			ui.PnameEdit->clear();
			ui.PpriceEdit->clear();
			ui.PdesEdit->clear();
		}
		else
		{
			TipDialog *w = new TipDialog("okButtonOnly");
			w->setContent(tr("添加失败，请检查后重新输入"));
			w->show();
		}
	}
}
