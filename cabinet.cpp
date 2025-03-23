#include "cabinet.h"
#include "ui_cabinet.h"
#include "kfurniture.h"
#include "kfurui.h"
#include <QPixmap>
#include <QMessageBox>
#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

cabinet::cabinet(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::cabinet)
{
    ui->setupUi(this);
    QPixmap imgbtn1("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/cabinet1.jpg");
    QPixmap imgbtn2("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/cabinet2.jpg");
    QPixmap imgbtn3("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/cabinet3.jpg");

    QIcon icon1(imgbtn1.scaled(ui->cabinet1btn->size(), Qt::KeepAspectRatio));
    QIcon icon2(imgbtn2.scaled(ui->cabinet2btn->size(), Qt::KeepAspectRatio));
    QIcon icon3(imgbtn3.scaled(ui->cabinet3btn->size(), Qt::KeepAspectRatio));

    ui->cabinet1btn->setIcon(icon1);
    ui->cabinet2btn->setIcon(icon2);
    ui->cabinet3btn->setIcon(icon3);

    ui->cabinet1btn->setIconSize(ui->cabinet1btn->size());
    ui->cabinet2btn->setIconSize(ui->cabinet2btn->size());
    ui->cabinet3btn->setIconSize(ui->cabinet3btn->size());

    ui->cabinet1btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/cabinet1.jpg");
    ui->cabinet2btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/cabinet2.jpg");
    ui->cabinet3btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/cabinet3.jpg");

    // Connect each button's clicked signal to the displayImage slot
    connect(ui->cabinet1btn, &QPushButton::clicked, this, &cabinet::displayImage);
    connect(ui->cabinet2btn, &QPushButton::clicked, this, &cabinet::displayImage);
    connect(ui->cabinet3btn, &QPushButton::clicked, this, &cabinet::displayImage);
}

cabinet::~cabinet()
{
    delete ui;
}

void cabinet::displayImage()
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

                kfur = new KFurniture;
                QObject::connect(&msgBox, &QMessageBox::accepted, [=]() {
                    kfur->setCabinetPath(selectedImagePath);
                });

                msgBox.exec();
                fstream file;
                file.open("kitchen_info.txt",ios::app);
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
                file<<kfur->getCabinet()<<endl;
                file.close();
                cout<< kfur->getCabinet()<<endl;

                delete kfur;
            }
            else
            {
                QMessageBox::warning(this, "Error", "Failed to load image.", QMessageBox::Ok);
            }
        }
    }
}
