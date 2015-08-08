#ifndef ADCSELEMENTS_H
#define ADCSELEMENTS_H
#include <QObject>
#include <QVector>
class adcsElements : public QObject
{
    Q_OBJECT
public:
    explicit adcsElements(QObject *parent = 0);
    QVector< double > w_bi_x;
    QVector< double > w_bi_y;
    QVector< double > w_bi_z;
    QVector< double > w_err_x;
    QVector< double > w_err_y;
    QVector< double > w_err_z;
    QVector< double > velocity_x;
    QVector< double > velocity_y;
    QVector< double > velocity_z;
    QVector< double > radius_x;
    QVector< double > radius_y;
    QVector< double > radius_z;
    QVector< double > magnetic_field_x;
    QVector< double > magnetic_field_y;
    QVector< double > magnetic_field_z;
    QVector< double > q_bi_a;
    QVector< double > q_bi_x;
    QVector< double > q_bi_y;
    QVector< double > q_bi_z;
    QVector< double > q_err_a;
    QVector< double > q_err_x;
    QVector< double > q_err_y;
    QVector< double > q_err_z;
    QVector< double > q_ref_a;
    QVector< double > q_ref_x;
    QVector< double > q_ref_y;
    QVector< double > q_ref_z;
    QVector <double> q_err_angle_x;
    QVector <double> q_err_angle_y;
    QVector <double> q_err_angle_z;
    QVector <double> q_dot_angle_x;
    QVector <double> q_dot_angle_y;
    QVector <double> q_dot_angle_z;

    QVector< double > time;

signals:

public slots:

};

#endif // ADCSELEMENTS_H
