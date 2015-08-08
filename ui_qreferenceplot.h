/********************************************************************************
** Form generated from reading UI file 'qreferenceplot.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QREFERENCEPLOT_H
#define UI_QREFERENCEPLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_QReferencePlot
{
public:
    QGridLayout *gridLayout;
    QCustomPlot *qrefPlot;

    void setupUi(QDialog *QReferencePlot)
    {
        if (QReferencePlot->objectName().isEmpty())
            QReferencePlot->setObjectName(QStringLiteral("QReferencePlot"));
        QReferencePlot->resize(400, 300);
        gridLayout = new QGridLayout(QReferencePlot);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        qrefPlot = new QCustomPlot(QReferencePlot);
        qrefPlot->setObjectName(QStringLiteral("qrefPlot"));

        gridLayout->addWidget(qrefPlot, 0, 0, 1, 1);


        retranslateUi(QReferencePlot);

        QMetaObject::connectSlotsByName(QReferencePlot);
    } // setupUi

    void retranslateUi(QDialog *QReferencePlot)
    {
        QReferencePlot->setWindowTitle(QApplication::translate("QReferencePlot", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class QReferencePlot: public Ui_QReferencePlot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QREFERENCEPLOT_H
