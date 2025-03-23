#include "kflooring.h"
#include <iostream>

using namespace std;

KFlooring::KFlooring():flooringName("-")
{

}

KFlooring::KFlooring(string name):flooringName(name)
{

}

KFlooring::KFlooring(const KFlooring & floor):flooringName(floor.flooringName)
{

}

KFlooring::~KFlooring()
{

}

string KFlooring::getFlooringName()
{
    return flooringName;
}

void KFlooring::setFlooringName(const QString & flooring)
{
    this->flooringName=flooring.toStdString();
}

void KFlooring::setFlooringNamePath(const QString & path)
{
    this->setFlooringName(path);
}
