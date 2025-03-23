#include "lfloorrug.h"
#include "ui_lfloorrug.h"
#include "Furniture.h"
#include "lfurniture.h"

#include <QPixmap>
#include <string>
#include <QMessageBox>
#include <iostream>
#include <fstream>
#include <cassert>

lfloorRug::lfloorRug(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::lfloorRug)
{
    ui->setupUi(this);
    QPixmap imgbtn1("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/rug1.jpg");
    QPixmap imgbtn2("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/rug2.jpg");
    QPixmap imgbtn3("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/rug3.jpg");

    QIcon icon1(imgbtn1.scaled(ui->rug1btn->size(), Qt::KeepAspectRatio));
    QIcon icon2(imgbtn2.scaled(ui->rug2btn->size(), Qt::KeepAspectRatio));
    QIcon icon3(imgbtn3.scaled(ui->rug3btn->size(), Qt::KeepAspectRatio));

    ui->rug1btn->setIcon(icon1);
    ui->rug2btn->setIcon(icon2);
    ui->rug3btn->setIcon(icon3);

    ui->rug1btn->setIconSize(ui->rug1btn->size());
    ui->rug2btn->setIconSize(ui->rug2btn->size());
    ui->rug3btn->setIconSize(ui->rug3btn->size());

    // Set imagePath property for each button
    ui->rug1btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/rug1.jpg");
    ui->rug2btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/rug2.jpg");
    ui->rug3btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/rug3.jpg");

    // Connect each button's clicked signal to the displayImage slot
    connect(ui->rug1btn, &QPushButton::clicked, this, &lfloorRug::displayImage);
    connect(ui->rug2btn, &QPushButton::clicked, this, &lfloorRug::displayImage);
    connect(ui->rug3btn, &QPushButton::clicked, this, &lfloorRug::displayImage);

}

lfloorRug::~lfloorRug()
{
    delete ui;
}

void lfloorRug::displayImage()
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
                    lfur->setFloorRugPath(selectedImagePath);
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
                file<<lfur->getFloorRug()<<endl;
                file.close();
                cout<<lfur->getFloorRug()<<endl;

                delete lfur;
            }
            else
            {
                QMessageBox::warning(this, "Error", "Failed to load image.", QMessageBox::Ok);
            }
        }
    }
}
