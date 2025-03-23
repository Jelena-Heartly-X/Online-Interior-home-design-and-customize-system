#include "coffeetable.h"
#include "ui_coffeetable.h"
#include "Furniture.h"
#include "lfurniture.h"

#include <QPixmap>
#include <string>
#include <QMessageBox>
#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

coffeeTable::coffeeTable(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::coffeeTable)
{
    ui->setupUi(this);
    QPixmap imgbtn1("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/coffeeTable1.jpg");
    QPixmap imgbtn2("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/coffeeTable2.jpg");
    QPixmap imgbtn3("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/coffeeTable3.jpg");

    QIcon icon1(imgbtn1.scaled(ui->coffee1btn->size(), Qt::KeepAspectRatio));
    QIcon icon2(imgbtn2.scaled(ui->coffee2btn->size(), Qt::KeepAspectRatio));
    QIcon icon3(imgbtn3.scaled(ui->coffee3btn->size(), Qt::KeepAspectRatio));

    ui->coffee1btn->setIcon(icon1);
    ui->coffee2btn->setIcon(icon2);
    ui->coffee3btn->setIcon(icon3);

    ui->coffee1btn->setIconSize(ui->coffee1btn->size());
    ui->coffee2btn->setIconSize(ui->coffee2btn->size());
    ui->coffee3btn->setIconSize(ui->coffee3btn->size());

    ui->coffee1btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/coffeeTable1.jpg");
    ui->coffee2btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/coffeeTable2.jpg");
    ui->coffee3btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/coffeeTable3.jpg");

    connect(ui->coffee1btn, &QPushButton::clicked, this, &coffeeTable::displayImage);
    connect(ui->coffee2btn, &QPushButton::clicked, this, &coffeeTable::displayImage);
    connect(ui->coffee3btn, &QPushButton::clicked, this, &coffeeTable::displayImage);
}

coffeeTable::~coffeeTable()
{
    delete ui;
}

void coffeeTable::displayImage()
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
                    lfur->setTablePath(selectedImagePath);
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
                file<<lfur->getTable()<<endl;
                file.close();
                cout<<lfur->getTable()<<endl;

                delete lfur;
            }
            else
            {
                QMessageBox::warning(this, "Error", "Failed to load image.", QMessageBox::Ok);
            }
        }
    }
}
