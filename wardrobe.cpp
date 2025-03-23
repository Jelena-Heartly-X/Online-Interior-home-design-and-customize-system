#include "wardrobe.h"
#include "ui_wardrobe.h"
#include <QPixmap>
#include <QMessageBox>
#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

wardrobe::wardrobe(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::wardrobe)
{
    ui->setupUi(this);

    QPixmap imgbtn1("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/wardrobe1.jpg");
    QPixmap imgbtn2("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/wardrobe2.jpg");
    QPixmap imgbtn3("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/wardrobe3.jpg");

    QIcon icon1(imgbtn1.scaled(ui->wr1btn->size(), Qt::KeepAspectRatio));
    QIcon icon2(imgbtn2.scaled(ui->wr2btn->size(), Qt::KeepAspectRatio));
    QIcon icon3(imgbtn3.scaled(ui->wr3btn->size(), Qt::KeepAspectRatio));

    ui->wr1btn->setIcon(icon1);
    ui->wr2btn->setIcon(icon2);
    ui->wr3btn->setIcon(icon3);

    ui->wr1btn->setIconSize(ui->wr1btn->size());
    ui->wr2btn->setIconSize(ui->wr2btn->size());
    ui->wr3btn->setIconSize(ui->wr3btn->size());

    ui->wr1btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/wardrobe1.jpg");
    ui->wr2btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/wardrobe2.jpg");
    ui->wr3btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/wardrobe3.jpg");

    // Connect each button's clicked signal to the displayImage slot
    connect(ui->wr1btn, &QPushButton::clicked, this, &wardrobe::displayImage);
    connect(ui->wr2btn, &QPushButton::clicked, this, &wardrobe::displayImage);
    connect(ui->wr3btn, &QPushButton::clicked, this, &wardrobe::displayImage);
}


wardrobe::~wardrobe()
{
    delete ui;
}

void wardrobe::displayImage()
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
                    bfur->setWardRobePath(selectedImagePath);
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
                file<<bfur->getWardrobe()<<endl;
                file.close();
                cout << bfur->getWardrobe() << endl;

                delete bfur;
            }
            else
            {
                QMessageBox::warning(this, "Error", "Failed to load image.", QMessageBox::Ok);
            }
        }
    }
}
