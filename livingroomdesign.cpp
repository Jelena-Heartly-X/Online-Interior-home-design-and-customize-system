#include "livingroomdesign.h"
#include "ui_livingroomdesign.h"
#include "lfurui.h"
#include "lfloorui.h"
#include "lthemeui.h"
#include <QScreen>
#include "viewlivingroom.h"

LivingroomDesign::LivingroomDesign(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LivingroomDesign)
{
    ui->setupUi(this);
}

LivingroomDesign::~LivingroomDesign()
{
    delete ui;
}

LivingRoom::LivingRoom():livFur(),livFloor(),livTheme()
{

}

LivingRoom::LivingRoom(LFurniture fur,LFlooring floor,LTheme theme):livFur(fur),livFloor(floor),livTheme(theme)
{

}

LivingRoom::LivingRoom(const LivingRoom & obj):livFur(obj.livFur),livFloor(obj.livFloor),livTheme(obj.livTheme)
{

}

LivingRoom::~LivingRoom()
{

}

void LivingroomDesign::on_lfurbtn_clicked()
{
    lfurui lfur;
    QScreen *primaryScreen = QApplication::primaryScreen();
    QRect screenGeometry = primaryScreen->geometry();
    lfur.resize(screenGeometry.size());
    lfur.setModal(true);
    lfur.exec();
}


void LivingroomDesign::on_lfloorbtn_clicked()
{
    lfloorui lfloor;
    QScreen *primaryScreen = QApplication::primaryScreen();
    QRect screenGeometry = primaryScreen->geometry();
    lfloor.resize(screenGeometry.size());
    lfloor.setModal(true);
    lfloor.exec();
}


void LivingroomDesign::on_lthemebtn_clicked()
{
    lthemeui ltheme;
    QScreen *primaryScreen = QApplication::primaryScreen();
    QRect screenGeometry = primaryScreen->geometry();
    ltheme.resize(screenGeometry.size());
    ltheme.setModal(true);
    ltheme.exec();
}


void LivingroomDesign::on_viewbtn_clicked()
{
    viewlivingroom livingroom;
    QScreen *primaryScreen = QApplication::primaryScreen();
    QRect screenGeometry = primaryScreen->geometry();
    livingroom.resize(screenGeometry.size());
    livingroom.setModal(true);
    livingroom.exec();
}

