#pragma execution_character_set("utf-8")
#include "sqlOp.h"
#include "qdebug.h"

SqlOp::SqlOp()
{

}

SqlOp::~SqlOp()
{

}


/*******************************************************************************************
* �������ƣ�CreateConnection
* �������ܣ��������ݿ�
* �����������1��HostName�����ݿ������ַ�� ��2��DatabaseName�����ݿ����ƣ� ��3��UserName���û��� ����4��Password������
* �����������
* ����ֵ  ����
********************************************************************************************/
bool SqlOp::CreateConnection()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL", "connection1");

	db.setDatabaseName("market");
	db.setUserName("root");

	if (db.open())
	{
		qDebug() << "CreateConnection:" << "connect  success";
		return true;
	}
	else
	{
		qDebug() << db.lastError().text();
		return false;
	}
}


/*******************************************************************************************
* �������ƣ�CloseConnection
* �������ܣ��ر����ݿ�
* �����������
* �����������
* ����ֵ  ����
********************************************************************************************/
bool SqlOp::CloseConnection()
{
	QSqlDatabase db = QSqlDatabase::database(QSqlDatabase::defaultConnection, false);
	if (db.isOpen())
	{
		db.close();
		qDebug() << "close " + db.databaseName() + " success";
		return true;
	}
	return false;
}

/*******************************************************************************************
* �������ƣ�SelectQuery
* �������ܣ���ѯ��䣬���ص�����Ϊ�ַ�����ʽ
* �����������1��select��sql��� ��2��num����ѯ������
* ���������result
* ����ֵ  ����ѯ���
********************************************************************************************/
QVector< QVector <QString> > SqlOp::SelectQuery(QString select, int num)
{
	QVector< QVector <QString> >  result;   //��Ų�ѯ���

	QSqlQuery query;
	query.exec(select);

	if (query.lastError().isValid())
	{
		qDebug() << query.lastError();
	}
	else
	{
		qDebug() <<"SelectQuery:"<< "select success";
		while (query.next())
		{
			QVector <QString> resultTemp;
			QString temp;
			for (int i = 0; i < num; i++)
			{
				temp = query.value(i).toString();
				resultTemp.append(temp);
			}
			result.append(resultTemp);
		}
	}

	return result;
}

/*******************************************************************************************
* �������ƣ�SelectQuery
* �������ܣ�����̬��������ѯ��䣬���ص�����Ϊ�ַ�����ʽ
* �����������1��select��sql��� ��2��num����ѯ������ ��3��bindValue����̬��������
* ���������result
* ����ֵ  ����ѯ���
********************************************************************************************/
QVector< QVector <QString> > SqlOp::SelectQuery(QString select, int num, QVector<QString> bindValue)
{
	QVector< QVector <QString> >  result;   //��Ų�ѯ���
	QSqlQuery query(GetDatabase());
	query.prepare(select);
	for (int i = 0; i < bindValue.size(); i++)
	{
		query.bindValue(i, bindValue[i]);
	}
	query.exec();

	if (query.lastError().isValid())
	{
		qDebug() << query.lastError();
	}
	else
	{
		qDebug() << "select success";
		while (query.next())
		{
			QVector <QString> resultTemp;
			QString temp;
			for (int i = 0; i < num; i++)
			{
				temp = query.value(i).toString();
				resultTemp.append(temp);
			}
			result.append(resultTemp);
		}
	}

	return  result;
}

/*******************************************************************************************
* �������ƣ�SelectQuery2
* �������ܣ���ѯ��䣬���ص�����Ϊ�ɱ�������ʽ
* �����������1��select��sql��� ��2��num����ѯ������
* ���������result
* ����ֵ  ����ѯ���
********************************************************************************************/
QVector< QVector <QVariant> > SqlOp::SelectQuery2(QString select, int num)
{
	QVector< QVector <QVariant> >  result;   //��Ų�ѯ���
	QSqlQuery query;
	query.exec(select);
	if (query.lastError().isValid())
	{
		qDebug() << query.lastError();
	}
	else
	{
		qDebug() << "select success";
		while (query.next())
		{
			QVector <QVariant> resultTemp;
			QVariant temp;
			for (int i = 0; i < num; i++)
			{
				temp = query.value(i);
				resultTemp.append(temp);
			}
			result.append(resultTemp);
		}
	}

	return result;
}

