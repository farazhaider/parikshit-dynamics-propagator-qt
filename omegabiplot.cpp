#include "omegabiplot.h"
#include "ui_omegabiplot.h"

OmegaBiPlot::OmegaBiPlot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OmegaBiPlot)
{
    ui->setupUi(this);
}

OmegaBiPlot::~OmegaBiPlot()
{
    delete ui;
}


void OmegaBiPlot::plot_data(QVector<double> &time,QVector<double> &x,QVector<double> &y,QVector<double> &z,double &final_time)
{

    ui->wbiPlot->addGraph();
    ui->wbiPlot->addGraph();
    ui->wbiPlot->addGraph();
    ui->wbiPlot->graph(0)->setData(time,x);
    ui->wbiPlot->graph(1)->setData(time,y);
    ui->wbiPlot->graph(2)->setData(time,z);
    ui->wbiPlot->graph(0)->setPen(QPen(Qt::red));
    ui->wbiPlot->graph(1)->setPen(QPen(Qt::green));
    ui->wbiPlot->graph(2)->setPen(QPen(Qt::blue));
    ui->wbiPlot->xAxis->setLabel("Time(sec)");
    ui->wbiPlot->yAxis->setLabel("Angular Velocity(deg/sec)");
    ui->wbiPlot->rescaleAxes();
    ui->wbiPlot->setInteractions(QCP::iRangeDrag |QCP::iRangeZoom | QCP::iSelectPlottables);
}
