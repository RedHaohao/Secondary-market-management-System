#include "market.h"

#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	/*
	�������ݿ�
	*/
	SqlOp::CreateConnection();



	market w;
	w.show();


	return a.exec();
}

