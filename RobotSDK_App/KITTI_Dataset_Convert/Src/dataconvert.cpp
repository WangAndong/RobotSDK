#include "dataconvert.h"

DataConvert::DataConvert(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.browsebin,SIGNAL(clicked()),this,SLOT(browseVelodyneBinSlot()));
	connect(ui.browseascii,SIGNAL(clicked()),this,SLOT(browseVelodyneASCIISlot()));
	connect(ui.bin2asciiconvert,SIGNAL(clicked()),this,SLOT(convertBin2ASCIISlot()));
	this->moveToThread(&thread);
}

DataConvert::~DataConvert()
{
	thread.exit();
	thread.wait();
}

void DataConvert::browseVelodyneBinSlot()
{
	QString dir=QFileDialog::getExistingDirectory(this,"Directory of Velodyne Bin Files");
	if(dir.size()>0)
	{
		ui.velodynebin->setText(dir);
	}
}

void DataConvert::browseVelodyneASCIISlot()
{
	QString dir=QFileDialog::getExistingDirectory(this,"Directory of Velodyne ASCII Files");
	if(dir.size()>0)
	{
		ui.velodyneascii->setText(dir);
	}
}

void DataConvert::convertBin2ASCIISlot()
{
	QDir bindir(ui.velodynebin->text());
	QStringList filters;
    filters << "*.bin";
    bindir.setNameFilters(filters);
	QFileInfoList binlist=bindir.entryInfoList(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
	int i,n=binlist.size();
	ui.bin2asciiprogress->setRange(0,n);
	ui.bin2asciiprogress->setValue(0);
	for(i=0;i<n;i++)
	{
		QFile infile(binlist.at(i).absoluteFilePath());
		if(!infile.open(QIODevice::ReadOnly))
		{
			continue;
		}
		QString outfilename=QString("%1/%2.txt").arg(ui.velodyneascii->text()).arg(binlist.at(i).baseName());
		QFile outfile(outfilename);
		if(!outfile.open(QIODevice::WriteOnly|QIODevice::Text))
		{
			infile.close();
			continue;
		}
		QTextStream stream(&outfile);
		int pointnum=infile.size()/sizeof(VelodynePoint);
		QVector<VelodynePoint> points(pointnum);
		memcpy((char *)(points.data()),infile.readAll().data(),infile.size());
		infile.close();
		int j,m=points.size();
		for(j=0;j<m;j++)
		{
			stream<<points[j].x<<" ";
			stream<<points[j].y<<" ";
			stream<<points[j].z<<" ";
			stream<<points[j].r<<" ";
			stream<<0<<"\n";
		}
		outfile.close();
		ui.bin2asciiprogress->setValue(i+1);
	}
}