#include "lfurui.h"
#include "ui_lfurui.h"
#include "sofa.h"
#include "coffeetable.h"
#include "tvstand.h"
#include "bookshelf.h"
#include "lfloorrug.h"
#include "llamps.h"
#include "ldecitems.h"
#include <QScreen>

lfurui::lfurui(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::lfurui)
{
    ui->setupUi(this);
}

lfurui::~lfurui()
{
    delete ui;
}

void lfurui::on_sofabtn_clicked()
{
    sofa s;
    QScreen *primaryScreen = QApplication::primaryScreen();
    QRect screenGeometry = primaryScreen->geometry();
    s.resize(screenGeometry.size());
    s.setModal(true);
    s.exec();
}


void lfurui::on_coffeetablebtn_clicked()
{
    coffeeTable ct;
    QScreen *primaryScreen = QApplication::primaryScreen();
    QRect screenGeometry = primaryScreen->geometry();
    ct.resize(screenGeometry.size());
    ct.setModal(true);
    ct.exec();
}


void lfurui::on_tvstandbtn_clicked()
{
    tvstand tv;
    QScreen *primaryScreen = QApplication::primaryScreen();
    QRect screenGeometry = primaryScreen->geometry();
    tv.resize(screenGeometry.size());
    tv.setModal(true);
    tv.exec();
}


void lfurui::on_bookshelfbtn_clicked()
{
    bookshelf bs;
    QScreen *primaryScreen = QApplication::primaryScreen();
    QRect screenGeometry = primaryScreen->geometry();
    bs.resize(screenGeometry.size());
    bs.setModal(true);
    bs.exec();
}

void lfurui::on_lampbtn_clicked()
{
    llamps l;
    QScreen *primaryScreen = QApplication::primaryScreen();
    QRect screenGeometry = primaryScreen->geometry();
    l.resize(screenGeometry.size());
    l.setModal(true);
    l.exec();
}


void lfurui::on_decitembtn_clicked()
{
    ldecitems ldi;
    QScreen *primaryScreen = QApplication::primaryScreen();
    QRect screenGeometry = primaryScreen->geometry();
    ldi.resize(screenGeometry.size());
    ldi.setModal(true);
    ldi.exec();
}


void lfurui::on_lfloorrugbtn_clicked()
{
    lfloorRug fr;
    QScreen *primaryScreen = QApplication::primaryScreen();
    QRect screenGeometry = primaryScreen->geometry();
    fr.resize(screenGeometry.size());
    fr.setModal(true);
    fr.exec();
}

