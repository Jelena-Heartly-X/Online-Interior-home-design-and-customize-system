#include "lfurniture.h"

#include <iostream>

using namespace std;

LFurniture::LFurniture():sofa(),table(),tvStand(),bookShelf(),floorRug(),lamps(),decItems()
{

}

LFurniture::LFurniture(string sofa,string table,string tvStand,string bookShelf,string floorRug,string lamps ,string decltems):sofa(sofa),table(table),tvStand(tvStand),bookShelf(bookShelf),floorRug(floorRug),lamps(lamps),decItems(decltems)
{

}

LFurniture::LFurniture(const LFurniture & fur):sofa(fur.sofa),table(fur.table),tvStand(fur.tvStand),bookShelf(fur.bookShelf),floorRug(fur.floorRug),lamps(fur.lamps),decItems(fur.decItems)
{

}

LFurniture::~LFurniture()
{

}

string LFurniture::getSofa()
{
    return sofa;
}

string LFurniture:: getTable()
{
    return table;
}

string LFurniture::getTvStand()
{
    return tvStand;
}

string LFurniture::getBookShelf()
{
    return bookShelf;
}

string LFurniture::getFloorRug()
{
    return floorRug;
}

string LFurniture::getLamps()
{
    return lamps;
}
string LFurniture::getDecItems()
{
    return decItems;
}

void LFurniture::setSofa(const QString & sofa)
{
    this->sofa = sofa.toStdString();
}

void LFurniture::setTable(const QString & table)
{
    this->table = table.toStdString();
}

void LFurniture::setTvStand(const QString & tvStand)
{
    this->tvStand = tvStand.toStdString();
}

void LFurniture::setBookShelf(const QString & bookShelf)
{
    this->bookShelf = bookShelf.toStdString();
}

void LFurniture::setFloorRug(const QString & floorRug)
{
    this->floorRug = floorRug.toStdString();
}

void LFurniture::setLamps(const QString & lamps)
{
    this->lamps = lamps.toStdString();
}

void LFurniture::setDecItems(const QString & decItems)
{
    this->decItems = decItems.toStdString();
}

void LFurniture::setSofaPath(const QString &path)
{
    this->setSofa(path);
}

void LFurniture::setTablePath(const QString &path)
{
    this->setTable(path);
}

void LFurniture::setLampsPath(const QString &path)
{
    this->setLamps(path);
}

void LFurniture::setTvStandPath(const QString &path)
{
    this->setTvStand(path);
}

void LFurniture::setBookShelfPath(const QString &path)
{
    this->setBookShelf(path);
}
void LFurniture::setFloorRugPath(const QString &path)
{
    this->setFloorRug(path);
}

void LFurniture::setDecItemsPath(const QString &path)
{
    this->setDecItems(path);
}
