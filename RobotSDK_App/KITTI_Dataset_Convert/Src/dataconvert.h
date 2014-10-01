#ifndef DATACONVERT_H
#define DATACONVERT_H

#include <QtWidgets/QMainWindow>
#include "ui_dataconvert.h"

#include<qfiledialog.h>
#include<qfileinfo.h>
#include<qfile.h>
#include<qtextstream.h>
#include<qthread.h>

struct VelodynePoint
{
	float x;
	float y;
	float z;
	float r;
};

class DataConvert : public QMainWindow
{
	Q_OBJECT

public:
	DataConvert(QWidget *parent = 0);
	~DataConvert();

private:
	Ui::DataConvertClass ui;
	QThread thread;
public slots:
	void browseVelodyneBinSlot();
	void browseVelodyneASCIISlot();
	void convertBin2ASCIISlot();
};

#endif // DATACONVERT_H
