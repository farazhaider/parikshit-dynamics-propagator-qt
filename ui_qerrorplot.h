/********************************************************************************
** Form generated from reading UI file 'qerrorplot.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QERRORPLOT_H
#define UI_QERRORPLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_QErrorPlot
{
public:
    QGridLayout *gridLayout;
    QCustomPlot *qerrPlot;

    void setupUi(QDialog *QErrorPlot)
    {
        if (QErrorPlot->objectName().isEmpty())
            QErrorPlot->setObjectName(QStringLiteral("QErrorPlot"));
        QErrorPlot->resize(400, 300);
        gridLayout = new QGridLayout(QErrorPlot);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        qerrPlot = new QCustomPlot(QErrorPlot);
        qerrPlot->setObjectName(QStringLiteral("qerrPlot"));

        gridLayout->addWidget(qerrPlot, 0, 0, 1, 1);


        retranslateUi(QErrorPlot);

        QMetaObject::connectSlotsByName(QErrorPlot);
    } // setupUi

    void retranslateUi(QDialog *QErrorPlot)
    {
        QErrorPlot->setWindowTitle(QApplication::translate("QErrorPlot", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class QErrorPlot: public Ui_QErrorPlot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QERRORPLOT_H
