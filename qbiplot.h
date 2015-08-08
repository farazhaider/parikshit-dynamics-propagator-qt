#ifndef QBIPLOT_H
#define QBIPLOT_H

#include <QDialog>
#include "qcustomplot.h"
namespace Ui {
class QBiPlot;
}

class QBiPlot : public QDialog
{
    Q_OBJECT

public:
    explicit QBiPlot(QWidget *parent = 0);
    void plot_data(QVector<double> &time,QVector<double> &qbia,QVector<double> &qbix,QVector<double> &qbiy,QVector<double> &qbiz,double &final_time);
    ~QBiPlot();

private:
    Ui::QBiPlot *ui;
};

#endif // QBIPLOT_H
