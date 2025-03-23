#include "diningtable.h"
#include "ui_diningtable.h"
#include <QPixmap>
#include <fstream>
#include <QMessageBox>
#include <cassert>
#include <iostream>
using namespace std;

diningTable::diningTable(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::diningTable)
{
    ui->setupUi(this);
    QPixmap imgbtn1("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/diningtable1.jpg");
    QPixmap imgbtn2("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/diningtable2.jpg");
    QPixmap imgbtn3("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/diningtable3.jpg");

    QIcon icon1(imgbtn1.scaled(ui->diningTable1btn->size(), Qt::KeepAspectRatio));
    QIcon icon2(imgbtn2.scaled(ui->diningTable2btn->size(), Qt::KeepAspectRatio));
    QIcon icon3(imgbtn3.scaled(ui->diningTable3btn->size(), Qt::KeepAspectRatio));

    ui->diningTable1btn->setIcon(icon1);
    ui->diningTable2btn->setIcon(icon2);
    ui->diningTable3btn->setIcon(icon3);

    ui->diningTable1btn->setIconSize(ui->diningTable1btn->size());
    ui->diningTable2btn->setIconSize(ui->diningTable2btn->size());
    ui->diningTable3btn->setIconSize(ui->diningTable3btn->size());

    ui->diningTable1btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/diningtable1.jpg");
    ui->diningTable2btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/diningtable2.jpg");
    ui->diningTable3btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/diningtable3.jpg");

    // Connect each button's clicked signal to the displayImage slot
    connect(ui->diningTable1btn, &QPushButton::clicked, this, &diningTable::displayImage);
    connect(ui->diningTable2btn, &QPushButton::clicked, this, &diningTable::displayImage);
    connect(ui->diningTable3btn, &QPushButton::clicked, this, &diningTable::displayImage);
}


diningTable::~diningTable()
{
    delete ui;
}

void diningTable::displayImage()
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
                    kfur->setDiningTablePath(selectedImagePath);
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
                file<<kfur->getDiningTable()<<endl;
                file.close();

                cout<< kfur->getDiningTable()<<endl;

                delete kfur;
            }
            else
            {
                QMessageBox::warning(this, "Error", "Failed to load image.", QMessageBox::Ok);
            }
        }
    }
}
