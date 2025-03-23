#include "bflooring1.h"
#include "ui_bflooring1.h"
#include "Flooring.h"
#include <iostream>
#include <QMessageBox>
#include "fstream"
#include <cassert>

using namespace std;

bflooring1::bflooring1(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::bflooring1)
{
    ui->setupUi(this);
    QPixmap imgbtn1("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/flooring1.jpg");
    QPixmap imgbtn2("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/flooring2.jpg");
    QPixmap imgbtn3("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/flooring3.jpg");

    QIcon icon1(imgbtn1.scaled(ui->bflooring1btn->size(), Qt::KeepAspectRatio));
    QIcon icon2(imgbtn2.scaled(ui->bflooring2btn->size(), Qt::KeepAspectRatio));
    QIcon icon3(imgbtn3.scaled(ui->bflooring3btn->size(), Qt::KeepAspectRatio));

    ui->bflooring1btn->setIcon(icon1);
    ui->bflooring2btn->setIcon(icon2);
    ui->bflooring3btn->setIcon(icon3);

    ui->bflooring1btn->setIconSize(ui->bflooring1btn->size());
    ui->bflooring2btn->setIconSize(ui->bflooring2btn->size());
    ui->bflooring3btn->setIconSize(ui->bflooring3btn->size());

    ui->bflooring1btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/flooring1.jpg");
    ui->bflooring2btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/flooring2.jpg");
    ui->bflooring3btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/flooring3.jpg");

    // Connect each button's clicked signal to the displayImage slot
    connect(ui->bflooring1btn, &QPushButton::clicked, this, &bflooring1::displayImage);
    connect(ui->bflooring2btn, &QPushButton::clicked, this, &bflooring1::displayImage);
    connect(ui->bflooring3btn, &QPushButton::clicked, this, &bflooring1::displayImage);
}

bflooring1::~bflooring1()
{
    delete ui;
}

BFlooring::BFlooring():flooringName("-")
{

}

BFlooring::BFlooring(string name):flooringName(name)
{

}

BFlooring::BFlooring(const BFlooring & floor):flooringName(floor.flooringName)
{

}

BFlooring::~BFlooring()
{

}

string BFlooring::getFlooringName()
{
    return flooringName;
}

void BFlooring::setFlooringName(const QString & flooring)
{
    this->flooringName=flooring.toStdString();
}

void BFlooring::setFlooringNamePath(const QString & path)
{
    this->setFlooringName(path);
}

void bflooring1::displayImage()
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

                bfloor = new (BFlooring);
                QObject::connect(&msgBox, &QMessageBox::accepted, [=]() {
                    bfloor->setFlooringNamePath(selectedImagePath);
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
                file<<bfloor->getFlooringName()<<endl;
                file.close();
                cout<< bfloor->getFlooringName()<<endl;

                delete bfloor;
            }
            else
            {
                QMessageBox::warning(this, "Error", "Failed to load image.", QMessageBox::Ok);
            }
        }
    }
}
