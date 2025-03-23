#include "bfurniture.h"
#include "ui_bfurniture.h"
#include "Furniture.h"
#include "bed.h"
#include "wardrobe.h"
#include "deskchair.h"
#include "lamps.h"
#include "floorrug.h"
#include "decitems.h"
#include <iostream>
#include <QScreen>

using namespace std;

bfurui::bfurui(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::bfurui)
{
    ui->setupUi(this);
}

bfurui::~bfurui()
{
    delete ui;
}

BFurniture::BFurniture():bed(),wardrobe(),desk(),lamps(),floorRug(),decItems()
{

}

BFurniture::BFurniture(string bed,string wardrobe,string desk,string lamps,string floorRug,string decItems):bed(bed),wardrobe(wardrobe),desk(desk),lamps(lamps),floorRug(floorRug),decItems(decItems)
{

}

BFurniture::BFurniture(const BFurniture & fur):bed(fur.bed),wardrobe(fur.wardrobe),desk(fur.desk),lamps(fur.lamps),floorRug(fur.floorRug),decItems(fur.decItems)
{

}

BFurniture::~BFurniture()
{

}
string BFurniture::getBed()
{
    return this->bed;
}

string BFurniture:: getWardrobe()
{
    return wardrobe;
}

string BFurniture::getDesk()
{
    return desk;
}

string BFurniture::getLamps()
{
    return lamps;
}

string BFurniture::getFloorRug()
{
    return floorRug;
}

string BFurniture::getDecItems()
{
    return decItems;
}

void BFurniture::setBed(const QString &bed)
{
    this->bed=bed.toStdString();
}

void BFurniture::setWardrobe(const QString & wardrobe)
{
    this->wardrobe=wardrobe.toStdString();
}

void BFurniture::setdesk(const QString & desk)
{
    this->desk=desk.toStdString();
}

void BFurniture::setLamps(const QString & lamp)
{
    this->lamps=lamp.toStdString();
}

void BFurniture::setFloorRug(const QString & rug)
{
    this->floorRug=rug.toStdString();
}

void BFurniture::setDecItems(const QString & items)
{
    this->decItems=items.toStdString();
}

void bfurui::on_bedbtn_clicked()
{
    bed *beds = new bed(this);
    QScreen *primaryScreen = QApplication::primaryScreen();
    QRect screenGeometry = primaryScreen->geometry();
    beds->resize(screenGeometry.size());
    beds->setModal(true);
    beds->exec();

    delete beds;
}

void bfurui::on_wardrobebtn_clicked()
{
    wardrobe *wr = new wardrobe(this);
    QScreen *primaryScreen = QApplication::primaryScreen();
    QRect screenGeometry = primaryScreen->geometry();
    wr->resize(screenGeometry.size());
    wr->setModal(true);
    wr->exec();
    delete wr;
}



void bfurui::on_deskbtn_clicked()
{
    deskchair *dc = new deskchair(this);
    QScreen *primaryScreen = QApplication::primaryScreen();
    QRect screenGeometry = primaryScreen->geometry();
    dc->resize(screenGeometry.size());
    dc->setModal(true);
    dc->exec();
    delete dc;
}


void bfurui::on_lampbtn_clicked()
{
    lamps *l = new lamps(this);
    QScreen *primaryScreen = QApplication::primaryScreen();
    QRect screenGeometry = primaryScreen->geometry();
    l->resize(screenGeometry.size());
    l->setModal(true);
    l->exec();
    delete l;
}


void bfurui::on_rugbtn_clicked()
{
    floorRug *fr=new floorRug(this);
    QScreen *primaryScreen = QApplication::primaryScreen();
    QRect screenGeometry = primaryScreen->geometry();
    fr->resize(screenGeometry.size());
    fr->setModal(true);
    fr->exec();
    delete fr;
}


void bfurui::on_decbtn_clicked()
{
    decItems *dc=new decItems(this);
    QScreen *primaryScreen = QApplication::primaryScreen();
    QRect screenGeometry = primaryScreen->geometry();
    dc->resize(screenGeometry.size());
    dc->setModal(true);
    dc->exec();
    delete dc;
}

void BFurniture::setBedPath(const QString &path)
{
    this->setBed(path);
}

void BFurniture::setWardRobePath(const QString &path)
{
    this->setWardrobe(path);
}

void BFurniture::setDeskPath(const QString &path)
{
    this->setdesk(path);
}

void BFurniture::setLampsPath(const QString &path)
{
    this->setLamps(path);
}

void BFurniture::setFloorRugPath(const QString &path)
{
    this->setFloorRug(path);
}

void BFurniture::setDecItemsPath(const QString &path)
{
    this->setDecItems(path);
}