/*******************************************************************************************
* �������ƣ�SelectQuery2
* �������ܣ�����̬��������ѯ��䣬���ص�����Ϊ�ɱ�������ʽ
* �����������1��select��sql��� ��2��num����ѯ������ ��3��bindValue����̬��������
* ���������result
* ����ֵ  ����ѯ���
********************************************************************************************/
QVector< QVector <QVariant> > SqlOp::SelectQuery2(QString select, int num, QVector<QString> bindValue)
{
	QVector< QVector <QVariant> >  result;   //��Ų�ѯ���
	QSqlQuery query;
	query.prepare(select);
	for (int i = 0; i < bindValue.size(); i++)
	{
		query.bindValue(i, bindValue[i]);
	}
	query.exec();

	if (query.lastError().isValid())
	{
		qDebug() << query.lastError();
	}
	else
	{
		qDebug() << "select success";
		while (query.next())
		{
			QVector <QVariant> resultTemp;
			QVariant temp;
			for (int i = 0; i < num; i++)
			{
				temp = query.value(i);
				resultTemp.append(temp);
			}
			result.append(resultTemp);
		}
	}

	return result;
}


/*******************************************************************************************
* �������ƣ�SelectQuery3
* �������ܣ���ѯ��䣬���ص�����Ϊ�ɱ�������ʽ
* �����������1��select��sql��� ��2��num����ѯ������ ��3��ָ�����ݿ��ѯ
* ���������result
* ����ֵ  ����ѯ���
********************************************************************************************/
QVector< QVector <QVariant> > SqlOp::SelectQuery3(QString select, int num, QSqlDatabase qSqlDB)
{
	QVector< QVector <QVariant> >  result;   //��Ų�ѯ���
	QSqlQuery query(qSqlDB);
	query.exec(select);
	if (query.lastError().isValid())
	{
		qDebug() << query.lastError();
	}
	else
	{
		qDebug() << "select success";
		while (query.next())
		{
			QVector <QVariant> resultTemp;
			QVariant temp;
			for (int i = 0; i < num; i++)
			{
				temp = query.value(i);
				resultTemp.append(temp);
			}
			result.append(resultTemp);
		}
	}

	return result;
}
/*******************************************************************************************
* �������ƣ�Delete_UpdateQuery
* �������ܣ�ɾ�����߸������
* �����������1��del��sql���
* ���������bool
* ����ֵ  ���������
********************************************************************************************/
bool SqlOp::Delete_UpdateQuery(QString del)
{
	QSqlQuery query;
	query.exec(del);

	if (query.lastError().isValid())
	{
		qDebug() << query.lastError();
		return false;
	}
	qDebug() << "Delete_Update success";
	return true;
}

/*******************************************************************************************
* �������ƣ�Delete_UpdateQuery
* �������ܣ�����̬������ɾ�����߸������
* �����������1��del��sql��䣻��2��binfValue����̬��������
* ���������bool
* ����ֵ  ���������
********************************************************************************************/
bool SqlOp::Delete_UpdateQuery(QString del, QVector<QVariant> bindValue)
{
	QSqlQuery query(GetDatabase());
	query.prepare(del);
	for (int i = 0; i < bindValue.size(); i++)
	{
		query.bindValue(i, bindValue[i]);
	}
	query.exec();

	if (query.lastError().isValid())
	{
		qDebug() << query.lastError();
		return false;
	}
	qDebug() << "Delete_Update success";
	return true;
}

/*******************************************************************************************
* �������ƣ�InsertQuery
* �������ܣ��������
* �����������1��insert��sql��䣻
* ���������bool
* ����ֵ  ���������
********************************************************************************************/
bool SqlOp::InsertQuery(QString insert)
{
	QSqlQuery query;
	query.exec(insert);

	if (query.lastError().isValid())
	{
		qDebug() << query.lastError();
		return false;
	}
	qDebug() << "insert success";
	return true;
}

