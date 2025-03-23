#include "lthemeui.h"
#include "ui_lthemeui.h"

#include <QPixmap>
#include "Theme.h"
#include <iostream>
#include <QMessageBox>
#include <QPushButton>
#include <fstream>

using namespace std;
lthemeui::lthemeui(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::lthemeui)
{
    ui->setupUi(this);
    QPixmap imgbtn1("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/ltheme1.jpg");
    QPixmap imgbtn2("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/ltheme2.jpg");
    QPixmap imgbtn3("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/ltheme3.jpg");

    QIcon icon1(imgbtn1.scaled(ui->ltheme1btn->size(), Qt::KeepAspectRatio));
    QIcon icon2(imgbtn2.scaled(ui->ltheme2btn->size(), Qt::KeepAspectRatio));
    QIcon icon3(imgbtn3.scaled(ui->ltheme3btn->size(), Qt::KeepAspectRatio));

    ui->ltheme1btn->setIcon(icon1);
    ui->ltheme2btn->setIcon(icon2);
    ui->ltheme3btn->setIcon(icon3);

    ui->ltheme1btn->setIconSize(ui->ltheme1btn->size());
    ui->ltheme2btn->setIconSize(ui->ltheme2btn->size());
    ui->ltheme3btn->setIconSize(ui->ltheme3btn->size());


    ui->ltheme1btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/ltheme1.jpg");
    ui->ltheme2btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/ltheme2.jpg");
    ui->ltheme3btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/ltheme3.jpg");

    // Connect each button's clicked signal to the displayImage slot
    connect(ui->ltheme1btn, &QPushButton::clicked, this, &lthemeui::displayImage);
    connect(ui->ltheme2btn, &QPushButton::clicked, this, &lthemeui::displayImage);
    connect(ui->ltheme3btn, &QPushButton::clicked, this, &lthemeui::displayImage);
}

lthemeui::~lthemeui()
{
    delete ui;
}

void lthemeui::displayImage()
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

                ltheme = new (LTheme);
                QObject::connect(&msgBox, &QMessageBox::accepted, [=]() {
                    ltheme->setColourPalettePath(selectedImagePath);
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
                file<<ltheme->getColourPalette()<<endl;
                file.close();
                cout<<ltheme->getColourPalette()<<endl;

                delete ltheme;
            }
            else
            {
                QMessageBox::warning(this, "Error", "Failed to load image.", QMessageBox::Ok);
            }
        }
    }
}
