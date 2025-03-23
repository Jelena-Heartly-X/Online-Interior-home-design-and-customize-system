#include "lfloorui.h"
#include "ui_lfloorui.h"

#include "Flooring.h"
#include <iostream>
#include <QMessageBox>
#include "fstream"
#include <cassert>

using namespace std;

LFlooring::LFlooring():flooringName()
{

}

LFlooring::LFlooring(string name):flooringName(name)
{

}

LFlooring::LFlooring(const LFlooring & floor):flooringName(floor.flooringName)
{

}

LFlooring::~LFlooring()
{

}
string LFlooring::getFlooringName()
{
    return flooringName;
}

void LFlooring::setFlooringName(const QString & name)
{
    flooringName = name.toStdString();
}

void LFlooring::setFlooringNamePath(const QString & path)
{
    this->setFlooringName(path);
}
