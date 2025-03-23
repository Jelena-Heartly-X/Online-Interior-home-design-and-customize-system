#include "oven.h"
#include "ui_oven.h"
#include "kelectronicitems.h"
#include "kelectronicitems1.h"
#include <QPixmap>
#include <string>
#include <QMessageBox>
#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;
oven::oven(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::oven)
{
    ui->setupUi(this);
    QPixmap imgbtn1("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/oven1.jpg");
    QPixmap imgbtn2("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/oven2.jpg");
    QPixmap imgbtn3("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/oven3.jpg");

    QIcon icon1(imgbtn1.scaled(ui->oven1btn->size(), Qt::KeepAspectRatio));
    QIcon icon2(imgbtn2.scaled(ui->oven2btn->size(), Qt::KeepAspectRatio));
    QIcon icon3(imgbtn3.scaled(ui->oven3btn->size(), Qt::KeepAspectRatio));

    ui->oven1btn->setIcon(icon1);
    ui->oven2btn->setIcon(icon2);
    ui->oven3btn->setIcon(icon3);

    ui->oven1btn->setIconSize(ui->oven1btn->size());
    ui->oven2btn->setIconSize(ui->oven2btn->size());
    ui->oven3btn->setIconSize(ui->oven3btn->size());

    // Set imagePath property for each button
    ui->oven1btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/oven1.jpg");
    ui->oven2btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/oven2.jpg");
    ui->oven3btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/oven3.jpg");


    // Connect each button's clicked signal to the displayImage slot
    connect(ui->oven1btn, &QPushButton::clicked, this, &oven::displayImage);
    connect(ui->oven2btn, &QPushButton::clicked, this, &oven::displayImage);
    connect(ui->oven3btn, &QPushButton::clicked, this, &oven::displayImage);

}

oven::~oven()
{
    delete ui;
}

void oven ::displayImage()
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
                    eitem->setOvenPath(selectedImagePath);
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
                file<<eitem->getOven()<<endl;
                file.close();
                cout<< eitem->getOven()<<endl;

                delete eitem;
            }
            else
            {
                QMessageBox::warning(this, "Error", "Failed to load image.", QMessageBox::Ok);
            }
        }
    }
}
