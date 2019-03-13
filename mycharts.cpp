#include "mycharts.h"

MyCharts::MyCharts(int* data, int size, QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	SetData(data, size);
}

void MyCharts::SetData(int * myData, int mySize)
{
	size = mySize;
	data = new int[size];
	max = 0;
	for (int i = 0; i < size; i++) {
		data[i] = myData[i];
		if (data[i] > max) {
			max = data[i];
		}
	}
	PaintGraph();
	SetValueAxises();
}

void MyCharts::SetValueAxises()
{
	chrt = new QChart();
	chrt->legend()->hide();
	chrt->resize(400, 300);
	chrt->addSeries(series);
	chrt->createDefaultAxes();
	chrt->setMaximumSize(400, 250);
	chrt->setTitle("Data Chart"); 
	chartView = new QChartView(chrt);
}

void MyCharts::PaintGraph()
{
	series = new QLineSeries[size];
	for (int i(0); i < size; i++)
		series->append(i, data[i]);
}
