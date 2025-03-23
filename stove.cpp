#include "stove.h"
#include "ui_stove.h"
#include "kelectronicitems.h"
#include "kelectronicitems1.h"
#include <string>
#include <QMessageBox>
#include <iostream>
#include <fstream>
#include <cassert>
#include <QPixmap>

using namespace std;

stove::stove(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::stove)
{
    ui->setupUi(this);
    QPixmap imgbtn1("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/stove1.jpg");
    QPixmap imgbtn2("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/stove2.jpg");
    QPixmap imgbtn3("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/stove3.jpg");

    QIcon icon1(imgbtn1.scaled(ui->stove1btn->size(), Qt::KeepAspectRatio));
    QIcon icon2(imgbtn2.scaled(ui->stove2btn->size(), Qt::KeepAspectRatio));
    QIcon icon3(imgbtn3.scaled(ui->stove3btn->size(), Qt::KeepAspectRatio));

    ui->stove1btn->setIcon(icon1);
    ui->stove2btn->setIcon(icon2);
    ui->stove3btn->setIcon(icon3);

    ui->stove1btn->setIconSize(ui->stove1btn->size());
    ui->stove2btn->setIconSize(ui->stove2btn->size());
    ui->stove3btn->setIconSize(ui->stove3btn->size());

    // Set imagePath property for each button
    ui->stove1btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/stove1.jpg");
    ui->stove2btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/stove2.jpg");
    ui->stove3btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/stove3.jpg");

    // Connect each button's clicked signal to the displayImage slot
    connect(ui->stove1btn, &QPushButton::clicked, this, &stove::displayImage);
    connect(ui->stove2btn, &QPushButton::clicked, this, &stove::displayImage);
    connect(ui->stove3btn, &QPushButton::clicked, this, &stove::displayImage);

}

stove::~stove()
{
    delete ui;
}

void stove::displayImage()
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
                    eitem->setStovePath(selectedImagePath);
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
                file<<eitem->getStove()<<endl;
                file.close();
                cout<< eitem->getStove()<<endl;

                delete eitem;
            }
            else
            {
                QMessageBox::warning(this, "Error", "Failed to load image.", QMessageBox::Ok);
            }
        }
    }
}
