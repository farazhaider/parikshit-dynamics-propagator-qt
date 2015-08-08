#ifndef MAGNETICFIELDPLOT_H
#define MAGNETICFIELDPLOT_H

#include <QDialog>
#include "qcustomplot.h"
#include <QVector>
namespace Ui {
class MagneticFieldPlot;
}

class MagneticFieldPlot : public QDialog
{
    Q_OBJECT

public:
    explicit MagneticFieldPlot(QWidget *parent = 0);
    void plot_data(QVector<double> &time,QVector<double> &mx,QVector<double> &my,QVector<double> &mz,double &final_time);
    ~MagneticFieldPlot();

private:
    Ui::MagneticFieldPlot *ui;
};

#endif // MAGNETICFIELDPLOT_H
