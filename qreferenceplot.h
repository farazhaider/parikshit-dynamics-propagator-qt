#ifndef QREFERENCEPLOT_H
#define QREFERENCEPLOT_H

#include <QDialog>
#include "qcustomplot.h"
namespace Ui {
class QReferencePlot;
}

class QReferencePlot : public QDialog
{
    Q_OBJECT

public:
    explicit QReferencePlot(QWidget *parent = 0);
    void plot_data(QVector<double> &time,QVector<double> &qrefa,QVector<double> &qrefx,QVector<double> &qrefy,QVector<double> &qrefz,double &final_time);
    ~QReferencePlot();

private:
    Ui::QReferencePlot *ui;
};

#endif // QREFERENCEPLOT_H
