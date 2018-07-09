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
* 函数名称：CreateConnection
* 函数介绍：连接数据库
* 输入参数：（1）HostName：数据库网络地址； （2）DatabaseName：数据库名称； （3）UserName：用户名 ；（4）Password：密码
* 输出参数：无
* 返回值  ：无
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
* 函数名称：CloseConnection
* 函数介绍：关闭数据库
* 输入参数：无
* 输出参数：无
* 返回值  ：无
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
* 函数名称：SelectQuery
* 函数介绍：查询语句，返回的数据为字符串形式
* 输入参数：（1）select：sql语句 （2）num：查询的列数
* 输出参数：result
* 返回值  ：查询结果
********************************************************************************************/
QVector< QVector <QString> > SqlOp::SelectQuery(QString select, int num)
{
	QVector< QVector <QString> >  result;   //存放查询结果

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
* 函数名称：SelectQuery
* 函数介绍：带动态参数，查询语句，返回的数据为字符串形式
* 输入参数：（1）select：sql语句 （2）num：查询的列数 （3）bindValue：动态参数集合
* 输出参数：result
* 返回值  ：查询结果
********************************************************************************************/
QVector< QVector <QString> > SqlOp::SelectQuery(QString select, int num, QVector<QString> bindValue)
{
	QVector< QVector <QString> >  result;   //存放查询结果
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
* 函数名称：SelectQuery2
* 函数介绍：查询语句，返回的数据为可变类型形式
* 输入参数：（1）select：sql语句 （2）num：查询的列数
* 输出参数：result
* 返回值  ：查询结果
********************************************************************************************/
QVector< QVector <QVariant> > SqlOp::SelectQuery2(QString select, int num)
{
	QVector< QVector <QVariant> >  result;   //存放查询结果
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
* 函数名称：SelectQuery2
* 函数介绍：带动态参数，查询语句，返回的数据为可变类型形式
* 输入参数：（1）select：sql语句 （2）num：查询的列数 （3）bindValue：动态参数集合
* 输出参数：result
* 返回值  ：查询结果
********************************************************************************************/
QVector< QVector <QVariant> > SqlOp::SelectQuery2(QString select, int num, QVector<QString> bindValue)
{
	QVector< QVector <QVariant> >  result;   //存放查询结果
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
* 函数名称：SelectQuery3
* 函数介绍：查询语句，返回的数据为可变类型形式
* 输入参数：（1）select：sql语句 （2）num：查询的列数 （3）指定数据库查询
* 输出参数：result
* 返回值  ：查询结果
********************************************************************************************/
QVector< QVector <QVariant> > SqlOp::SelectQuery3(QString select, int num, QSqlDatabase qSqlDB)
{
	QVector< QVector <QVariant> >  result;   //存放查询结果
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
* 函数名称：Delete_UpdateQuery
* 函数介绍：删除或者更新语句
* 输入参数：（1）del：sql语句
* 输出参数：bool
* 返回值  ：操作结果
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
* 函数名称：Delete_UpdateQuery
* 函数介绍：带动态参数，删除或者更新语句
* 输入参数：（1）del：sql语句；（2）binfValue：动态参数集合
* 输出参数：bool
* 返回值  ：操作结果
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
* 函数名称：InsertQuery
* 函数介绍：插入语句
* 输入参数：（1）insert：sql语句；
* 输出参数：bool
* 返回值  ：操作结果
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
* 函数名称：InsertQuery
* 函数介绍：插入语句，带有参数
* 输入参数：（1）insert：sql语句； （2）bindValue：动态参数
* 输出参数：bool
* 返回值  ：操作结果
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



	//查询  MFL_ProjectInfo 表
	const int projectTableCounts = 32;
	QVector<QString> bindValue;
	bindValue.append(ID);
	QString query_projectinfo = "select * from MFL_ProjectInfo where ProjectID = ? ";
	QVector< QVector<QVariant> > projectinfo;
	projectinfo = SqlOp::SelectQuery2(query_projectinfo, projectTableCounts, bindValue);

	//查询 MFL_PlateInfo  表
	const int plateTableCounts = 26;   //钢板表的列数
	QString query_plateinfo = "select * from MFL_PlateInfo where ProjectID = ? ";
	QVector< QVector<QVariant> > plateinfo;
	plateinfo = SqlOp::SelectQuery2(query_plateinfo, plateTableCounts, bindValue);

	//查询MFL_TrackInfo 表
	const int trackInfoTableCounts = 22;   //轨迹信息表的列数
	QString query_trackinfo = "select * from MFL_TrackInfo where PlateID in(select PlateID from MFL_PlateInfo where ProjectID = ?)";
	QVector< QVector<QVariant> > trackinfo;
	trackinfo = SqlOp::SelectQuery2(query_trackinfo, trackInfoTableCounts, bindValue);

	//查询MFL_TrackCheckRecord表
	const int trackRecordTableCounts = 9;
	QString query_trackrecord = "select * from MFL_TrackCheckRecord where TrackID in (select TrackID from MFL_TrackInfo where PlateID in(select PlateID from MFL_PlateInfo where ProjectID = ?))";
	QVector< QVector<QVariant> > trackrecord;
	trackrecord = SqlOp::SelectQuery2(query_trackrecord, trackRecordTableCounts, bindValue);
	exportdb.transaction();

	//往新数据库插入  MFL_ProjectInfo 表

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
	if (!query.execBatch()) //进行批处理，如果出错就输出错误
		qDebug() << query.lastError();

	//往新数据库插入  MFL_PlateInfo 表
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
	if (!query.execBatch()) //进行批处理，如果出错就输出错误
		qDebug() << query.lastError();

	//往新数据库插入  MFL_TrackInfo 表
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
	if (!query.execBatch()) //进行批处理，如果出错就输出错误
		qDebug() << query.lastError();

	//往新数据库插入  MFL_TrackCheckRecord 表
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
	if (!query.execBatch()) //进行批处理，如果出错就输出错误
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
* 函数名称：ImportProjectDbInfo
* 函数介绍：从外部数据文件.db中导入项目信息
* 输入参数：（1）外部数据文件的路径；
* 输出参数：QVector< QVector <QVariant>> 返回projectInfo,
* 返回值  ：操作结果
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

	//查询  MFL_ProjectInfo 表
	QString query_projectinfo = QObject::tr("select ProjectName,CompanyName,CheckMan,MFLAlert,EnvLength,EdgePlateNumber,EdgePlateWidth,UsedYear,CoatStatus,PlateMaterial,PlateThickness,StoreMaterial,CoatThickness,ProjectID from MFL_ProjectInfo where ProjectID ='%1' ").arg(projectID);
	QVector< QVector<QVariant> > projectinfo;
	projectinfo = SelectQuery3(query_projectinfo, 14, importDB);


	return projectinfo;
}
/*******************************************************************************************
* 函数名称：ImportProjectDb
* 函数介绍：将外部数据文件.db中导入本地数据库
* 输入参数：（1）外部数据文件的路径；
* 输出参数：void
* 返回值  ：
********************************************************************************************/
int SqlOp::ImportProjectDb(const QString &dbPath)
{
	/*-----------------从外部数据文件db中获取数据-----------------------------*/
	QSqlDatabase importDB = QSqlDatabase::addDatabase("QSQLITE", "importDB");
	importDB.setDatabaseName(dbPath);
	if (!importDB.open()) {
		qDebug() << "Database Can't open!";
	}

	QString queryProject = "SELECT ProjectID FROM MFL_ProjectInfo";
	QVector< QVector <QVariant> > queryResult = SelectQuery3(queryProject, 1, importDB);
	QString projectID = queryResult[0][0].toString();

	//查询  MFL_ProjectInfo 表
	QString query_projectinfo = QObject::tr("select * from MFL_ProjectInfo where ProjectID = '%1' ").arg(projectID);
	QVector< QVector<QVariant> > projectinfo;
	projectinfo = SelectQuery3(query_projectinfo, 32, importDB);


	//查询 MFL_PlateInfo  表
	QString query_plateinfo = QObject::tr("select * from MFL_PlateInfo where ProjectID = '%1' ").arg(projectID);
	QVector< QVector<QVariant> > plateinfo;
	plateinfo = SelectQuery3(query_plateinfo, 24, importDB);

	//查询MFL_TrackInfo 表
	QString query_trackinfo = QObject::tr("select * from MFL_TrackInfo where PlateID in(select PlateID from MFL_PlateInfo where ProjectID = '%1')").arg(projectID);
	QVector< QVector<QVariant> > trackinfo;
	trackinfo = SelectQuery3(query_trackinfo, 22, importDB);

	//查询MFL_TrackCheckRecord表
	QString query_trackrecord = QObject::tr("select * from MFL_TrackCheckRecord where TrackID in (select TrackID from MFL_TrackInfo where PlateID in(select PlateID from MFL_PlateInfo where ProjectID = '%1'))").arg(projectID);
	QVector< QVector<QVariant> > trackrecord;
	trackrecord = SelectQuery3(query_trackrecord, 9, importDB);


	/*-----------------向本地数据插入数据-----------------------------*/
	QSqlDatabase dbSqlOp = QSqlDatabase::database();
	QSqlQuery query(dbSqlOp);
	dbSqlOp.transaction();

	//往新数据库插入  MFL_ProjectInfo 表
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
			project[i][0] = 0;		//导入的项目设置为未完成
		query.addBindValue(project[i]);
	}
	if (!query.execBatch()) //进行批处理，如果出错就输出错误
		qDebug() << query.lastError();

	//往新数据库插入  MFL_PlateInfo 表
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
	if (!query.execBatch()) //进行批处理，如果出错就输出错误
		qDebug() << query.lastError();

	//往新数据库插入  MFL_TrackInfo 表
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
	if (!query.execBatch()) //进行批处理，如果出错就输出错误
		qDebug() << query.lastError();

	//往新数据库插入  MFL_TrackCheckRecord 表
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
	if (!query.execBatch()) //进行批处理，如果出错就输出错误
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
