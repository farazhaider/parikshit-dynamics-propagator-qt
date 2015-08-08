#include "qbiplot.h"
#include "ui_qbiplot.h"

QBiPlot::QBiPlot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QBiPlot)
{
    ui->setupUi(this);
}

QBiPlot::~QBiPlot()
{
    delete ui;
}



void QBiPlot::plot_data(QVector<double> &time,QVector<double> &a,QVector<double> &x,QVector<double> &y,QVector<double> &z,double &final_time)
{
        //ui->qbiPlot->xAxis->setRange(1,final_time);
        //ui->qbiPlot->yAxis->setRange(-1,1);
        ui->qbiPlot->addGraph();
        ui->qbiPlot->addGraph();
        ui->qbiPlot->addGraph();
        ui->qbiPlot->addGraph();
        ui->qbiPlot->graph(0)->setData(time,a);
        ui->qbiPlot->graph(1)->setData(time,x);
        ui->qbiPlot->graph(2)->setData(time,y);
        ui->qbiPlot->graph(3)->setData(time,z);
        ui->qbiPlot->graph(0)->setPen(QPen(Qt::magenta));
        ui->qbiPlot->graph(1)->setPen(QPen(Qt::red));
        ui->qbiPlot->graph(2)->setPen(QPen(Qt::green));
        ui->qbiPlot->graph(3)->setPen(QPen(Qt::blue));
        ui->qbiPlot->xAxis->setLabel("Time(sec)");
        ui->qbiPlot->rescaleAxes();
        ui->qbiPlot->setInteractions(QCP::iRangeDrag |QCP::iRangeZoom | QCP::iSelectPlottables);
}
