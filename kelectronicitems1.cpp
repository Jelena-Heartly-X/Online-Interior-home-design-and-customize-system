#include "kelectronicitems1.h"
#include "ui_kelectronicitems1.h"
#include "fridge.h"
#include "stove.h"
#include "oven.h"
#include <QScreen>

kelectronicitems1::kelectronicitems1(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::kelectronicitems1)
{
    ui->setupUi(this);

}

kelectronicitems1::~kelectronicitems1()
{
    delete ui;
}

void kelectronicitems1::on_kfridge1btn_clicked()
{
    fridge f;
    QScreen *primaryScreen = QApplication::primaryScreen();
    QRect screenGeometry = primaryScreen->geometry();
    f.resize(screenGeometry.size());
    f.setModal(true);
    f.exec();
}


void kelectronicitems1::on_kstove2btn_clicked()
{
    stove s;
    QScreen *primaryScreen = QApplication::primaryScreen();
    QRect screenGeometry = primaryScreen->geometry();
    s.resize(screenGeometry.size());
    s.setModal(true);
    s.exec();
}



void kelectronicitems1::on_koven3btn_clicked()
{
    oven o;
    QScreen *primaryScreen = QApplication::primaryScreen();
    QRect screenGeometry = primaryScreen->geometry();
    o.resize(screenGeometry.size());
    o.setModal(true);
    o.exec();
}

