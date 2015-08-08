#include "qreferenceplot.h"
#include "ui_qreferenceplot.h"

QReferencePlot::QReferencePlot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QReferencePlot)
{
    ui->setupUi(this);
}

QReferencePlot::~QReferencePlot()
{
    delete ui;
}


void QReferencePlot::plot_data(QVector<double> &time,QVector<double> &a,QVector<double> &x,QVector<double> &y,QVector<double> &z,double &final_time)
{
    ui->qrefPlot->addGraph();
    ui->qrefPlot->addGraph();
    ui->qrefPlot->addGraph();
    ui->qrefPlot->addGraph();
    ui->qrefPlot->graph(0)->setData(time,a);
    ui->qrefPlot->graph(1)->setData(time,x);
    ui->qrefPlot->graph(2)->setData(time,y);
    ui->qrefPlot->graph(3)->setData(time,z);
    ui->qrefPlot->graph(0)->setPen(QPen(Qt::magenta));
    ui->qrefPlot->graph(1)->setPen(QPen(Qt::red));
    ui->qrefPlot->graph(2)->setPen(QPen(Qt::green));
    ui->qrefPlot->graph(3)->setPen(QPen(Qt::blue));
    ui->qrefPlot->xAxis->setLabel("Time(sec)");
    ui->qrefPlot->rescaleAxes();
    ui->qrefPlot->setInteractions(QCP::iRangeDrag |QCP::iRangeZoom | QCP::iSelectPlottables);
}
