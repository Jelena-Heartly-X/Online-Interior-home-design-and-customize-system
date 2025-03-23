#include "viewkitchen.h"
#include "ui_viewkitchen.h"
#include <iostream>
#include <QPixmap>
#include <QSize>
#include <fstream>
#include <cassert>

using namespace std;

viewkitchen::viewkitchen(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::viewkitchen)
{
    ui->setupUi(this);
    ifstream file("kitchen_info.txt");
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

            if (line.find("diningtable") != string::npos)
            {
                QSize labelSize = ui->dininglbl->size();
                pixmap = pixmap.scaled(labelSize, Qt::KeepAspectRatio);
                ui->dininglbl->setPixmap(pixmap);
            }
            else if (line.find("counter") != string::npos)
            {
                QSize labelSize = ui->toplbl->size();
                pixmap = pixmap.scaled(labelSize, Qt::KeepAspectRatio);
                ui->toplbl->setPixmap(pixmap);
            }
            else if (line.find("cabinet") != string::npos)
            {
                QSize labelSize = ui->cabinetlbl->size();
                pixmap = pixmap.scaled(labelSize, Qt::KeepAspectRatio);
                ui->cabinetlbl->setPixmap(pixmap);
            }
            else if (line.find("sink") != string::npos)
            {
                QSize labelSize = ui->sinklbl->size();
                pixmap = pixmap.scaled(labelSize, Qt::KeepAspectRatio);
                ui->sinklbl->setPixmap(pixmap);
            }
            else if (line.find("fridge") != string::npos)
            {
                QSize labelSize = ui->fridgelbl->size();
                pixmap = pixmap.scaled(labelSize, Qt::KeepAspectRatio);
                ui->fridgelbl->setPixmap(pixmap);
            }
            else if (line.find("stove") != string::npos)
            {
                QSize labelSize = ui->stovelbl->size();
                pixmap = pixmap.scaled(labelSize, Qt::KeepAspectRatio);
                ui->stovelbl->setPixmap(pixmap);
            }
            else if (line.find("oven") != string::npos)
            {
                QSize labelSize = ui->ovenlbl->size();
                pixmap = pixmap.scaled(labelSize, Qt::KeepAspectRatio);
                ui->ovenlbl->setPixmap(pixmap);
            }
            else if (line.find("flooring") != string::npos)
            {
                QSize labelSize = ui->flooringlbl->size();
                pixmap = pixmap.scaled(labelSize, Qt::KeepAspectRatio);
                ui->flooringlbl->setPixmap(pixmap);
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

viewkitchen::~viewkitchen()
{
    delete ui;
}
