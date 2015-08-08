/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *velocity_layout;
    QLabel *v_label;
    QLineEdit *v_x;
    QLineEdit *v_y;
    QLineEdit *v_z;
    QHBoxLayout *radius_layout;
    QLabel *r_label;
    QLineEdit *r_x;
    QLineEdit *r_y;
    QLineEdit *r_z;
    QHBoxLayout *w_br_layout;
    QLabel *w_br_label;
    QLineEdit *w_br_x;
    QLineEdit *w_br_y;
    QLineEdit *w_br_z;
    QHBoxLayout *w_bi_layout;
    QLabel *w_bi_label;
    QLineEdit *w_bi_x;
    QLineEdit *w_bi_y;
    QLineEdit *w_bi_z;
    QHBoxLayout *angle_layout;
    QLabel *yaw_label;
    QLineEdit *yaw;
    QLabel *pitch_label;
    QLineEdit *pitch;
    QLabel *roll_label;
    QLineEdit *roll;
    QHBoxLayout *disturbance_torque_layout;
    QLabel *td_label;
    QLineEdit *td_x;
    QLineEdit *td_y;
    QLineEdit *td_z;
    QHBoxLayout *misc_layout;
    QLabel *step_label;
    QLineEdit *step;
    QLabel *time_label;
    QLineEdit *final_time;
    QPushButton *compute;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(624, 302);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        velocity_layout = new QHBoxLayout();
        velocity_layout->setSpacing(6);
        velocity_layout->setObjectName(QStringLiteral("velocity_layout"));
        v_label = new QLabel(centralWidget);
        v_label->setObjectName(QStringLiteral("v_label"));

        velocity_layout->addWidget(v_label);

        v_x = new QLineEdit(centralWidget);
        v_x->setObjectName(QStringLiteral("v_x"));

        velocity_layout->addWidget(v_x);

        v_y = new QLineEdit(centralWidget);
        v_y->setObjectName(QStringLiteral("v_y"));

        velocity_layout->addWidget(v_y);

        v_z = new QLineEdit(centralWidget);
        v_z->setObjectName(QStringLiteral("v_z"));

        velocity_layout->addWidget(v_z);


        gridLayout->addLayout(velocity_layout, 0, 0, 1, 1);

        radius_layout = new QHBoxLayout();
        radius_layout->setSpacing(6);
        radius_layout->setObjectName(QStringLiteral("radius_layout"));
        r_label = new QLabel(centralWidget);
        r_label->setObjectName(QStringLiteral("r_label"));

        radius_layout->addWidget(r_label);

        r_x = new QLineEdit(centralWidget);
        r_x->setObjectName(QStringLiteral("r_x"));

        radius_layout->addWidget(r_x);

        r_y = new QLineEdit(centralWidget);
        r_y->setObjectName(QStringLiteral("r_y"));

        radius_layout->addWidget(r_y);

        r_z = new QLineEdit(centralWidget);
        r_z->setObjectName(QStringLiteral("r_z"));

        radius_layout->addWidget(r_z);


        gridLayout->addLayout(radius_layout, 1, 0, 1, 1);

        w_br_layout = new QHBoxLayout();
        w_br_layout->setSpacing(6);
        w_br_layout->setObjectName(QStringLiteral("w_br_layout"));
        w_br_label = new QLabel(centralWidget);
        w_br_label->setObjectName(QStringLiteral("w_br_label"));

        w_br_layout->addWidget(w_br_label);

        w_br_x = new QLineEdit(centralWidget);
        w_br_x->setObjectName(QStringLiteral("w_br_x"));

        w_br_layout->addWidget(w_br_x);

        w_br_y = new QLineEdit(centralWidget);
        w_br_y->setObjectName(QStringLiteral("w_br_y"));

        w_br_layout->addWidget(w_br_y);

        w_br_z = new QLineEdit(centralWidget);
        w_br_z->setObjectName(QStringLiteral("w_br_z"));

        w_br_layout->addWidget(w_br_z);


        gridLayout->addLayout(w_br_layout, 2, 0, 1, 1);

        w_bi_layout = new QHBoxLayout();
        w_bi_layout->setSpacing(6);
        w_bi_layout->setObjectName(QStringLiteral("w_bi_layout"));
        w_bi_label = new QLabel(centralWidget);
        w_bi_label->setObjectName(QStringLiteral("w_bi_label"));

        w_bi_layout->addWidget(w_bi_label);

        w_bi_x = new QLineEdit(centralWidget);
        w_bi_x->setObjectName(QStringLiteral("w_bi_x"));

        w_bi_layout->addWidget(w_bi_x);

        w_bi_y = new QLineEdit(centralWidget);
        w_bi_y->setObjectName(QStringLiteral("w_bi_y"));

        w_bi_layout->addWidget(w_bi_y);

        w_bi_z = new QLineEdit(centralWidget);
        w_bi_z->setObjectName(QStringLiteral("w_bi_z"));

        w_bi_layout->addWidget(w_bi_z);


        gridLayout->addLayout(w_bi_layout, 3, 0, 1, 1);

        angle_layout = new QHBoxLayout();
        angle_layout->setSpacing(6);
        angle_layout->setObjectName(QStringLiteral("angle_layout"));
        yaw_label = new QLabel(centralWidget);
        yaw_label->setObjectName(QStringLiteral("yaw_label"));

        angle_layout->addWidget(yaw_label);

        yaw = new QLineEdit(centralWidget);
        yaw->setObjectName(QStringLiteral("yaw"));

        angle_layout->addWidget(yaw);

        pitch_label = new QLabel(centralWidget);
        pitch_label->setObjectName(QStringLiteral("pitch_label"));

        angle_layout->addWidget(pitch_label);

        pitch = new QLineEdit(centralWidget);
        pitch->setObjectName(QStringLiteral("pitch"));

        angle_layout->addWidget(pitch);

        roll_label = new QLabel(centralWidget);
        roll_label->setObjectName(QStringLiteral("roll_label"));

        angle_layout->addWidget(roll_label);

        roll = new QLineEdit(centralWidget);
        roll->setObjectName(QStringLiteral("roll"));

        angle_layout->addWidget(roll);


        gridLayout->addLayout(angle_layout, 4, 0, 1, 1);

        disturbance_torque_layout = new QHBoxLayout();
        disturbance_torque_layout->setSpacing(6);
        disturbance_torque_layout->setObjectName(QStringLiteral("disturbance_torque_layout"));
        td_label = new QLabel(centralWidget);
        td_label->setObjectName(QStringLiteral("td_label"));

        disturbance_torque_layout->addWidget(td_label);

        td_x = new QLineEdit(centralWidget);
        td_x->setObjectName(QStringLiteral("td_x"));

        disturbance_torque_layout->addWidget(td_x);

        td_y = new QLineEdit(centralWidget);
        td_y->setObjectName(QStringLiteral("td_y"));

        disturbance_torque_layout->addWidget(td_y);

        td_z = new QLineEdit(centralWidget);
        td_z->setObjectName(QStringLiteral("td_z"));

        disturbance_torque_layout->addWidget(td_z);


        gridLayout->addLayout(disturbance_torque_layout, 5, 0, 1, 1);

        misc_layout = new QHBoxLayout();
        misc_layout->setSpacing(6);
        misc_layout->setObjectName(QStringLiteral("misc_layout"));
        step_label = new QLabel(centralWidget);
        step_label->setObjectName(QStringLiteral("step_label"));

        misc_layout->addWidget(step_label);

        step = new QLineEdit(centralWidget);
        step->setObjectName(QStringLiteral("step"));

        misc_layout->addWidget(step);

        time_label = new QLabel(centralWidget);
        time_label->setObjectName(QStringLiteral("time_label"));

        misc_layout->addWidget(time_label);

        final_time = new QLineEdit(centralWidget);
        final_time->setObjectName(QStringLiteral("final_time"));

        misc_layout->addWidget(final_time);

        compute = new QPushButton(centralWidget);
        compute->setObjectName(QStringLiteral("compute"));

        misc_layout->addWidget(compute);


        gridLayout->addLayout(misc_layout, 6, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 624, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        v_label->setText(QApplication::translate("MainWindow", "Initial Velocity", 0));
        r_label->setText(QApplication::translate("MainWindow", "Initial Radius", 0));
        w_br_label->setText(QApplication::translate("MainWindow", "Omega B->R", 0));
        w_bi_label->setText(QApplication::translate("MainWindow", "Omega B->I", 0));
        yaw_label->setText(QApplication::translate("MainWindow", "Yaw", 0));
        pitch_label->setText(QApplication::translate("MainWindow", "Pitch", 0));
        roll_label->setText(QApplication::translate("MainWindow", "Roll", 0));
        td_label->setText(QApplication::translate("MainWindow", "Disturbance Torque", 0));
        step_label->setText(QApplication::translate("MainWindow", "Step", 0));
        time_label->setText(QApplication::translate("MainWindow", "Final Time", 0));
        compute->setText(QApplication::translate("MainWindow", "Compute", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
