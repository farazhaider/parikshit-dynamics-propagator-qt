/********************************************************************************
** Form generated from reading UI file 'radiusplot.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RADIUSPLOT_H
#define UI_RADIUSPLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_RadiusPlot
{
public:
    QGridLayout *gridLayout;
    QCustomPlot *rPlot;

    void setupUi(QDialog *RadiusPlot)
    {
        if (RadiusPlot->objectName().isEmpty())
            RadiusPlot->setObjectName(QStringLiteral("RadiusPlot"));
        RadiusPlot->resize(400, 300);
        gridLayout = new QGridLayout(RadiusPlot);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        rPlot = new QCustomPlot(RadiusPlot);
        rPlot->setObjectName(QStringLiteral("rPlot"));

        gridLayout->addWidget(rPlot, 0, 0, 1, 1);


        retranslateUi(RadiusPlot);

        QMetaObject::connectSlotsByName(RadiusPlot);
    } // setupUi

    void retranslateUi(QDialog *RadiusPlot)
    {
        RadiusPlot->setWindowTitle(QApplication::translate("RadiusPlot", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class RadiusPlot: public Ui_RadiusPlot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RADIUSPLOT_H
