#include "btheme1.h"
#include "ui_btheme1.h"
#include <QPixmap>
#include "Theme.h"
#include <iostream>
#include <QMessageBox>
#include <fstream>

using namespace std;

btheme1::btheme1(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::btheme1)
{
    ui->setupUi(this);
    QPixmap imgbtn1("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/btheme1.jpg");
    QPixmap imgbtn2("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/btheme2.jpg");
    QPixmap imgbtn3("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/btheme3.jpg");

    QIcon icon1(imgbtn1.scaled(ui->btheme1btn->size(), Qt::KeepAspectRatio));
    QIcon icon2(imgbtn2.scaled(ui->btheme2btn->size(), Qt::KeepAspectRatio));
    QIcon icon3(imgbtn3.scaled(ui->btheme3btn->size(), Qt::KeepAspectRatio));

    ui->btheme1btn->setIcon(icon1);
    ui->btheme2btn->setIcon(icon2);
    ui->btheme3btn->setIcon(icon3);

    ui->btheme1btn->setIconSize(ui->btheme1btn->size());
    ui->btheme2btn->setIconSize(ui->btheme2btn->size());
    ui->btheme3btn->setIconSize(ui->btheme3btn->size());

    ui->btheme1btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/btheme1.jpg");
    ui->btheme2btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/btheme2.jpg");
    ui->btheme3btn->setProperty("imagePath", "D:/E-books/SEM 2/Object Oriented Programming/Package_Images/btheme3.jpg");

    // Connect each button's clicked signal to the displayImage slot
    connect(ui->btheme1btn, &QPushButton::clicked, this, &btheme1::displayImage);
    connect(ui->btheme2btn, &QPushButton::clicked, this, &btheme1::displayImage);
    connect(ui->btheme3btn, &QPushButton::clicked, this, &btheme1::displayImage);
}

btheme1::~btheme1()
{
    delete ui;
}

BTheme::BTheme():colourPalette()
{

}

BTheme::BTheme(string pallete):colourPalette(pallete)
{

}

BTheme::BTheme(const BTheme & theme):colourPalette(theme.colourPalette)
{

}

BTheme::~BTheme()
{

}

string BTheme::getColourPalette()
{
    return colourPalette;
}

void BTheme::setColourPalette(const QString & palette)
{
    this->colourPalette = palette.toStdString();
}

void BTheme::setColourPalettePath(const QString & path)
{
    this->setColourPalette(path);
}

void btheme1::displayImage()
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

                btheme = new (BTheme);
                QObject::connect(&msgBox, &QMessageBox::accepted, [=]() {
                    btheme->setColourPalettePath(selectedImagePath);
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
                file<<btheme->getColourPalette()<<endl;
                file.close();
                cout<< btheme->getColourPalette()<<endl;

                delete btheme;
            }
            else
            {
                QMessageBox::warning(this, "Error", "Failed to load image.", QMessageBox::Ok);
            }
        }
    }
}
