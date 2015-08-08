#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"
#include "velocityplot.h"
#include "qbiplot.h"
#include "omegabiplot.h"
#include "omegaerrorplot.h"
#include "qerrorplot.h"
#include "magneticfieldplot.h"
#include "qreferenceplot.h"
#include "qerror_angle.h"

#include "radiusplot.h"
#include "dashboard.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->r_x->setText("-4574.864542173510");
    ui->r_y->setText("5548.715893525739");
    ui->r_z->setText("14.655863338082");

    ui->v_x->setText("0.853878261671869");
    ui->v_y->setText("0.692230734080194");
    ui->v_z->setText("7.360691063866804");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_compute_clicked()
{

    ui->compute->setEnabled(false);
    VECTOR w_bi,w_br,e,Td;
    double r[3],v[3];
    double final_time,step;






    w_br.vec[0]=ui->w_br_x->text().toDouble()*pi/180;
    w_br.vec[1]=ui->w_br_y->text().toDouble()*pi/180;
    w_br.vec[2]=ui->w_br_z->text().toDouble()*pi/180;

    e.vec[0]=ui->yaw->text().toDouble()*pi/180;
    e.vec[1]=ui->pitch->text().toDouble()*pi/180;
    e.vec[2]=ui->roll->text().toDouble()*pi/180;


    v[0]=ui->v_x->text().toDouble();
    v[1]=ui->v_y->text().toDouble();
    v[2]=ui->v_z->text().toDouble();


    r[0]=ui->r_x->text().toDouble();
    r[1]=ui->r_y->text().toDouble();
    r[2]=ui->r_z->text().toDouble();

    Td.vec[0]=ui->td_x->text().toDouble();
    Td.vec[1]=ui->td_y->text().toDouble();
    Td.vec[2]=ui->td_z->text().toDouble();

    final_time=ui->final_time->text().toDouble();
    step=ui->step->text().toDouble();


    Dashboard d;
    VelocityPlot *vplot =new VelocityPlot;
    RadiusPlot *rplot= new RadiusPlot;
    QBiPlot *qbiplot = new QBiPlot;
    QErrorPlot *qerrplot = new QErrorPlot;
    QReferencePlot *qrefplot = new QReferencePlot;
    OmegaBiPlot *wbiplot = new OmegaBiPlot;
    OmegaErrorPlot *werrplot = new OmegaErrorPlot;
    MagneticFieldPlot *magplot = new MagneticFieldPlot;
    qerror_angle *qerrangplot = new qerror_angle;



    adcsElements element;
    d.adcs_engine(step,final_time,r,v,w_br,w_bi,Td,e,element);

    vplot->plot_data(element.time,element.velocity_x,element.velocity_y,element.velocity_z,final_time);
    rplot->plot_data(element.time,element.radius_x,element.radius_y,element.radius_z,final_time);
    magplot->plot_data(element.time,element.magnetic_field_x,element.magnetic_field_y,element.magnetic_field_z,final_time);
    qbiplot->plot_data(element.time,element.q_bi_a,element.q_bi_x,element.q_bi_y,element.q_bi_z,final_time);
    qerrplot->plot_data(element.time,element.q_err_a,element.q_err_x,element.q_err_y,element.q_err_z,final_time);
    qrefplot->plot_data(element.time,element.q_ref_a,element.q_ref_x,element.q_ref_y,element.q_ref_z,final_time);
    wbiplot->plot_data(element.time,element.w_bi_x,element.w_bi_y,element.w_bi_z,final_time);
    werrplot->plot_data(element.time,element.w_err_x,element.w_err_y,element.w_err_z,final_time);
    qerrangplot->plot_data(element.time,element.q_err_angle_x,element.q_err_angle_y,element.q_err_angle_z,final_time);




    vplot->setMinimumSize(QSize(800,600));
    rplot->setMinimumSize(QSize(800,600));
    magplot->setMinimumSize(QSize(800,600));
    wbiplot->setMinimumSize(QSize(800,600));
    werrplot->setMinimumSize(QSize(800,600));
    qbiplot->setMinimumSize(QSize(800,600));
    qrefplot->setMinimumSize(QSize(800,600));
    qerrplot->setMinimumSize(QSize(800,600));
    qerrangplot->setMinimumSize(QSize(800,600));

    vplot->setWindowTitle("Velocity Vector");
    rplot->setWindowTitle("Radius Vector");
    qbiplot->setWindowTitle("Quaternion Body to Inertial");
    qrefplot->setWindowTitle("Quaternion Reference");
    qerrplot->setWindowTitle("error in satellite's orientation in quaternion");
    magplot->setWindowTitle("Magnetic Field Vector Orbit Frame");
    wbiplot->setWindowTitle("Satellite's Body Rates");
    werrplot->setWindowTitle("Error in satellite's body rates");
    qerrangplot->setWindowTitle("Error in sattelite's orientation in euler angles");
    qbiplot->show();
    qrefplot->show();
    qerrplot->show();
    vplot->show();
    rplot->show();
    magplot->show();
    wbiplot->show();
    werrplot->show();
    qerrangplot->show();

    //qDebug()<<element.q_bi_a.last() << element.q_bi_x.last() << element.q_bi_y.last() << element.q_bi_z.last();
    ui->compute->setEnabled(true);
}
