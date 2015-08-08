#include "radiusplot.h"
#include "ui_radiusplot.h"

RadiusPlot::RadiusPlot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RadiusPlot)
{
    ui->setupUi(this);
}

RadiusPlot::~RadiusPlot()
{
    delete ui;
}



void RadiusPlot::plot_data(QVector<double> &time,QVector<double> &x,QVector<double> &y,QVector<double> &z,double &final_time)
{
   // ui->rPlot->xAxis->setRange(1,final_time);
   // ui->rPlot->yAxis->setRange(-6000,6000);
    ui->rPlot->addGraph();
    ui->rPlot->addGraph();
    ui->rPlot->addGraph();
    ui->rPlot->graph(0)->setData(time,x);
    ui->rPlot->graph(1)->setData(time,y);
    ui->rPlot->graph(2)->setData(time,z);
    ui->rPlot->graph(0)->setPen(QPen(Qt::red));
    ui->rPlot->graph(1)->setPen(QPen(Qt::green));
    ui->rPlot->graph(2)->setPen(QPen(Qt::blue));
    ui->rPlot->rescaleAxes();
    ui->rPlot->setInteractions(QCP::iRangeDrag |QCP::iRangeZoom | QCP::iSelectPlottables);
}
