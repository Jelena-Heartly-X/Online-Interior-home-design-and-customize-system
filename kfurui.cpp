#include "kfurui.h"
#include "ui_kfurui.h"
#include "diningtable.h"
#include "countertop.h"
#include "cabinet.h"
#include "sink.h"
#include <QScreen>

kfurui::kfurui(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::kfurui)
{
    ui->setupUi(this);
}

kfurui::~kfurui()
{
    delete ui;
}

void kfurui::on_diningTablebtn_clicked()
{

    diningTable *diningTables = new diningTable(this);
    QScreen *primaryScreen = QApplication::primaryScreen();
    QRect screenGeometry = primaryScreen->geometry();
    diningTables->resize(screenGeometry.size());
    diningTables->setModal(true);
    diningTables->exec();

    delete diningTables;
}
void kfurui::on_cabinetbtn_clicked()
{
    cabinet * cabinets = new  cabinet(this);
    QScreen *primaryScreen = QApplication::primaryScreen();
    QRect screenGeometry = primaryScreen->geometry();
    cabinets->resize(screenGeometry.size());
    cabinets->setModal(true);
    cabinets->exec();

    delete cabinets;
}

void kfurui::on_counterTopbtn_clicked()
{
    counterTop * counterTops = new counterTop(this);
    QScreen *primaryScreen = QApplication::primaryScreen();
    QRect screenGeometry = primaryScreen->geometry();
    counterTops->resize(screenGeometry.size());
    counterTops->setModal(true);
    counterTops->exec();

    delete counterTops;

}
void kfurui::on_sinkbtn_clicked()
{
    sink * sinks  = new  sink (this);
    QScreen *primaryScreen = QApplication::primaryScreen();
    QRect screenGeometry = primaryScreen->geometry();
    sinks ->resize(screenGeometry.size());
    sinks->setModal(true);
    sinks->exec();

    delete sinks ;

}
