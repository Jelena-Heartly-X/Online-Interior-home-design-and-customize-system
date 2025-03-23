#include "viewbedroom.h"
#include "ui_viewbedroom.h"
#include <iostream>
#include <QPixmap>
#include <QSize>
#include <fstream>
#include <cassert>

using namespace std;

viewBedroom::viewBedroom(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::viewBedroom)
{
    ui->setupUi(this);
    ifstream file("bedroom_info.txt");
    if (!file.is_open())
    {
        cerr << "Unable to open file!" << endl;
        return;
    }

    string line;
    while (getline(file, line))
    {
        cout << "Reading line: " << line << endl;

        QPixmap pixmap(line.c_str());
        if (!pixmap.isNull())
        {
            cout << "Pixmap loaded successfully" << endl;


            if (line.find("bed") != string::npos)
            {
                QSize labelSize = ui->bedlbl->size();
                pixmap = pixmap.scaled(labelSize, Qt::KeepAspectRatio);
                ui->bedlbl->setPixmap(pixmap);
            }
            else if (line.find("wardrobe") != string::npos)
            {
                QSize labelSize = ui->wardrobelbl->size();
                pixmap = pixmap.scaled(labelSize, Qt::KeepAspectRatio);
                ui->wardrobelbl->setPixmap(pixmap);
            }
            else if (line.find("decItems") != string::npos)
            {
                QSize labelSize = ui->decitemslbl->size();
                pixmap = pixmap.scaled(labelSize, Qt::KeepAspectRatio);
                ui->decitemslbl->setPixmap(pixmap);
            }
            else if (line.find("rug") != string::npos)
            {
                QSize labelSize = ui->ruglbl->size();
                pixmap = pixmap.scaled(labelSize, Qt::KeepAspectRatio);
                ui->ruglbl->setPixmap(pixmap);
            }
            else if (line.find("desk") != string::npos)
            {
                QSize labelSize = ui->desklbl->size();
                pixmap = pixmap.scaled(labelSize, Qt::KeepAspectRatio);
                ui->desklbl->setPixmap(pixmap);
            }
            else if (line.find("lamp") != string::npos)
            {
                QSize labelSize = ui->lamplbl->size();
                pixmap = pixmap.scaled(labelSize, Qt::KeepAspectRatio);
                ui->lamplbl->setPixmap(pixmap);
            }
            else if (line.find("floor") != string::npos)
            {
                QSize labelSize = ui->floorlbl->size();
                pixmap = pixmap.scaled(labelSize, Qt::KeepAspectRatio);
                ui->floorlbl->setPixmap(pixmap);
            }
            else if (line.find("theme") != string::npos)
            {
                QSize labelSize = ui->themelbl->size();
                pixmap = pixmap.scaled(labelSize, Qt::KeepAspectRatio);
                ui->themelbl->setPixmap(pixmap);
            }
        }
        else
        {
            cerr << "Failed to load pixmap for line: " << line << endl;
        }
    }
    file.close();
}

viewBedroom::~viewBedroom()
{
    delete ui;
}