/*******************************************************************************************
* �������ƣ�InsertQuery
* �������ܣ�������䣬���в���
* �����������1��insert��sql��䣻 ��2��bindValue����̬����
* ���������bool
* ����ֵ  ���������
********************************************************************************************/
bool SqlOp::InsertQuery(QString insert, QVector<QVariant> bindvalue)
{
	QSqlQuery query(GetDatabase());
	query.prepare(insert);
	for (int i = 0; i < bindvalue.size(); i++)
	{
		query.bindValue(i, bindvalue[i]);
	}
	query.exec();

	if (query.lastError().isValid())
	{
		qDebug() << query.lastError();
		return false;
	}
	qDebug() << "insert success";
	return true;
}


int SqlOp::ExportProjectDb(const QString &dbName, const QString &ID)
{
	QSqlDatabase exportdb = QSqlDatabase::addDatabase("QSQLITE", "export");
	exportdb.setDatabaseName(dbName);
	if (!exportdb.open()) {
		qDebug() << "Database Can't open!";
		return -1;
	}

	QSqlQuery query(exportdb);
	if (!query.exec("CREATE TABLE [MFL_DevInfo] ([DevID] CHAR(8) NOT NULL,[DevName] VARCHAR(25),[SysName] VARCHAR(50),[CheckCompany] VARCHAR(60),[CheckMan] VARCHAR(30),[ProductionDate] DATE,[SellDate] DATE,[HardwareVersion] VARCHAR(8),[SoftwareVersion] VARCHAR(8),[ChannelNumber] INTEGER,[SpaceLength] FLOAT,[StepLength] FLOAT,[DevWidth] FLOAT,[DevLength] FLOAT,[DevBackEndLength] FLOAT,[DevFrontEndLength] FLOAT,[DevWeight] FLOAT,[ServicePhone] VARCHAR(20),[Remark] VARCHAR(200),[ThresholdValue1] FLOAT,[ThresholdPer1] FLOAT,[ThresholdPer1Value] FLOAT,[ThresholdPer2] FLOAT,[ThresholdPer2Value] FLOAT,[ThresholdPer3] FLOAT,[ThresholdPer3Value] FLOAT,[ThresholdPer4] FLOAT,[ThresholdPer4Value] FLOAT,[Parameter1] FLOAT,[Parameter2] FLOAT,[Parameter3] FLOAT,[Parameter4] FLOAT,[Parameter5] FLOAT,[Channel1Factor] FLOAT DEFAULT 1,[Channel2Factor] FLOAT DEFAULT 1,[Channel3Factor] FLOAT DEFAULT 1,[Channel4Factor] FLOAT DEFAULT 1,[Channel5Factor] FLOAT DEFAULT 1,[Channel6Factor] FLOAT DEFAULT 1,[Channel7Factor] FLOAT DEFAULT 1,[Channel8Factor] FLOAT DEFAULT 1,[Channel9Factor] FLOAT DEFAULT 1,[Channel10Factor] FLOAT DEFAULT 1,[Channel11Factor] FLOAT DEFAULT 1,[Channel12Factor] FLOAT DEFAULT 1,[Channel13Factor] FLOAT DEFAULT 1,[Channel14Factor] FLOAT DEFAULT 1,[Channel15Factor] FLOAT DEFAULT 1,[Channel16Factor] FLOAT DEFAULT 1,[Channel17Factor] FLOAT DEFAULT 1,[Channel18Factor] FLOAT DEFAULT 1,[Channel19Factor] FLOAT DEFAULT 1,[Channel20Factor] FLOAT DEFAULT 1,[Channel21Factor] FLOAT DEFAULT 1,[Channel22Factor] FLOAT DEFAULT 1,[Channel23Factor] FLOAT DEFAULT 1,[Channel24Factor] FLOAT DEFAULT 1,[Channel25Factor] FLOAT DEFAULT 1,[Channel26Factor] FLOAT DEFAULT 1,[Channel27Factor] FLOAT DEFAULT 1,[Channel28Factor] FLOAT DEFAULT 1,[Channel29Factor] FLOAT DEFAULT 1,[Channel30Factor] FLOAT DEFAULT 1,[Channel31Factor] FLOAT DEFAULT 1,[Channel32Factor] FLOAT DEFAULT 1,[Channel33Factor] FLOAT DEFAULT 1,[Channel34Factor] FLOAT DEFAULT 1,[Channel35Factor] FLOAT DEFAULT 1,[Channel36Factor] FLOAT DEFAULT 1,CONSTRAINT[sqlite_autoindex_MFL_DevInfo_1] PRIMARY KEY([DevID])); "))
		qDebug() << "create  table MFL_DevInfo failed";
	if (!query.exec("CREATE TABLE MFL_DeAdjust (AdjustID             NUMERIC(6)                     not null,DevID                CHAR(8),AdjustTime           DATE,Remark               VARCHAR(200),ThresholdValue1      FLOAT,ThresholdPer1        FLOAT,ThresholdPer1X       FLOAT,ThresholdPer1Value   FLOAT,ThresholdPer2        FLOAT,ThresholdPer2X       FLOAT,ThresholdPer2Value   FLOAT,ThresholdPer3        FLOAT,ThresholdPer3X       FLOAT,ThresholdPer3Value   FLOAT,ThresholdPer4        FLOAT,ThresholdPer4X       FLOAT,ThresholdPer4Value   FLOAT,Parameter1           FLOAT,Parameter2           FLOAT,Parameter3           FLOAT,Parameter4           FLOAT,Parameter5           FLOAT,SteelThickness       INT,DisValue             INT,primary key (AdjustID),foreign key (DevID) references MFL_DevInfo (DevID) );"))
		qDebug() << "create  table MFL_DeAdjust failed";
	if (!query.exec("CREATE TABLE [MFL_ProjectInfo] (  [ProjectID] CHAR(36) NOT NULL,   [DevID] CHAR(8) NOT NULL,   [ProjectName] VARCHAR(50),   [CompanyName] VARCHAR(60),   [MFLAlert] FLOAT,   [EnvShape] VARCHAR(20),   [PointPosition] INTEGER,   [CoordinatesAutoGen] BOOL,   [EnvLength] FLOAT,   [EnvWidth] FLOAT,   [EnvArea] FLOAT,   [PlateNumber] INTEGER,   [EdgePlateNumber] INTEGER,   [EdgePlateWidth] FLOAT,   [DefectPlateNumber] INTEGER,   [CheckMan] VARCHAR(20),   [CreateTime] DATE,   [CheckTime] DATE,  [UsedYear] INTEGER,   [PlateThickness] FLOAT,   [CoatThickness] FLOAT,   [CoatStatus] VARCHAR(50),   [PlateMaterial] VARCHAR(50),   [StoreMaterial] VARCHAR(50),   [DefectArea20] FLOAT,   [DefectArea40] FLOAT,   [DefectArea60] FLOAT,  [DefectArea80] FLOAT,   [MaxDefectPercent] FLOAT,   [ProjectPic] [LONG VARBINARY],   [IsCompleted] BOOL,   [remark] VARCHAR(200),  CONSTRAINT [sqlite_autoindex_MFL_ProjectInfo_1] PRIMARY KEY ([ProjectID]));"))
		qDebug() << "create  table MFL_ProjectInfo failed";
	if (!query.exec("CREATE TABLE [MFL_PlateInfo] ([PlateID] CHAR(36) NOT NULL, [ProjectID] CHAR(36) REFERENCES [MFL_ProjectInfo]([ProjectID]), [RowNo] int, [ColumnNo] int, [PlateName] VARCHAR(50), [PointPosition] INTEGER, [PlateType] INTEGER, [PlateLength] FLOAT, [PlateWidth] FLOAT, [PlateLength2] FLOAT, [PlateWidth2] FLOAT, [XCoords] FLOAT, [YCoords] FLOAT, [CreateTime] DATE, [CheckTime] DATE, [DefectArea20] FLOAT DEFAULT 0, [DefectArea40] FLOAT DEFAULT 0, [DefectArea60] FLOAT DEFAULT 0, [DefectArea80] FLOAT DEFAULT 0, [MaxDefectPercent] FLOAT DEFAULT 0, [PlateArea] FLOAT DEFAULT 0, [ScanPercent] FLOAT DEFAULT 0, [IsDefect] BOOL DEFAULT '0', [PlatePic] [LONG VARBINARY], [Remark] VARCHAR(200), [DetectDirection] INT, CONSTRAINT [sqlite_autoindex_MFL_PlateInfo_1] PRIMARY KEY ([PlateID]));"))
		qDebug() << "create  table MFL_PlateInfo failed";
	if (!query.exec("CREATE TABLE [MFL_TrackInfo] (    [TrackID] CHAR(36) NOT NULL,     [PlateID] CHAR(36) REFERENCES [MFL_PlateInfo]([PlateID]),     [TrackRowNo] INT,         [TrackColumnNo] INT,      [XCoords] FLOAT,     [YCoords] FLOAT,     [CheckAngle] INTEGER DEFAULT 0,     [CheckDirection] INTEGER DEFAULT 0,     [TrackLength] FLOAT,     [TrackWidth] FLOAT,     [CreateTime] DATE,     [CheckTime] DATE,     [DefectArea20] FLOAT DEFAULT 0,     [DefectArea40] FLOAT DEFAULT 0,     [DefectArea60] FLOAT DEFAULT 0,     [DefectArea80] FLOAT DEFAULT 0,     [MaxDefectPercent] FLOAT DEFAULT 0,     [TrackPic] [LONG VARBINARY],     [Remark] VARCHAR(200),     [ChannelNumber] INTEGER,     [SpaceLength] FLOAT,     [StepLength] FLOAT,     CONSTRAINT [sqlite_autoindex_MFL_TrackInfo_1] PRIMARY KEY ([TrackID]));"))
		qDebug() << "create  table MFL_TrackInfo failed";
	if (!query.exec("CREATE TABLE MFL_TrackCheckRecord ( RecordID     CHAR(36)       not null, TrackID      CHAR(36), ChannelID    CHAR(3), CheckTime    DATE, XCoords      FLOAT, YCoords      FLOAT, CheckValue   FLOAT, WaveletValue FLOAT, DefectPercent        FLOAT   default 0, primary key (RecordID), foreign key (TrackID)       references MFL_TrackInfo (TrackID) );"))
		qDebug() << "create  table MFL_TrackCheckRecord failed";



	//��ѯ  MFL_ProjectInfo ��
	const int projectTableCounts = 32;
	QVector<QString> bindValue;
	bindValue.append(ID);
	QString query_projectinfo = "select * from MFL_ProjectInfo where ProjectID = ? ";
	QVector< QVector<QVariant> > projectinfo;
	projectinfo = SqlOp::SelectQuery2(query_projectinfo, projectTableCounts, bindValue);

	//��ѯ MFL_PlateInfo  ��
	const int plateTableCounts = 26;   //�ְ�������
	QString query_plateinfo = "select * from MFL_PlateInfo where ProjectID = ? ";
	QVector< QVector<QVariant> > plateinfo;
	plateinfo = SqlOp::SelectQuery2(query_plateinfo, plateTableCounts, bindValue);

	//��ѯMFL_TrackInfo ��
	const int trackInfoTableCounts = 22;   //�켣��Ϣ�������
	QString query_trackinfo = "select * from MFL_TrackInfo where PlateID in(select PlateID from MFL_PlateInfo where ProjectID = ?)";
	QVector< QVector<QVariant> > trackinfo;
	trackinfo = SqlOp::SelectQuery2(query_trackinfo, trackInfoTableCounts, bindValue);

	//��ѯMFL_TrackCheckRecord��
	const int trackRecordTableCounts = 9;
	QString query_trackrecord = "select * from MFL_TrackCheckRecord where TrackID in (select TrackID from MFL_TrackInfo where PlateID in(select PlateID from MFL_PlateInfo where ProjectID = ?))";
	QVector< QVector<QVariant> > trackrecord;
	trackrecord = SqlOp::SelectQuery2(query_trackrecord, trackRecordTableCounts, bindValue);
	exportdb.transaction();

	//�������ݿ����  MFL_ProjectInfo ��

	query.prepare("INSERT INTO MFL_ProjectInfo values(? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ?, ?, ?, ?  )");
	QVariantList *project = new QVariantList[projectTableCounts];
	for (int i = 0; i < projectinfo.size(); i++)
	{
		for (int j = 0; j < projectTableCounts; j++)
			project[j] << projectinfo[i][j];
	}
	for (int i = 0; i < projectTableCounts; i++)
	{
		query.addBindValue(project[i]);
	}
	if (!query.execBatch()) //�������������������������
		qDebug() << query.lastError();

	//�������ݿ����  MFL_PlateInfo ��
	query.prepare("INSERT INTO MFL_PlateInfo values(? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ?, ?, ?, ?, ?, ?, ? )");
	QVariantList *plate = new QVariantList[plateTableCounts];
	for (int i = 0; i < plateinfo.size(); i++)
	{
		for (int j = 0; j < plateTableCounts; j++)
			plate[j] << plateinfo[i][j];
	}
	for (int i = 0; i < plateTableCounts; i++)
	{
		query.addBindValue(plate[i]);
	}
	if (!query.execBatch()) //�������������������������
		qDebug() << query.lastError();

	//�������ݿ����  MFL_TrackInfo ��
	query.prepare("INSERT INTO MFL_TrackInfo values(? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ?, ?, ?)");
	QVariantList *track = new QVariantList[trackInfoTableCounts];
	for (int i = 0; i < trackinfo.size(); i++)
	{
		for (int j = 0; j < trackInfoTableCounts; j++)
			track[j] << trackinfo[i][j];
	}
	for (int i = 0; i < trackInfoTableCounts; i++)
	{
		query.addBindValue(track[i]);
	}
	if (!query.execBatch()) //�������������������������
		qDebug() << query.lastError();

	//�������ݿ����  MFL_TrackCheckRecord ��
	query.prepare("INSERT INTO MFL_TrackCheckRecord values(? , ? , ? , ? , ? , ? , ? , ? , ? )");
	QVariantList *trackcheck = new QVariantList[trackRecordTableCounts];
	for (int i = 0; i < trackrecord.size(); i++)
	{
		for (int j = 0; j < trackRecordTableCounts; j++)
			trackcheck[j] << trackrecord[i][j];
	}
	for (int i = 0; i < trackRecordTableCounts; i++)
	{
		query.addBindValue(trackcheck[i]);
	}
	if (!query.execBatch()) //�������������������������
		qDebug() << query.lastError();

	bool result = exportdb.commit();
	if (result)
	{
		return 0;
	}
	else
	{
		return -2;
	}
}

