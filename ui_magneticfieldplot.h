/********************************************************************************
** Form generated from reading UI file 'magneticfieldplot.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAGNETICFIELDPLOT_H
#define UI_MAGNETICFIELDPLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MagneticFieldPlot
{
public:
    QGridLayout *gridLayout;
    QCustomPlot *magnetic_field_Plot;

    void setupUi(QDialog *MagneticFieldPlot)
    {
        if (MagneticFieldPlot->objectName().isEmpty())
            MagneticFieldPlot->setObjectName(QStringLiteral("MagneticFieldPlot"));
        MagneticFieldPlot->resize(400, 300);
        gridLayout = new QGridLayout(MagneticFieldPlot);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        magnetic_field_Plot = new QCustomPlot(MagneticFieldPlot);
        magnetic_field_Plot->setObjectName(QStringLiteral("magnetic_field_Plot"));

        gridLayout->addWidget(magnetic_field_Plot, 0, 0, 1, 1);


        retranslateUi(MagneticFieldPlot);

        QMetaObject::connectSlotsByName(MagneticFieldPlot);
    } // setupUi

    void retranslateUi(QDialog *MagneticFieldPlot)
    {
        MagneticFieldPlot->setWindowTitle(QApplication::translate("MagneticFieldPlot", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class MagneticFieldPlot: public Ui_MagneticFieldPlot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAGNETICFIELDPLOT_H
