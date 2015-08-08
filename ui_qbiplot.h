/********************************************************************************
** Form generated from reading UI file 'qbiplot.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QBIPLOT_H
#define UI_QBIPLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_QBiPlot
{
public:
    QGridLayout *gridLayout;
    QCustomPlot *qbiPlot;

    void setupUi(QDialog *QBiPlot)
    {
        if (QBiPlot->objectName().isEmpty())
            QBiPlot->setObjectName(QStringLiteral("QBiPlot"));
        QBiPlot->resize(400, 300);
        gridLayout = new QGridLayout(QBiPlot);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        qbiPlot = new QCustomPlot(QBiPlot);
        qbiPlot->setObjectName(QStringLiteral("qbiPlot"));

        gridLayout->addWidget(qbiPlot, 0, 0, 1, 1);


        retranslateUi(QBiPlot);

        QMetaObject::connectSlotsByName(QBiPlot);
    } // setupUi

    void retranslateUi(QDialog *QBiPlot)
    {
        QBiPlot->setWindowTitle(QApplication::translate("QBiPlot", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class QBiPlot: public Ui_QBiPlot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QBIPLOT_H
