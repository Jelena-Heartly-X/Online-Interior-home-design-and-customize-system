#include "tvstand.h"
#include "ui_tvstand.h"
#include "Furniture.h"
#include "lfurniture.h"

#include <QPixmap>
#include <string>
#include <QMessageBox>
#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;
tvstand::tvstand(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::tvstand)
{
    ui->setupUi(this);
    QPixmap imgbtn1("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/tvstand1.jpg");
    QPixmap imgbtn2("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/tvstand2.jpg");
    QPixmap imgbtn3("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/tvstand3.jpg");

    QIcon icon1(imgbtn1.scaled(ui->tvStand1btn->size(), Qt::KeepAspectRatio));
    QIcon icon2(imgbtn2.scaled(ui->tvStand2btn->size(), Qt::KeepAspectRatio));
    QIcon icon3(imgbtn3.scaled(ui->tvStand3btn->size(), Qt::KeepAspectRatio));

    ui->tvStand1btn->setIcon(icon1);
    ui->tvStand2btn->setIcon(icon2);
    ui->tvStand3btn->setIcon(icon3);

    ui->tvStand1btn->setIconSize(ui->tvStand1btn->size());
    ui->tvStand2btn->setIconSize(ui->tvStand2btn->size());
    ui->tvStand3btn->setIconSize(ui->tvStand3btn->size());

    // Set imagePath property for each button
    ui->tvStand1btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/tvstand1.jpg");
    ui->tvStand2btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/tvstand2.jpg");
    ui->tvStand3btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/tvstand3.jpg");

    // Connect each button's clicked signal to the displayImage slot
    connect(ui->tvStand1btn, &QPushButton::clicked, this, &tvstand::displayImage);
    connect(ui->tvStand2btn, &QPushButton::clicked, this, &tvstand::displayImage);
    connect(ui->tvStand3btn, &QPushButton::clicked, this, &tvstand::displayImage);

}

tvstand::~tvstand()
{
    delete ui;
}
void tvstand::displayImage()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button)
    {
        selectedImagePath = button->property("imagePath").toString();
        QString imagePath = button->property("imagePath").toString();
        if (!imagePath.isEmpty()) {
            QPixmap image(imagePath);
            if (!image.isNull())
            {
                QMessageBox msgBox;
                msgBox.setWindowTitle("Selected Image");
                msgBox.setIconPixmap(image.scaled(300, 300, Qt::KeepAspectRatio));

                lfur = new (LFurniture);
                QObject::connect(&msgBox, &QMessageBox::accepted, [=]() {
                    lfur->setTvStandPath(selectedImagePath);
                });

                msgBox.exec();
                fstream file;
                file.open("livingroom_info.txt", ios::app);
                try
                {
                    if(!file.is_open())
                    {
                        string errorMsg="Login info File not found!!!";
                        throw errorMsg;
                    }
                }
                catch(string errorMsg)
                {
                    cout<<errorMsg<<endl;
                    assert(false);
                }
                file<<lfur->getTvStand()<<endl;
                file.close();
                cout<<lfur->getTvStand()<<endl;

                delete lfur;
            }
            else
            {
                QMessageBox::warning(this, "Error", "Failed to load image.", QMessageBox::Ok);
            }
        }
    }
}
