#include "kitchendesign.h"
#include "ui_kitchendesign.h"
#include "kfloorui.h"
#include "kfurui.h"
#include "kthemeui.h"
#include "kelectronicitems1.h"
#include "viewkitchen.h"
#include <QScreen>

kitchenDesign::kitchenDesign(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::kitchenDesign)
{
    ui->setupUi(this);
}

kitchenDesign::~kitchenDesign()
{
    delete ui;
}

Kitchen::Kitchen():kitcFur(),kitcFloor(),kitcTheme()
{

}

Kitchen::Kitchen(KFurniture fur,KFlooring floor,KTheme theme):kitcFur(fur),kitcFloor(floor),kitcTheme(theme)
{

}

Kitchen::Kitchen(const Kitchen & obj):kitcFur(obj.kitcFur),kitcFloor(obj.kitcFloor),kitcTheme(obj.kitcTheme)
{

}

Kitchen::~Kitchen()
{

}

void kitchenDesign::on_kfurbtn_clicked()
{
    kfurui kfur;
    QScreen *primaryScreen = QApplication::primaryScreen();
    QRect screenGeometry = primaryScreen->geometry();
    kfur.resize(screenGeometry.size());
    kfur.setModal(true);
    kfur.exec();
}


void kitchenDesign::on_kfloorbtn_clicked()
{
    kfloorui kfloor;
    QScreen *primaryScreen = QApplication::primaryScreen();
    QRect screenGeometry = primaryScreen->geometry();
    kfloor.resize(screenGeometry.size());
    kfloor.setModal(true);
    kfloor.exec();
}


void kitchenDesign::on_kthemebtn_clicked()
{
    kthemeui ktheme;
    QScreen *primaryScreen = QApplication::primaryScreen();
    QRect screenGeometry = primaryScreen->geometry();
    ktheme.resize(screenGeometry.size());
    ktheme.setModal(true);
    ktheme.exec();
}


void kitchenDesign::on_keitembtn_clicked()
{
    kelectronicitems1 keitems;
    QScreen *primaryScreen = QApplication::primaryScreen();
    QRect screenGeometry = primaryScreen->geometry();
    keitems.resize(screenGeometry.size());
    keitems.setModal(true);
    keitems.exec();
}


void kitchenDesign::on_viewbtn_clicked()
{
    viewkitchen kitchen;
    QScreen *primaryScreen = QApplication::primaryScreen();
    QRect screenGeometry = primaryScreen->geometry();
    kitchen.resize(screenGeometry.size());
    kitchen.setModal(true);
    kitchen.exec();
}

