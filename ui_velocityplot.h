/********************************************************************************
** Form generated from reading UI file 'velocityplot.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VELOCITYPLOT_H
#define UI_VELOCITYPLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_VelocityPlot
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QCustomPlot *vPlot;

    void setupUi(QDialog *VelocityPlot)
    {
        if (VelocityPlot->objectName().isEmpty())
            VelocityPlot->setObjectName(QStringLiteral("VelocityPlot"));
        VelocityPlot->resize(400, 300);
        gridLayout_2 = new QGridLayout(VelocityPlot);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        vPlot = new QCustomPlot(VelocityPlot);
        vPlot->setObjectName(QStringLiteral("vPlot"));

        gridLayout->addWidget(vPlot, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(VelocityPlot);

        QMetaObject::connectSlotsByName(VelocityPlot);
    } // setupUi

    void retranslateUi(QDialog *VelocityPlot)
    {
        VelocityPlot->setWindowTitle(QApplication::translate("VelocityPlot", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class VelocityPlot: public Ui_VelocityPlot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VELOCITYPLOT_H
