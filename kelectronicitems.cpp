#include "kelectronicitems.h"
#include <iostream>
#include "fridge.h"
#include "oven.h"
#include "stove.h"
#include <QScreen>


using namespace std;

KElectronicItems::KElectronicItems():refridgerator(),microwaveOven(),stove()
{

}

KElectronicItems::KElectronicItems(string fridge,string oven,string stove):refridgerator(fridge),microwaveOven(oven),stove(stove)
{

}

KElectronicItems::KElectronicItems(const KElectronicItems & eItems):refridgerator(eItems.refridgerator),microwaveOven(eItems.microwaveOven),stove(eItems.stove)
{

}

KElectronicItems::~KElectronicItems()
{

}

string KElectronicItems::getFridge()
{
    return refridgerator;
}

string KElectronicItems::getOven()
{
    return microwaveOven;
}

string KElectronicItems::getStove()
{
    return stove;
}

void KElectronicItems::setFridge(const QString &refridgerator)
{
    this->refridgerator=refridgerator.toStdString();
}

void KElectronicItems::setOven(const QString &microwaveOven)
{
    this->microwaveOven=microwaveOven.toStdString();

}
void KElectronicItems::setStove(const QString &stove)
{
    this->stove=stove.toStdString();
}

void KElectronicItems::setFridgePath(const QString & path )
{
    this->setFridge(path);
}
void KElectronicItems::setOvenPath(const QString & path )
{
    this->setOven(path);
}
void KElectronicItems::setStovePath(const QString & path )
{
    this->setStove(path);
}
