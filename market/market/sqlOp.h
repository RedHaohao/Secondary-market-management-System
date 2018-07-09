#ifndef SQLOP_H
#define SQLOP_H

#include <QtSql>
#include <QSqlDatabase>
#include "qvector.h"

/********************************************************************************************
* ������  ��SqlOp
* �������ܣ�ʵ��������ݿ��������ɾ�Ĳ�
*
* ��    �ߣ�������
* ������ڣ�2016��6��17��
*
* ������ʷ��
* 1������ʱ�䣺
*    �������ݣ�
*    ��    �ߣ�
* *********************************************************************************************/

class SqlOp
{
public:
	SqlOp();
	~SqlOp();


	static bool CreateConnection();
	static bool CloseConnection();

	//����Ҫ��̬������SQL��䣬�����ַ����ͣ���Ҫ�õ�������ס
	//��Ҫ�õ���̬������SQL��䣬����Ҫ���
	//���� name��varchar���ͣ�age������
	//����Ҫ��̬������insert into person (name,age) values("zhangsan",13)  
	//��Ҫ��̬������ insert into person (name ,age) values(:zhangsan,:age)

	//select column from table where column=?
	//select column from table where column=:column
	static QVector< QVector <QString> > SelectQuery(QString select, int num);//��ѯ��䣬��һ������ΪSQL��䣬�ڶ�������Ϊ��Ҫ������
	static QVector< QVector <QString> > SelectQuery(QString select, int num, QVector<QString> bindValue);//��ѯ��䣬��һ������ΪSQL��䣬�ڶ�������Ϊ������������Ϊ����
	//�������Ƽ�ʹ����������
	static QVector< QVector <QVariant> > SelectQuery2(QString select, int num);//��ѯ��䣬��һ������ΪSQL��䣬�ڶ�������Ϊ��Ҫ������
	static QVector< QVector <QVariant> > SelectQuery2(QString select, int num, QVector<QString> bindValue);//��ѯ��䣬��һ������ΪSQL��䣬�ڶ�������Ϊ������������Ϊ����
	//��ѯ�ⲿ���ݿ����������ʹ�õ�����
	static QVector< QVector <QVariant> > SelectQuery3(QString select, int num, QSqlDatabase qSqlDB);//��ѯ��䣬��һ������ΪSQL��䣬�ڶ�������Ϊ��Ҫ��������������Ϊָ�����ⲿ����
	//delete from table where column=?
	//delete from table where column=:column
	//update table set column=? where column=?
	//update table set column=:column where column=:column
	static bool Delete_UpdateQuery(QString del);
	static bool Delete_UpdateQuery(QString del, QVector<QVariant> bindValue);
	//insert into table (column1,cloumn2,column3,����) values(:column1,:column2,:column3,����)
	//insert into table (column1,cloumn2,column3,����) values(?,?,?,����)
	static bool InsertQuery(QString inserst);
	static bool InsertQuery(QString insert, QVector<QVariant> bindValue);

	//������Ŀ
	static int ExportProjectDb(const QString &dbName, const QString &ID);
	//������Ŀ
	static QVector< QVector <QVariant>> ImportProjectDbInfo(const QString &dbPath);
	static int ImportProjectDb(const QString &dbPath);


	//��ȡ���ݿ�
	static QSqlDatabase& GetDatabase();
};

#endif // SQL_H
