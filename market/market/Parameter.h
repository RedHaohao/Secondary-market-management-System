#pragma once
#include <QString>
#include <QSqlDatabase>

class Parameter
{
public:
	
	int m_vUserID;//�û�ID
	QString m_vPID;//��Ʒ��
	int userFlag = 0;//0Ϊ�û���1Ϊ����Ա
	QString m_vMessage;//�û�����

	static Parameter* getInstance();
	static Parameter *m_Parameter;
	void initParameter();
	Parameter();
	~Parameter();


	QSqlDatabase db;
};


