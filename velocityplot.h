#ifndef VELOCITYPLOT_H
#define VELOCITYPLOT_H

#include <QDialog>
#include "qcustomplot.h"
namespace Ui {
class VelocityPlot;
}

class VelocityPlot : public QDialog
{
    Q_OBJECT

public:
    explicit VelocityPlot(QWidget *parent = 0);
    void plot_data(QVector<double> &time,QVector<double> &vx,QVector<double> &vy,QVector<double> &vz,double &final_time);
    ~VelocityPlot();


private:
    Ui::VelocityPlot *ui;
};

#endif // VELOCITYPLOT_H
