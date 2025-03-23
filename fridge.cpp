#include "fridge.h"
#include "ui_fridge.h"
#include "kelectronicitems.h"
#include "kelectronicitems1.h"
#include <QPixmap>
#include <string>
#include <QMessageBox>
#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

fridge::fridge(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::fridge)
{
    ui->setupUi(this);
    QPixmap imgbtn1("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/fridge1.jpg");
    QPixmap imgbtn2("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/fridge2.jpg");
    QPixmap imgbtn3("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/fridge3.jpg");

    QIcon icon1(imgbtn1.scaled(ui->fridge1btn->size(), Qt::KeepAspectRatio));
    QIcon icon2(imgbtn2.scaled(ui->fridge2btn->size(), Qt::KeepAspectRatio));
    QIcon icon3(imgbtn3.scaled(ui->fridge3btn->size(), Qt::KeepAspectRatio));

    ui->fridge1btn->setIcon(icon1);
    ui->fridge2btn->setIcon(icon2);
    ui->fridge3btn->setIcon(icon3);

    ui->fridge1btn->setIconSize(ui->fridge1btn->size());
    ui->fridge2btn->setIconSize(ui->fridge2btn->size());
    ui->fridge3btn->setIconSize(ui->fridge3btn->size());

    ui->fridge1btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/fridge1.jpg");
    ui->fridge2btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/fridge2.jpg");
    ui->fridge3btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/fridge3.jpg");

    // Connect each button's clicked signal to the displayImage slot
    connect(ui->fridge1btn, &QPushButton::clicked, this, &fridge::displayImage);
    connect(ui->fridge2btn, &QPushButton::clicked, this, &fridge::displayImage);
    connect(ui->fridge3btn, &QPushButton::clicked, this, &fridge::displayImage);

}

fridge::~fridge()
{
    delete ui;
}
void fridge::displayImage()
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

                eitem = new (KElectronicItems);
                QObject::connect(&msgBox, &QMessageBox::accepted, [=]() {
                    eitem->setFridgePath(selectedImagePath);
                });

                msgBox.exec();
                fstream file;
                file.open("kitchen_info.txt", ios::app);
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
                file<<eitem->getFridge()<<endl;
                file.close();
                cout<< eitem->getFridge()<<endl;

                delete eitem;
            }
            else
            {
                QMessageBox::warning(this, "Error", "Failed to load image.", QMessageBox::Ok);
            }
        }
    }
}
