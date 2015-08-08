#include "qerror_angle.h"
#include "ui_qerror_angle.h"

qerror_angle::qerror_angle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::qerror_angle)
{
    ui->setupUi(this);
}

qerror_angle::~qerror_angle()
{
    delete ui;
}


void qerror_angle::plot_data(QVector<double> &time, QVector<double> &x, QVector<double> &y, QVector<double> &z, double &final_time){
    ui->qerror_angle_plot->addGraph();
    ui->qerror_angle_plot->addGraph();
    ui->qerror_angle_plot->addGraph();
    ui->qerror_angle_plot->graph(0)->setData(time,x);
    ui->qerror_angle_plot->graph(1)->setData(time,y);
    ui->qerror_angle_plot->graph(2)->setData(time,z);
    ui->qerror_angle_plot->graph(0)->setPen(QPen(Qt::red));
    ui->qerror_angle_plot->graph(1)->setPen(QPen(Qt::green));
    ui->qerror_angle_plot->graph(2)->setPen(QPen(Qt::blue));
    ui->qerror_angle_plot->xAxis->setLabel("Time(sec)");
    ui->qerror_angle_plot->yAxis->setLabel("Angle(deg)");
    ui->qerror_angle_plot->rescaleAxes();
    ui->qerror_angle_plot->setInteractions(QCP::iRangeDrag |QCP::iRangeZoom | QCP::iSelectPlottables);
}
