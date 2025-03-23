#include "sink.h"
#include "ui_sink.h"
#include <QPixmap>
#include <QMessageBox>
#include <iostream>
#include <fstream>
#include <cassert>

sink::sink(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::sink)
{
    ui->setupUi(this);
    QPixmap imgbtn1("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/sink1.jpg");
    QPixmap imgbtn2("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/sink2.jpg");
    QPixmap imgbtn3("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/sink3.jpg");

    QIcon icon1(imgbtn1.scaled(ui->sink1btn->size(), Qt::KeepAspectRatio));
    QIcon icon2(imgbtn2.scaled(ui->sink2btn->size(), Qt::KeepAspectRatio));
    QIcon icon3(imgbtn3.scaled(ui->sink3btn->size(), Qt::KeepAspectRatio));

    ui->sink1btn->setIcon(icon1);
    ui->sink2btn->setIcon(icon2);
    ui->sink3btn->setIcon(icon3);

    ui->sink1btn->setIconSize(ui->sink1btn->size());
    ui->sink2btn->setIconSize(ui->sink2btn->size());
    ui->sink3btn->setIconSize(ui->sink3btn->size());

    ui->sink1btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/sink1.jpg");
    ui->sink2btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/sink2.jpg");
    ui->sink3btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/sink3.jpg");

    // Connect each button's clicked signal to the displayImage slot
    connect(ui->sink1btn, &QPushButton::clicked, this, &sink::displayImage);
    connect(ui->sink2btn, &QPushButton::clicked, this, &sink::displayImage);
    connect(ui->sink3btn, &QPushButton::clicked, this, &sink::displayImage);
}

sink::~sink()
{
    delete ui;
}

void sink::displayImage()
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
                    kfur->setSinkPath(selectedImagePath);
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
                file<<kfur->getSink()<<endl;
                file.close();
                cout<< kfur->getSink()<<endl;

                delete kfur;
            }
            else
            {
                QMessageBox::warning(this, "Error", "Failed to load image.", QMessageBox::Ok);
            }
        }
    }
}
