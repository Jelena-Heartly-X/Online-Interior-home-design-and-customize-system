#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Home.h"
#include <QMainWindow>
#include <iostream>
#include <string>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
class OnlineInterior;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_sign_in_clicked();

    void on_log_in_clicked();

private:
    Ui::OnlineInterior *ui;
};
#endif // MAINWINDOW_H

