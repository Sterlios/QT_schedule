#include "mycharts.h"
#include <QtWidgets/QApplication>
#include "Calcul.h"
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qlayout.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QWidget Main_Window;
	Calcul fData("test", "result.txt");
	int size = fData.GetSize();
	int* data = new int[fData.GetSize()];
	data = fData.GetData();
	MyCharts w(data, size);
	double m = fData.GetMeanValue();
	double s = fData.GetStandartDeviation();
	QLabel *label = new QLabel;
	label->setText("M(x) = " + QString::number(m) + "\nS(x) = " + QString::number(s));
	QVBoxLayout *vbl = new QVBoxLayout(&Main_Window);
	vbl->addWidget(w.chartView);
	vbl->addWidget(label);	
	Main_Window.show();
	return a.exec();
}
