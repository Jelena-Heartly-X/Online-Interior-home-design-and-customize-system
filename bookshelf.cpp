#include "bookshelf.h"
#include "ui_bookshelf.h"
#include "Furniture.h"
#include "lfurniture.h"
#include <string>
#include <QMessageBox>
#include <iostream>
#include <fstream>
#include <cassert>
#include <QPixmap>

bookshelf::bookshelf(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::bookshelf)
{
    ui->setupUi(this);
    QPixmap imgbtn1("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/shelf1.jpg");
    QPixmap imgbtn2("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/shelf2.jpg");
    QPixmap imgbtn3("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/shelf3.jpg");

    QIcon icon1(imgbtn1.scaled(ui->shelf1btn->size(), Qt::KeepAspectRatio));
    QIcon icon2(imgbtn2.scaled(ui->shelf2btn->size(), Qt::KeepAspectRatio));
    QIcon icon3(imgbtn3.scaled(ui->shelf3btn->size(), Qt::KeepAspectRatio));

    ui->shelf1btn->setIcon(icon1);
    ui->shelf2btn->setIcon(icon2);
    ui->shelf3btn->setIcon(icon3);

    ui->shelf1btn->setIconSize(ui->shelf1btn->size());
    ui->shelf2btn->setIconSize(ui->shelf2btn->size());
    ui->shelf3btn->setIconSize(ui->shelf3btn->size());

    ui->shelf1btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/shelf1.jpg");
    ui->shelf2btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/shelf2.jpg");
    ui->shelf3btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/shelf3.jpg");

    connect(ui->shelf1btn, &QPushButton::clicked, this, &bookshelf::displayImage);
    connect(ui->shelf2btn, &QPushButton::clicked, this, &bookshelf::displayImage);
    connect(ui->shelf3btn, &QPushButton::clicked, this, &bookshelf::displayImage);
}


bookshelf::~bookshelf()
{
    delete ui;
}

void bookshelf::displayImage()
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
                    lfur->setBookShelfPath(selectedImagePath);
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
                file<<lfur->getBookShelf()<<endl;
                file.close();
                cout<<lfur->getBookShelf()<<endl;

                delete lfur;
            }
            else
            {
                QMessageBox::warning(this, "Error", "Failed to load image.", QMessageBox::Ok);
            }
        }
    }
}
