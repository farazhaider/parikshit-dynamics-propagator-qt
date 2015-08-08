#ifndef QERRORPLOT_H
#define QERRORPLOT_H

#include <QDialog>
#include "qcustomplot.h"
namespace Ui {
class QErrorPlot;
}

class QErrorPlot : public QDialog
{
    Q_OBJECT

public:
    explicit QErrorPlot(QWidget *parent = 0);
    void plot_data(QVector<double> &time,QVector<double> &qerra,QVector<double> &errx,QVector<double> &erry,QVector<double> &errz,double &final_time);
    ~QErrorPlot();

private:
    Ui::QErrorPlot *ui;
};

#endif // QERRORPLOT_H
