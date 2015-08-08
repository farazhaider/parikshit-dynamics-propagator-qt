#include "velocityplot.h"
#include "ui_velocityplot.h"
#include "qcustomplot.h"

VelocityPlot::VelocityPlot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VelocityPlot)
{

    ui->setupUi(this); 
}

VelocityPlot::~VelocityPlot()
{
    delete ui;
}


void VelocityPlot::plot_data(QVector<double> &time,QVector<double> &x,QVector<double> &y,QVector<double> &z,double &final_time)
{
   // ui->vPlot->xAxis->setRange(1,final_time);
   // ui->vPlot->yAxis->setRange(-8,8);
    ui->vPlot->addGraph();
    ui->vPlot->addGraph();
    ui->vPlot->addGraph();
    ui->vPlot->graph(0)->setData(time,x);
    ui->vPlot->graph(1)->setData(time,y);
    ui->vPlot->graph(2)->setData(time,z);
    ui->vPlot->graph(0)->setPen(QPen(Qt::red));
    ui->vPlot->graph(1)->setPen(QPen(Qt::green));
    ui->vPlot->graph(2)->setPen(QPen(Qt::blue));
    ui->vPlot->rescaleAxes();
    ui->vPlot->setInteractions(QCP::iRangeDrag |QCP::iRangeZoom | QCP::iSelectPlottables);
}

