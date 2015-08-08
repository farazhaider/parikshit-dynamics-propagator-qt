#include "mainwindow.h"
#include <QApplication>
#include <QIcon>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("ADCS Dashboard");
    QIcon q("icon.jpg");
    w.setWindowIcon(q);
    w.show();
    return a.exec();
}
