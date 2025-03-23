#include "sofa.h"
#include "ui_sofa.h"
#include "Furniture.h"
#include "lfurniture.h"

#include <QPixmap>
#include <string>
#include <QMessageBox>
#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

sofa::sofa(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::sofa)
{
    ui->setupUi(this);
    QPixmap imgbtn1("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/sofa1.jpg");
    QPixmap imgbtn2("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/sofa2.jpg");
    QPixmap imgbtn3("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/sofa3.jpg");

    QIcon icon1(imgbtn1.scaled(ui->sofa1btn->size(), Qt::KeepAspectRatio));
    QIcon icon2(imgbtn2.scaled(ui->sofa2btn->size(), Qt::KeepAspectRatio));
    QIcon icon3(imgbtn3.scaled(ui->sofa3btn->size(), Qt::KeepAspectRatio));

    ui->sofa1btn->setIcon(icon1);
    ui->sofa2btn->setIcon(icon2);
    ui->sofa3btn->setIcon(icon3);

    ui->sofa1btn->setIconSize(ui->sofa1btn->size());
    ui->sofa2btn->setIconSize(ui->sofa2btn->size());
    ui->sofa3btn->setIconSize(ui->sofa3btn->size());

    // Set imagePath property for each button
    ui->sofa1btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/sofa1.jpg");
    ui->sofa2btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/sofa2.jpg");
    ui->sofa3btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/sofa3.jpg");

    // Connect each button's clicked signal to the displayImage slot
    connect(ui->sofa1btn, &QPushButton::clicked, this, &sofa::displayImage);
    connect(ui->sofa2btn, &QPushButton::clicked, this, &sofa::displayImage);
    connect(ui->sofa3btn, &QPushButton::clicked, this, &sofa::displayImage);
}

sofa::~sofa()
{
    delete ui;
}

void sofa::displayImage()
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
                    lfur->setSofaPath(selectedImagePath);
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
                file<<lfur->getSofa()<<endl;
                file.close();
                cout<<lfur->getSofa()<<endl;

                delete lfur;
            }
            else
            {
                QMessageBox::warning(this, "Error", "Failed to load image.", QMessageBox::Ok);
            }
        }
    }
}
