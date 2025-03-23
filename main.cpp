#include "mainwindow.h"
#include <iostream>
#include <QScreen>
#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QScreen *primaryScreen = QApplication::primaryScreen();
    QRect screenGeometry = primaryScreen->geometry();
    w.resize(screenGeometry.size());
    w.show();

    return a.exec();
}
