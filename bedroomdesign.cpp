#include "bedroomdesign.h"
#include "ui_bedroomdesign.h"
#include "bfurniture.h"
#include "viewbedroom.h"
#include "bflooring1.h"
#include "btheme1.h"
#include <iostream>
#include <QPixmap>
#include <QScreen>

using namespace std;

bedroomDesign::bedroomDesign(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::bedroomDesign)
{
    ui->setupUi(this);
}

bedroomDesign::~bedroomDesign()
{
    delete ui;
}

Bedroom::Bedroom():bedFur(),bedFloor(),bedTheme()
{

}

Bedroom::Bedroom(BFurniture fur,BFlooring floor,BTheme bedTheme):bedFur(fur),bedFloor(floor),bedTheme(bedTheme)
{

}

Bedroom::Bedroom(const Bedroom & obj):bedFur(obj.bedFur),bedFloor(obj.bedFloor),bedTheme(obj.bedTheme)
{

}

Bedroom::~Bedroom()
{

}

void bedroomDesign::on_bfurbtn_clicked()
{
    bfurui bfur;
    QScreen *primaryScreen = QApplication::primaryScreen();
    QRect screenGeometry = primaryScreen->geometry();
    bfur.resize(screenGeometry.size());
    bfur.setModal(true);
    bfur.exec();
}


void bedroomDesign::on_bfloorbtn_clicked()
{
    bflooring1 bfloor;
    QScreen *primaryScreen = QApplication::primaryScreen();
    QRect screenGeometry = primaryScreen->geometry();
    bfloor.resize(screenGeometry.size());
    bfloor.setModal(true);
    bfloor.exec();
}


void bedroomDesign::on_bthemebtn_clicked()
{
    btheme1 bth;
    QScreen *primaryScreen = QApplication::primaryScreen();
    QRect screenGeometry = primaryScreen->geometry();
    bth.resize(screenGeometry.size());
    bth.setModal(true);
    bth.exec();
}


void bedroomDesign::on_viewbtn_clicked()
{
    viewBedroom bedroom;
    QScreen *primaryScreen = QApplication::primaryScreen();
    QRect screenGeometry = primaryScreen->geometry();
    bedroom.resize(screenGeometry.size());
    bedroom.setModal(true);
    bedroom.exec();
}

