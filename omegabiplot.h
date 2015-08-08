#ifndef OMEGABIPLOT_H
#define OMEGABIPLOT_H

#include <QDialog>
#include "qcustomplot.h"
namespace Ui {
class OmegaBiPlot;
}

class OmegaBiPlot : public QDialog
{
    Q_OBJECT

public:
    explicit OmegaBiPlot(QWidget *parent = 0);
    void plot_data(QVector<double> &time,QVector<double> &wbix,QVector<double> &wbiy,QVector<double> &wbiz,double &final_time);
    ~OmegaBiPlot();

private:
    Ui::OmegaBiPlot *ui;
};

#endif // OMEGABIPLOT_H
