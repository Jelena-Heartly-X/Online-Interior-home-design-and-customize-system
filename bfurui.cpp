#include "bfurniture.h"
#include "ui_bfurniture.h"
#include "Furniture.h"
#include <iostream>

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
    return bed;
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
