#include "omegaerrorplot.h"
#include "ui_omegaerrorplot.h"

OmegaErrorPlot::OmegaErrorPlot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OmegaErrorPlot)
{
    ui->setupUi(this);
}

OmegaErrorPlot::~OmegaErrorPlot()
{
    delete ui;
}


void OmegaErrorPlot::plot_data(QVector<double> &time,QVector<double> &x,QVector<double> &y,QVector<double> &z,double &final_time)
{

    ui->werrPlot->addGraph();
    ui->werrPlot->addGraph();
    ui->werrPlot->addGraph();
    ui->werrPlot->graph(0)->setData(time,x);
    ui->werrPlot->graph(1)->setData(time,y);
    ui->werrPlot->graph(2)->setData(time,z);
    ui->werrPlot->graph(0)->setPen(QPen(Qt::red));
    ui->werrPlot->graph(1)->setPen(QPen(Qt::green));
    ui->werrPlot->graph(2)->setPen(QPen(Qt::blue));
    ui->werrPlot->xAxis->setLabel("Time(sec)");
    ui->werrPlot->yAxis->setLabel("Angular Velocity(deg/sec)");
    ui->werrPlot->rescaleAxes();
    ui->werrPlot->setInteractions(QCP::iRangeDrag |QCP::iRangeZoom | QCP::iSelectPlottables);
}
