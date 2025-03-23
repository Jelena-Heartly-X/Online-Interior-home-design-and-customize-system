#include "lamps.h"
#include "ui_lamps.h"
#include <QPixmap>
#include <QMessageBox>
#include <iostream>
#include <cassert>
#include <fstream>

using namespace std;

lamps::lamps(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::lamps)
{
    ui->setupUi(this);
    QPixmap imgbtn1("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/lamp4.jpg");
    QPixmap imgbtn2("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/lamp5.jpg");
    QPixmap imgbtn3("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/lamp6.jpg");

    QIcon icon1(imgbtn1.scaled(ui->lamp1btn->size(), Qt::KeepAspectRatio));
    QIcon icon2(imgbtn2.scaled(ui->lamp2btn->size(), Qt::KeepAspectRatio));
    QIcon icon3(imgbtn3.scaled(ui->lamp3btn->size(), Qt::KeepAspectRatio));

    ui->lamp1btn->setIcon(icon1);
    ui->lamp2btn->setIcon(icon2);
    ui->lamp3btn->setIcon(icon3);

    ui->lamp1btn->setIconSize(ui->lamp1btn->size());
    ui->lamp2btn->setIconSize(ui->lamp2btn->size());
    ui->lamp3btn->setIconSize(ui->lamp3btn->size());

    ui->lamp1btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/lamp4.jpg");
    ui->lamp2btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/lamp5.jpg");
    ui->lamp3btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/lamp6.jpg");

    // Connect each button's clicked signal to the displayImage slot
    connect(ui->lamp1btn, &QPushButton::clicked, this, &lamps::displayImage);
    connect(ui->lamp2btn, &QPushButton::clicked, this, &lamps::displayImage);
    connect(ui->lamp3btn, &QPushButton::clicked, this, &lamps::displayImage);
}


lamps::~lamps()
{
    delete ui;
}

void lamps::displayImage()
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
                    bfur->setLampsPath(selectedImagePath);
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
                file<<bfur->getLamps()<<endl;
                file.close();
                cout << bfur->getLamps() << endl;

                delete bfur;
            }
            else
            {
                QMessageBox::warning(this, "Error", "Failed to load image.", QMessageBox::Ok);
            }
        }
    }
}
