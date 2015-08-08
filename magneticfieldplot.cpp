#include "magneticfieldplot.h"
#include "ui_magneticfieldplot.h"

MagneticFieldPlot::MagneticFieldPlot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MagneticFieldPlot)
{
    ui->setupUi(this);
}

MagneticFieldPlot::~MagneticFieldPlot()
{
    delete ui;
}


void MagneticFieldPlot::plot_data(QVector<double> &time,QVector<double> &x,QVector<double> &y,QVector<double> &z,double &final_time)
{
   ui->magnetic_field_Plot->addGraph();
   ui->magnetic_field_Plot->addGraph();
   ui->magnetic_field_Plot->addGraph();
   ui->magnetic_field_Plot->graph(0)->setData(time,x);
   ui->magnetic_field_Plot->graph(1)->setData(time,y);
   ui->magnetic_field_Plot->graph(2)->setData(time,z);
   ui->magnetic_field_Plot->graph(0)->setPen(QPen(Qt::red));
   ui->magnetic_field_Plot->graph(1)->setPen(QPen(Qt::green));
   ui->magnetic_field_Plot->graph(2)->setPen(QPen(Qt::blue));
   ui->magnetic_field_Plot->rescaleAxes();
   ui->magnetic_field_Plot->setInteractions(QCP::iRangeDrag |QCP::iRangeZoom | QCP::iSelectPlottables);
}
