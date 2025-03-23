#include "bed.h"
#include "ui_bed.h"
#include "Furniture.h"
#include "bfurniture.h"
#include <QPixmap>
#include <string>
#include <QMessageBox>
#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

bed::bed(QWidget *parent) : QDialog(parent), ui(new Ui::bed)
{
    ui->setupUi(this);

    QPixmap imgbtn1("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/bed1.jpg");
    QPixmap imgbtn2("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/bed2.jpg");
    QPixmap imgbtn3("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/bed3.jpg");

    QIcon icon1(imgbtn1.scaled(ui->bed1btn->size(), Qt::KeepAspectRatio));
    QIcon icon2(imgbtn2.scaled(ui->bed2btn->size(), Qt::KeepAspectRatio));
    QIcon icon3(imgbtn3.scaled(ui->bed3btn->size(), Qt::KeepAspectRatio));

    ui->bed1btn->setIcon(icon1);
    ui->bed2btn->setIcon(icon2);
    ui->bed3btn->setIcon(icon3);

    ui->bed1btn->setIconSize(ui->bed1btn->size());
    ui->bed2btn->setIconSize(ui->bed2btn->size());
    ui->bed3btn->setIconSize(ui->bed3btn->size());

    // Set imagePath property for each button
    ui->bed1btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/bed1.jpg");
    ui->bed2btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/bed2.jpg");
    ui->bed3btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/bed3.jpg");

    // Connect each button's clicked signal to the displayImage slot
    connect(ui->bed1btn, &QPushButton::clicked, this, &bed::displayImage);
    connect(ui->bed2btn, &QPushButton::clicked, this, &bed::displayImage);
    connect(ui->bed3btn, &QPushButton::clicked, this, &bed::displayImage);
}

bed::~bed()
{
    delete ui;
}

void bed::displayImage()
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

                bfur = new (BFurniture);
                QObject::connect(&msgBox, &QMessageBox::accepted, [=]() {
                    bfur->setBedPath(selectedImagePath);
                });

                msgBox.exec();
                fstream file;
                file.open("bedroom_info.txt", ios::app);
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
                file<<bfur->getBed()<<endl;
                file.close();
                cout<< bfur->getBed()<<endl;

                delete bfur;
            }
            else
            {
                QMessageBox::warning(this, "Error", "Failed to load image.", QMessageBox::Ok);
            }
        }
    }
}
