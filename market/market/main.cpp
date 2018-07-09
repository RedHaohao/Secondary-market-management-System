#include "market.h"

#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	/*
	连接数据库
	*/
	SqlOp::CreateConnection();



	market w;
	w.show();


	return a.exec();
}

