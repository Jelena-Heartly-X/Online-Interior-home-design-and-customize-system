#include "interiordesign.h"
#include "ui_interiordesign.h"
#include "bedroomdesign.h"
#include "kitchendesign.h"
#include "livingroomdesign.h"
#include <QPixmap>
#include <QScreen>

InteriorDesign::InteriorDesign(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::InteriorDesign)
{
    ui->setupUi(this);
    ui->Label->setAlignment(Qt::AlignCenter);
    ui->Label_2->setAlignment(Qt::AlignCenter);
}

InteriorDesign::~InteriorDesign()
{
    delete ui;
}

void InteriorDesign::on_btn_bedroom_clicked()
{
    bedroomDesign bedroom;
    QScreen *primaryScreen = QApplication::primaryScreen();
    QRect screenGeometry = primaryScreen->geometry();
    bedroom.resize(screenGeometry.size());
    bedroom.setModal(true);
    bedroom.exec();
}


void InteriorDesign::on_btn_livingroom_clicked()
{
    LivingroomDesign livingRoom;
    QScreen *primaryScreen = QApplication::primaryScreen();
    QRect screenGeometry = primaryScreen->geometry();
    livingRoom.resize(screenGeometry.size());
    livingRoom.setModal(true);
    livingRoom.exec();
}


void InteriorDesign::on_btn_kitchen_clicked()
{
    kitchenDesign kitchen;
    QScreen *primaryScreen = QApplication::primaryScreen();
    QRect screenGeometry = primaryScreen->geometry();
    kitchen.resize(screenGeometry.size());
    kitchen.setModal(true);
    kitchen.exec();
}

