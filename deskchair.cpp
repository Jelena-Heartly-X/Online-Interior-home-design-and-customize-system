#include "deskchair.h"
#include "ui_deskchair.h"
#include "Furniture.h"
#include <QPixmap>
#include <QMessageBox>
#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

deskchair::deskchair(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::deskchair)
{
    ui->setupUi(this);
    QPixmap imgbtn1("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/desk1.jpg");
    QPixmap imgbtn2("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/desk2.jpg");
    QPixmap imgbtn3("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/desk3.jpg");

    QIcon icon1(imgbtn1.scaled(ui->desk1btn->size(), Qt::KeepAspectRatio));
    QIcon icon2(imgbtn2.scaled(ui->desk2btn->size(), Qt::KeepAspectRatio));
    QIcon icon3(imgbtn3.scaled(ui->desk3btn->size(), Qt::KeepAspectRatio));

    ui->desk1btn->setIcon(icon1);
    ui->desk2btn->setIcon(icon2);
    ui->desk3btn->setIcon(icon3);

    ui->desk1btn->setIconSize(ui->desk1btn->size());
    ui->desk2btn->setIconSize(ui->desk2btn->size());
    ui->desk3btn->setIconSize(ui->desk3btn->size());

    ui->desk1btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/desk1.jpg");
    ui->desk2btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/desk2.jpg");
    ui->desk3btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/desk3.jpg");

    // Connect each button's clicked signal to the displayImage slot
    connect(ui->desk1btn, &QPushButton::clicked, this, &deskchair::displayImage);
    connect(ui->desk2btn, &QPushButton::clicked, this, &deskchair::displayImage);
    connect(ui->desk3btn, &QPushButton::clicked, this, &deskchair::displayImage);
}


deskchair::~deskchair()
{
    delete ui;
}

void deskchair::displayImage()
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
                    bfur->setDeskPath(selectedImagePath);
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
                file<<bfur->getDesk()<<endl;
                file.close();
                cout << bfur->getDesk()<< endl;

                delete bfur;
            }
            else
            {
                QMessageBox::warning(this, "Error", "Failed to load image.", QMessageBox::Ok);
            }
        }
    }
}
