#pragma execution_character_set("utf-8")
#include "tab2.h"
#include "getUUID.cpp"
Tab2::Tab2(QWidget *parent)
	: QWidget(parent)
{

	ui.setupUi(this);
//	connect(ui.collectBox, SIGNAL(currentIndexChanged(int)), this, SLOT(captureCardSlot(int)));
	connect(ui.PpriceEdit, SIGNAL(editingFinished()), this, SLOT(checkPprice()));    //�����Ʒ�۸�
	connect(ui.PpriceEdit, SIGNAL(returnPressed()), this, SLOT(checkPprice()));
	connect(ui.uploadButton, SIGNAL(clicked()), this, SLOT(upload()));  //�ϴ�

	ui.CLIDBox->addItem(tr("�鼮"));   
	ui.CLIDBox->addItem(tr("�Ҿ�"));
	ui.CLIDBox->addItem(tr("����"));
	ui.CLIDBox->addItem(tr("��ʳ"));
	ui.CLIDBox->addItem(tr("��ױƷ"));
	ui.CLIDBox->addItem(tr("�����豸"));
	ui.CLIDBox->addItem(tr("����"));

	ui.CIDBox->addItem(tr("ȫ��"));   
	ui.CIDBox->addItem(tr("�ų���"));
	ui.CIDBox->addItem(tr("�˳���"));
	ui.CIDBox->addItem(tr("�߳���"));
	ui.CIDBox->addItem(tr("������"));
	ui.CIDBox->addItem(tr("�����"));

}


Tab2::~Tab2()
{

}

void Tab2::checkPprice()   //���۸�
{	
	if (isDigitStr(ui.PpriceEdit->text()) == 0)
	{
		ui.PpriceEdit->clear();
		TipDialog *w = new TipDialog("okButtonOnly");
		w->setContent(tr("��������ȷ����ֵ"));
		w->show();
	}
}
int Tab2::isDigitStr(QString str)  //�ж��������ֵ�Ƿ�Ϊ��ȷ��С��
{
	QByteArray ba = str.toLatin1();//QString ת��Ϊ char*  
	const char *s = ba.data();
	int point = 1;    //С�����������ֻ��1��
	int num = 0;     //���ֵĸ���
	for (int i = 0; i < str.size(); i++)
	{
		if (i == 0 && s[i] == 0)
		{
			if ((str.size()>2 && s[i + 1] != '.') || str.size() == 1)
				//�������ֵΪ0�����ж�Ϊ�����ʽ������������һ������Ϊ0��0���治��С����Ҳ�ж�Ϊ��ʽ����
				return 0;
		}
		if (s[i] == '.')
		{
			point--;
			if (i == str.size() - 1 || i == 0)   //���С�������û�����֣�˵���������ֵ��ʽ����
				return 0;
		}
		if (point < 0)
			return 0;   //���С������������1����˵���������ֵ��ʽ����
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
	if (!ui.PnameEdit->text().isEmpty() && !ui.PpriceEdit->text().isEmpty())  //��������Ϊ��
	{
		int m_vSID = 0;
		QString m_vPID = "";
		int m_vCLID = 0;
		int m_vCID = 0;
		QString m_vPname = "";
		float m_vPprice = 0;
		QString m_vPdes = "";


		QString s1 = ui.CLIDBox->currentText();
		if (s1 == "�鼮")
			m_vCLID = 0;
		else if (s1 == "�Ҿ�")
			m_vCLID = 1;
		else if (s1 == "����")
			m_vCLID = 2;
		else if (s1 == "��ʳ")
			m_vCLID = 3;
		else if (s1 == "��ױƷ")
			m_vCLID = 4;
		else if (s1 == "�����豸")
			m_vCLID = 5;
		else if (s1 == "����")
			m_vCLID = 6;

		QString s2 = ui.CIDBox->currentText();
		if (s2 == "ȫ��")
			m_vCID = 10;
		else if (s2== "�ų���")
			m_vCID = 9;
		else if (s2 == "�˳���")
			m_vCID = 8;
		else if (s2 == "�߳���")
			m_vCID = 7;
		else if (s2 == "������")
			m_vCID = 6;
		else if (s2 == "�����")
			m_vCID = 5;


        m_vSID = Parameter::getInstance()->m_vUserID;
		m_vPID = UUid::getUUid();   //ϵͳ�Զ�����UUid,��ΪPID
		m_vPname = ui.PnameEdit->text();
		m_vPprice = ui.PpriceEdit->text().toFloat();
		m_vPdes = ui.PdesEdit->toPlainText();//textEdit��ȡ�ı�



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
		if (result)    //����ϴ��ɹ�
		{
			TipDialog *w = new TipDialog("okButtonOnly");
			w->setContent(tr("�ϴ��ɹ�"));
			w->show();
			ui.PnameEdit->clear();
			ui.PpriceEdit->clear();
			ui.PdesEdit->clear();
		}
		else
		{
			TipDialog *w = new TipDialog("okButtonOnly");
			w->setContent(tr("���ʧ�ܣ��������������"));
			w->show();
		}
	}
}
