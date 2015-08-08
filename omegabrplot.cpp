#include "omegabrplot.h"
#include "ui_omegabrplot.h"

OmegaBrPlot::OmegaBrPlot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OmegaBrPlot)
{
    ui->setupUi(this);
}

OmegaBrPlot::~OmegaBrPlot()
{
    delete ui;
}
