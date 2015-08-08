/********************************************************************************
** Form generated from reading UI file 'omegabiplot.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OMEGABIPLOT_H
#define UI_OMEGABIPLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_OmegaBiPlot
{
public:
    QGridLayout *gridLayout;
    QCustomPlot *wbiPlot;

    void setupUi(QDialog *OmegaBiPlot)
    {
        if (OmegaBiPlot->objectName().isEmpty())
            OmegaBiPlot->setObjectName(QStringLiteral("OmegaBiPlot"));
        OmegaBiPlot->resize(400, 300);
        gridLayout = new QGridLayout(OmegaBiPlot);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        wbiPlot = new QCustomPlot(OmegaBiPlot);
        wbiPlot->setObjectName(QStringLiteral("wbiPlot"));

        gridLayout->addWidget(wbiPlot, 0, 0, 1, 1);


        retranslateUi(OmegaBiPlot);

        QMetaObject::connectSlotsByName(OmegaBiPlot);
    } // setupUi

    void retranslateUi(QDialog *OmegaBiPlot)
    {
        OmegaBiPlot->setWindowTitle(QApplication::translate("OmegaBiPlot", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class OmegaBiPlot: public Ui_OmegaBiPlot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OMEGABIPLOT_H
