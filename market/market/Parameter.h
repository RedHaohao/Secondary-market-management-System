#pragma once
#include <QString>
#include <QSqlDatabase>

class Parameter
{
public:
	
	int m_vUserID;//用户ID
	QString m_vPID;//产品号
	int userFlag = 0;//0为用户，1为管理员
	QString m_vMessage;//用户留言

	static Parameter* getInstance();
	static Parameter *m_Parameter;
	void initParameter();
	Parameter();
	~Parameter();


	QSqlDatabase db;
};


