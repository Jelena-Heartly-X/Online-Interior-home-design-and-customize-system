#include "ldecitems.h"
#include "ui_ldecitems.h"
#include "Furniture.h"
#include "lfurniture.h"

#include <QPixmap>
#include <string>
#include <QMessageBox>
#include <iostream>
#include <fstream>
#include <cassert>

ldecitems::ldecitems(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ldecitems)
{
    ui->setupUi(this);
    QPixmap imgbtn1("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/decItems2.jpg");
    QPixmap imgbtn2("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/decItems4.jpg");
    QPixmap imgbtn3("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/decItems6.jpg");

    QIcon icon1(imgbtn1.scaled(ui->decItems1btn->size(), Qt::KeepAspectRatio));
    QIcon icon2(imgbtn2.scaled(ui->decItems2btn->size(), Qt::KeepAspectRatio));
    QIcon icon3(imgbtn3.scaled(ui->decItems3btn->size(), Qt::KeepAspectRatio));

    ui->decItems1btn->setIcon(icon1);
    ui->decItems2btn->setIcon(icon2);
    ui->decItems3btn->setIcon(icon3);

    ui->decItems1btn->setIconSize(ui->decItems1btn->size());
    ui->decItems2btn->setIconSize(ui->decItems2btn->size());
    ui->decItems3btn->setIconSize(ui->decItems3btn->size());

    // Set imagePath property for each button
    ui->decItems1btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/decItems2.jpg");
    ui->decItems2btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/decItems4.jpg");
    ui->decItems3btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/decItems6.jpg");

    // Connect each button's clicked signal to the displayImage slot
    connect(ui->decItems1btn, &QPushButton::clicked, this, &ldecitems::displayImage);
    connect(ui->decItems2btn, &QPushButton::clicked, this, &ldecitems::displayImage);
    connect(ui->decItems3btn, &QPushButton::clicked, this, &ldecitems::displayImage);
}

ldecitems::~ldecitems()
{
    delete ui;
}

void ldecitems::displayImage()
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
                    lfur->setDecItemsPath(selectedImagePath);
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
                file<<lfur->getDecItems()<<endl;
                file.close();
                cout<<lfur->getDecItems()<<endl;

                delete lfur;
            }
            else
            {
                QMessageBox::warning(this, "Error", "Failed to load image.", QMessageBox::Ok);
            }
        }
    }
}
