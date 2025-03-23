#include "kthemeui.h"
#include "ui_kthemeui.h"
#include <QPixmap>
#include "ktheme.h"
#include <iostream>
#include <QMessageBox>
#include <fstream>

using namespace std;

kthemeui::kthemeui(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::kthemeui)
{
    ui->setupUi(this);
    QPixmap imgbtn1("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/ktheme1.jpg");
    QPixmap imgbtn2("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/ktheme2.jpg");
    QPixmap imgbtn3("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/ktheme3.jpg");

    QIcon icon1(imgbtn1.scaled(ui->ktheme1btn->size(), Qt::KeepAspectRatio));
    QIcon icon2(imgbtn2.scaled(ui->ktheme2btn->size(), Qt::KeepAspectRatio));
    QIcon icon3(imgbtn3.scaled(ui->ktheme3btn->size(), Qt::KeepAspectRatio));

    ui->ktheme1btn->setIcon(icon1);
    ui->ktheme2btn->setIcon(icon2);
    ui->ktheme3btn->setIcon(icon3);

    ui->ktheme1btn->setIconSize(ui->ktheme1btn->size());
    ui->ktheme2btn->setIconSize(ui->ktheme2btn->size());
    ui->ktheme3btn->setIconSize(ui->ktheme3btn->size());

    ui->ktheme1btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/ktheme1.jpg");
    ui->ktheme2btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/ktheme2.jpg");
    ui->ktheme3btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/ktheme3.jpg");

    // Connect each button's clicked signal to the displayImage slot
    connect(ui->ktheme1btn, &QPushButton::clicked, this, &kthemeui::displayImage);
    connect(ui->ktheme2btn, &QPushButton::clicked, this, &kthemeui::displayImage);
    connect(ui->ktheme3btn, &QPushButton::clicked, this, &kthemeui::displayImage);
}


kthemeui::~kthemeui()
{
    delete ui;
}

void kthemeui::displayImage()
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

                ktheme = new (KTheme);
                QObject::connect(&msgBox, &QMessageBox::accepted, [=]() {
                    ktheme->setColourPalettePath(selectedImagePath);
                });

                msgBox.exec();
                fstream file;
                file.open("kitchen_info.txt", ios::app);
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
                file<<ktheme->getColourPalette()<<endl;
                file.close();
                cout<< ktheme->getColourPalette()<<endl;

                delete ktheme;
            }
            else
            {
                QMessageBox::warning(this, "Error", "Failed to load image.", QMessageBox::Ok);
            }
        }
    }
}
