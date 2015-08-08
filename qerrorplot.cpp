#include "qerrorplot.h"
#include "ui_qerrorplot.h"

QErrorPlot::QErrorPlot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QErrorPlot)
{
    ui->setupUi(this);
}

QErrorPlot::~QErrorPlot()
{
    delete ui;
}

void QErrorPlot::plot_data(QVector<double> &time,QVector<double> &a,QVector<double> &x,QVector<double> &y,QVector<double> &z,double &final_time)
{
   // ui->qerrPlot->xAxis->setRange(1,final_time);
   // ui->qerrPlot->yAxis->setRange(-1,1);
    ui->qerrPlot->addGraph();
    ui->qerrPlot->addGraph();
    ui->qerrPlot->addGraph();
    ui->qerrPlot->addGraph();
    ui->qerrPlot->graph(0)->setData(time,a);
    ui->qerrPlot->graph(1)->setData(time,x);
    ui->qerrPlot->graph(2)->setData(time,y);
    ui->qerrPlot->graph(3)->setData(time,z);
    ui->qerrPlot->graph(0)->setPen(QPen(Qt::magenta));
    ui->qerrPlot->graph(1)->setPen(QPen(Qt::red));
    ui->qerrPlot->graph(2)->setPen(QPen(Qt::green));
    ui->qerrPlot->graph(3)->setPen(QPen(Qt::blue));
    ui->qerrPlot->xAxis->setLabel("Time(sec)");
    ui->qerrPlot->yAxis->setLabel("Quaternion");
    ui->qerrPlot->rescaleAxes();
    ui->qerrPlot->setInteractions(QCP::iRangeDrag |QCP::iRangeZoom | QCP::iSelectPlottables);
}
