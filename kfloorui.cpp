#include "kfloorui.h"
#include "ui_kfloorui.h"
#include <QPixmap>
#include <QMessageBox>
#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

kfloorui::kfloorui(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::kfloorui)
{
    ui->setupUi(this);
    QPixmap imgbtn1("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/flooring4.jpg");
    QPixmap imgbtn2("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/flooring5.jpg");
    QPixmap imgbtn3("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/flooring6.jpg");

    QIcon icon1(imgbtn1.scaled(ui->kfloor1btn->size(), Qt::KeepAspectRatio));
    QIcon icon2(imgbtn2.scaled(ui->kfloor2btn->size(), Qt::KeepAspectRatio));
    QIcon icon3(imgbtn3.scaled(ui->kfloor3btn->size(), Qt::KeepAspectRatio));

    ui->kfloor1btn->setIcon(icon1);
    ui->kfloor2btn->setIcon(icon2);
    ui->kfloor3btn->setIcon(icon3);

    ui->kfloor1btn->setIconSize(ui->kfloor1btn->size());
    ui->kfloor2btn->setIconSize(ui->kfloor2btn->size());
    ui->kfloor3btn->setIconSize(ui->kfloor3btn->size());

    ui->kfloor1btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/flooring4.jpg");
    ui->kfloor2btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/flooring5.jpg");
    ui->kfloor3btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/flooring6.jpg");

    // Connect each button's clicked signal to the displayImage slot
    connect(ui->kfloor1btn, &QPushButton::clicked, this, &kfloorui::displayImage);
    connect(ui->kfloor2btn, &QPushButton::clicked, this, &kfloorui::displayImage);
    connect(ui->kfloor3btn, &QPushButton::clicked, this, &kfloorui::displayImage);
}

kfloorui::~kfloorui()
{
    delete ui;
}

void kfloorui::displayImage()
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

                kfloor = new (KFlooring);
                QObject::connect(&msgBox, &QMessageBox::accepted, [=]() {
                    kfloor->setFlooringNamePath(selectedImagePath);
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
                file<<kfloor->getFlooringName()<<endl;
                file.close();
                cout<< kfloor->getFlooringName()<<endl;

                delete kfloor;
            }
            else
            {
                QMessageBox::warning(this, "Error", "Failed to load image.", QMessageBox::Ok);
            }
        }
    }
}
