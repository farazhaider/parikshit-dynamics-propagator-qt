#ifndef RADIUSPLOT_H
#define RADIUSPLOT_H

#include <QDialog>
#include "qcustomplot.h"
namespace Ui {
class RadiusPlot;
}

class RadiusPlot : public QDialog
{
    Q_OBJECT

public:
    explicit RadiusPlot(QWidget *parent = 0);
    void plot_data(QVector<double> &time,QVector<double> &x,QVector<double> &y,QVector<double> &z,double &final_time);
    ~RadiusPlot();

private:
    Ui::RadiusPlot *ui;
};

#endif // RADIUSPLOT_H
