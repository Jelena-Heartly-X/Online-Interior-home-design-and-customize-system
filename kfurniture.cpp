#include "kfurniture.h"
#include <iostream>

using namespace std;

KFurniture::KFurniture():diningTable(""),counterTop(""),cabinet(""),sink("")
{

}

KFurniture::KFurniture(string diningTable,string counterTop,string cabinet,string sink):diningTable(diningTable),counterTop(counterTop),cabinet(cabinet),sink(sink)
{

}

KFurniture::KFurniture(const KFurniture & fur):diningTable(fur.diningTable),counterTop(fur.counterTop),cabinet(fur.cabinet),sink(fur.sink)
{

}

KFurniture::~KFurniture()
{

}

string KFurniture::getDiningTable()
{
    return diningTable;
}

string KFurniture::getCounterTop()
{
    return counterTop;
}

string KFurniture::getCabinet()
{
    return cabinet;
}

string KFurniture::getSink()
{
    return sink;
}

void KFurniture::setDiningTable(const QString & diningTable)
{
    this->diningTable = diningTable.toStdString();
}

void KFurniture::setCounterTop(const QString & counterTop)
{
    this->counterTop = counterTop.toStdString();
}

void KFurniture::setCabinet(const QString & cabinet)
{
    this->cabinet = cabinet.toStdString();
}

void KFurniture::setSink(const QString & sink)
{
    this->sink = sink.toStdString();
}

void KFurniture::setDiningTablePath(const QString &path)
{
    this->setDiningTable(path);
}

void KFurniture::setCabinetPath(const QString &path)
{
    this->setCabinet(path);
}

void KFurniture::setCounterTopPath(const QString &path)
{
    this->setCounterTop(path);
}

void KFurniture::setSinkPath(const QString &path)
{
    this->setSink(path);
}
