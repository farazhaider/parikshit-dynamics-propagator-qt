#-------------------------------------------------
#
# ADCS Dynamics By Faraz Haider 5-June-2014
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = adcs_model
TEMPLATE = app


SOURCES += \
    adcselements.cpp \
    dashboard.cpp \
    dialog.cpp \
    dynamics_modules.cpp \
    ephimeredes.cpp \
    frame_conversions.cpp \
    igrf.cpp \
    legacy.cpp \
    magneticfieldplot.cpp \
    main.cpp \
    mainwindow.cpp \
    mat_ops.cpp \
    omegabiplot.cpp \
    omegabrplot.cpp \
    omegaerrorplot.cpp \
    qbiplot.cpp \
    qcustomplot.cpp \
    qerror_angle.cpp \
    qerrorplot.cpp \
    qreferenceplot.cpp \
    quat_ops.cpp \
    radiusplot.cpp \
    vec_ops.cpp \
    velocityplot.cpp


HEADERS  += \
    adcs_engine.h \
    adcselements.h \
    astro_constants.h \
    dashboard.h \
    data_structs.h \
    declarations.h \
    dialog.h \
    dynamics_modules.h \
    ephimeredes.h \
    frame_conversions.h \
    igrf.h \
    legacy.h \
    magneticfieldplot.h \
    mainwindow.h \
    mat_ops.h \
    omegabiplot.h \
    omegaerrorplot.h \
    qbiplot.h \
    qcustomplot.h \
    qerror_angle.h \
    qerrorplot.h \
    qreferenceplot.h \
    quat_ops.h \
    radiusplot.h \
    ui_magneticfieldplot.h \
    ui_mainwindow.h \
    ui_omegabiplot.h \
    ui_omegaerrorplot.h \
    ui_qbiplot.h \
    ui_qerrorplot.h \
    ui_qreferenceplot.h \
    ui_radiusplot.h \
    ui_velocityplot.h \
    vec_ops.h \
    velocityplot.h



FORMS    += \
    dialog.ui \
    magneticfieldplot.ui \
    mainwindow.ui \
    omegabiplot.ui \
    omegaerrorplot.ui \
    qbiplot.ui \
    qerror_angle.ui \
    qerrorplot.ui \
    qreferenceplot.ui \
    radiusplot.ui \
    velocityplot.ui




