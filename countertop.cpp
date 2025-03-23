#include "countertop.h"
#include "ui_countertop.h"
#include <QPixmap>
#include <QMessageBox>
#include <iostream>
#include <fstream>
#include <cassert>

counterTop::counterTop(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::counterTop)
{
    ui->setupUi(this);
    QPixmap imgbtn1("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/countertop1.jpg");
    QPixmap imgbtn2("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/countertop2.jpg");
    QPixmap imgbtn3("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/countertop3.jpg");

    QIcon icon1(imgbtn1.scaled(ui->top1btn->size(), Qt::KeepAspectRatio));
    QIcon icon2(imgbtn2.scaled(ui->top2btn->size(), Qt::KeepAspectRatio));
    QIcon icon3(imgbtn3.scaled(ui->top3btn->size(), Qt::KeepAspectRatio));

    ui->top1btn->setIcon(icon1);
    ui->top2btn->setIcon(icon2);
    ui->top3btn->setIcon(icon3);

    ui->top1btn->setIconSize(ui->top1btn->size());
    ui->top2btn->setIconSize(ui->top2btn->size());
    ui->top3btn->setIconSize(ui->top3btn->size());

    ui->top1btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/countertop1.jpg");
    ui->top2btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/countertop2.jpg");
    ui->top3btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/countertop3.jpg");

    // Connect each button's clicked signal to the displayImage slot
    connect(ui->top1btn, &QPushButton::clicked, this, &counterTop::displayImage);
    connect(ui->top2btn, &QPushButton::clicked, this, &counterTop::displayImage);
    connect(ui->top3btn, &QPushButton::clicked, this, &counterTop::displayImage);

}

counterTop::~counterTop()
{
    delete ui;
}

void counterTop::displayImage()
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

                kfur = new (KFurniture);
                QObject::connect(&msgBox, &QMessageBox::accepted, [=]() {
                    kfur->setCounterTopPath(selectedImagePath);
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
                file<<kfur->getCounterTop()<<endl;
                file.close();
                cout<<kfur->getCounterTop()<<endl;

                delete kfur;
            }
            else
            {
                QMessageBox::warning(this, "Error", "Failed to load image.", QMessageBox::Ok);
            }
        }
    }
}
