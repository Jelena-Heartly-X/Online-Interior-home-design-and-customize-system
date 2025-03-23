#include "lfloorui.h"
#include "ui_lfloorui.h"

#include "Flooring.h"
#include <iostream>
#include <QMessageBox>
#include "fstream"
#include <cassert>

using namespace std;

lfloorui::lfloorui(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::lfloorui)
{
    ui->setupUi(this);
    QPixmap imgbtn1("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/flooring3.jpg");
    QPixmap imgbtn2("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/flooring4.jpg");
    QPixmap imgbtn3("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/flooring5.jpg");

    QIcon icon1(imgbtn1.scaled(ui->lfloor1btn->size(), Qt::KeepAspectRatio));
    QIcon icon2(imgbtn2.scaled(ui->lfloor2btn->size(), Qt::KeepAspectRatio));
    QIcon icon3(imgbtn3.scaled(ui->lfloor3btn->size(), Qt::KeepAspectRatio));

    ui->lfloor1btn->setIcon(icon1);
    ui->lfloor2btn->setIcon(icon2);
    ui->lfloor3btn->setIcon(icon3);

    ui->lfloor1btn->setIconSize(ui->lfloor1btn->size());
    ui->lfloor2btn->setIconSize(ui->lfloor2btn->size());
    ui->lfloor3btn->setIconSize(ui->lfloor3btn->size());

    ui->lfloor1btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/flooring3.jpg");
    ui->lfloor2btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/flooring4.jpg");
    ui->lfloor3btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/flooring5.jpg");

    // Connect each button's clicked signal to the displayImage slot
    connect(ui->lfloor1btn, &QPushButton::clicked, this, &lfloorui::displayImage);
    connect(ui->lfloor2btn, &QPushButton::clicked, this, &lfloorui::displayImage);
    connect(ui->lfloor3btn, &QPushButton::clicked, this, &lfloorui::displayImage);
}

lfloorui::~lfloorui()
{
    delete ui;
}

void lfloorui::displayImage()
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

                lfloor = new (LFlooring);
                QObject::connect(&msgBox, &QMessageBox::accepted, [=]() {
                    lfloor->setFlooringNamePath(selectedImagePath);
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
                file<<lfloor->getFlooringName()<<endl;
                file.close();
                cout<<lfloor->getFlooringName()<<endl;

                delete lfloor;
            }
            else
            {
                QMessageBox::warning(this, "Error", "Failed to load image.", QMessageBox::Ok);
            }
        }
    }
}
