/********************************************************************************
** Form generated from reading UI file 'omegaerrorplot.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OMEGAERRORPLOT_H
#define UI_OMEGAERRORPLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_OmegaErrorPlot
{
public:
    QGridLayout *gridLayout;
    QCustomPlot *werrPlot;

    void setupUi(QDialog *OmegaErrorPlot)
    {
        if (OmegaErrorPlot->objectName().isEmpty())
            OmegaErrorPlot->setObjectName(QStringLiteral("OmegaErrorPlot"));
        OmegaErrorPlot->resize(400, 300);
        gridLayout = new QGridLayout(OmegaErrorPlot);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        werrPlot = new QCustomPlot(OmegaErrorPlot);
        werrPlot->setObjectName(QStringLiteral("werrPlot"));

        gridLayout->addWidget(werrPlot, 0, 0, 1, 1);


        retranslateUi(OmegaErrorPlot);

        QMetaObject::connectSlotsByName(OmegaErrorPlot);
    } // setupUi

    void retranslateUi(QDialog *OmegaErrorPlot)
    {
        OmegaErrorPlot->setWindowTitle(QApplication::translate("OmegaErrorPlot", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class OmegaErrorPlot: public Ui_OmegaErrorPlot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OMEGAERRORPLOT_H