/*******************************************************************************************
* �������ƣ�ImportProjectDbInfo
* �������ܣ����ⲿ�����ļ�.db�е�����Ŀ��Ϣ
* �����������1���ⲿ�����ļ���·����
* ���������QVector< QVector <QVariant>> ����projectInfo,
* ����ֵ  ���������
********************************************************************************************/
QVector< QVector <QVariant>> SqlOp::ImportProjectDbInfo(const QString &dbPath)
{
	QSqlDatabase importDB = QSqlDatabase::addDatabase("QSQLITE", "importDB");
	importDB.setDatabaseName(dbPath);
	if (!importDB.open()) {
		qDebug() << "Database Can't open!";
	}

	QString queryProject = "SELECT ProjectID FROM MFL_ProjectInfo";
	QVector< QVector <QVariant> > queryResult = SelectQuery3(queryProject, 1, importDB);
	QString projectID = queryResult[0][0].toString();

	//��ѯ  MFL_ProjectInfo ��
	QString query_projectinfo = QObject::tr("select ProjectName,CompanyName,CheckMan,MFLAlert,EnvLength,EdgePlateNumber,EdgePlateWidth,UsedYear,CoatStatus,PlateMaterial,PlateThickness,StoreMaterial,CoatThickness,ProjectID from MFL_ProjectInfo where ProjectID ='%1' ").arg(projectID);
	QVector< QVector<QVariant> > projectinfo;
	projectinfo = SelectQuery3(query_projectinfo, 14, importDB);


	return projectinfo;
}
/*******************************************************************************************
* �������ƣ�ImportProjectDb
* �������ܣ����ⲿ�����ļ�.db�е��뱾�����ݿ�
* �����������1���ⲿ�����ļ���·����
* ���������void
* ����ֵ  ��
********************************************************************************************/
int SqlOp::ImportProjectDb(const QString &dbPath)
{
	/*-----------------���ⲿ�����ļ�db�л�ȡ����-----------------------------*/
	QSqlDatabase importDB = QSqlDatabase::addDatabase("QSQLITE", "importDB");
	importDB.setDatabaseName(dbPath);
	if (!importDB.open()) {
		qDebug() << "Database Can't open!";
	}

	QString queryProject = "SELECT ProjectID FROM MFL_ProjectInfo";
	QVector< QVector <QVariant> > queryResult = SelectQuery3(queryProject, 1, importDB);
	QString projectID = queryResult[0][0].toString();

	//��ѯ  MFL_ProjectInfo ��
	QString query_projectinfo = QObject::tr("select * from MFL_ProjectInfo where ProjectID = '%1' ").arg(projectID);
	QVector< QVector<QVariant> > projectinfo;
	projectinfo = SelectQuery3(query_projectinfo, 32, importDB);


	//��ѯ MFL_PlateInfo  ��
	QString query_plateinfo = QObject::tr("select * from MFL_PlateInfo where ProjectID = '%1' ").arg(projectID);
	QVector< QVector<QVariant> > plateinfo;
	plateinfo = SelectQuery3(query_plateinfo, 24, importDB);

	//��ѯMFL_TrackInfo ��
	QString query_trackinfo = QObject::tr("select * from MFL_TrackInfo where PlateID in(select PlateID from MFL_PlateInfo where ProjectID = '%1')").arg(projectID);
	QVector< QVector<QVariant> > trackinfo;
	trackinfo = SelectQuery3(query_trackinfo, 22, importDB);

	//��ѯMFL_TrackCheckRecord��
	QString query_trackrecord = QObject::tr("select * from MFL_TrackCheckRecord where TrackID in (select TrackID from MFL_TrackInfo where PlateID in(select PlateID from MFL_PlateInfo where ProjectID = '%1'))").arg(projectID);
	QVector< QVector<QVariant> > trackrecord;
	trackrecord = SelectQuery3(query_trackrecord, 9, importDB);


	/*-----------------�򱾵����ݲ�������-----------------------------*/
	QSqlDatabase dbSqlOp = QSqlDatabase::database();
	QSqlQuery query(dbSqlOp);
	dbSqlOp.transaction();

	//�������ݿ����  MFL_ProjectInfo ��
	query.prepare("INSERT INTO MFL_ProjectInfo values(? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ?, ?, ? , ?  )");
	QVariantList *project = new QVariantList[32];
	for (int i = 0; i < projectinfo.size(); i++)
	{
		for (int j = 0; j < 32; j++)
			project[j] << projectinfo[i][j];
	}
	for (int i = 0; i < 32; i++)
	{
		if (i == 30)
			project[i][0] = 0;		//�������Ŀ����Ϊδ���
		query.addBindValue(project[i]);
	}
	if (!query.execBatch()) //�������������������������
		qDebug() << query.lastError();

	//�������ݿ����  MFL_PlateInfo ��
	query.prepare("INSERT INTO MFL_PlateInfo values(? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ?, ?, ?, ?, ? )");
	QVariantList *plate = new QVariantList[24];
	for (int i = 0; i < plateinfo.size(); i++)
	{
		for (int j = 0; j < 24; j++)
			plate[j] << plateinfo[i][j];
	}
	for (int i = 0; i < 24; i++)
	{
		query.addBindValue(plate[i]);
	}
	if (!query.execBatch()) //�������������������������
		qDebug() << query.lastError();

	//�������ݿ����  MFL_TrackInfo ��
	query.prepare("INSERT INTO MFL_TrackInfo values(? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ?, ?, ?)");
	QVariantList *track = new QVariantList[22];
	for (int i = 0; i < trackinfo.size(); i++)
	{
		for (int j = 0; j < 22; j++)
			track[j] << trackinfo[i][j];
	}
	for (int i = 0; i < 22; i++)
	{
		query.addBindValue(track[i]);
	}
	if (!query.execBatch()) //�������������������������
		qDebug() << query.lastError();

	//�������ݿ����  MFL_TrackCheckRecord ��
	query.prepare("INSERT INTO MFL_TrackCheckRecord values(? , ? , ? , ? , ? , ? , ? , ? , ? )");
	QVariantList *trackcheck = new QVariantList[9];
	for (int i = 0; i < trackrecord.size(); i++)
	{
		for (int j = 0; j < 9; j++)
			trackcheck[j] << trackrecord[i][j];
	}
	for (int i = 0; i < 9; i++)
	{
		query.addBindValue(trackcheck[i]);
	}
	if (!query.execBatch()) //�������������������������
		qDebug() << query.lastError();

	bool result = dbSqlOp.commit();
	if (result)
	{
		return 0;
	}
	else
	{
		return -2;
	}
	return 0;
}


QSqlDatabase& SqlOp::GetDatabase()
{
	QSqlDatabase db = QSqlDatabase::database("connection1", true);
	QSqlDatabase &db1 = db;
	return db1;
}
