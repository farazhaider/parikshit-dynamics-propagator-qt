#ifndef OMEGAERRORPLOT_H
#define OMEGAERRORPLOT_H

#include <QDialog>
#include "qcustomplot.h"
namespace Ui {
class OmegaErrorPlot;
}

class OmegaErrorPlot : public QDialog
{
    Q_OBJECT

public:
    explicit OmegaErrorPlot(QWidget *parent = 0);
    void plot_data(QVector<double> &time,QVector<double> &werrx,QVector<double> &werry,QVector<double> &werrz,double &final_time);
    ~OmegaErrorPlot();

private:
    Ui::OmegaErrorPlot *ui;
};

#endif // OMEGAERRORPLOT_H
