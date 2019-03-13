#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_mycharts.h"
#include <QtCore/QtMath>
#include <QtGui>

#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>

QT_CHARTS_USE_NAMESPACE

using namespace QtCharts;

class MyCharts : public QMainWindow
{
	Q_OBJECT

public:
	MyCharts(int* data, int size, QWidget *parent = Q_NULLPTR);
	void SetData(int* data, int size);
	void SetValueAxises();
	void PaintGraph();
	QChartView *chartView;
private:
	int max;
	int* data;
	int size;
	Ui::MyChartsClass ui;
	QLineSeries *series;
	QChart *chrt;
};
