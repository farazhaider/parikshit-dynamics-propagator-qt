#ifndef QERROR_ANGLE_H
#define QERROR_ANGLE_H

#include <QDialog>

namespace Ui {
class qerror_angle;
}

class qerror_angle : public QDialog
{
    Q_OBJECT

public:
    explicit qerror_angle(QWidget *parent = 0);
    void plot_data(QVector<double> &time,QVector<double> &x,QVector<double> &y,QVector<double> &z,double &final_time);
    ~qerror_angle();

private:
    Ui::qerror_angle *ui;
};

#endif // QERROR_ANGLE_H
