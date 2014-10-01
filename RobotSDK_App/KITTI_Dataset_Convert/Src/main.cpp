#include "dataconvert.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	DataConvert w;
	w.show();
	return a.exec();
}
