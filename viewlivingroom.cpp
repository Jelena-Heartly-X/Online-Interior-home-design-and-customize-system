#include "viewlivingroom.h"
#include "ui_viewlivingroom.h"
#include <iostream>
#include <QPixmap>
#include <QSize>
#include <fstream>
#include <cassert>

using namespace std;

viewlivingroom::viewlivingroom(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::viewlivingroom)
{
    ui->setupUi(this);
    ifstream file("livingroom_info.txt");
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

            if (line.find("sofa") != string::npos)
            {
                QSize labelSize = ui->sofalbl->size();
                pixmap = pixmap.scaled(labelSize, Qt::KeepAspectRatio);
                ui->sofalbl->setPixmap(pixmap);
            }
            else if (line.find("coffeeTable") != string::npos)
            {
                QSize labelSize = ui->coffeetablelbl->size();
                pixmap = pixmap.scaled(labelSize, Qt::KeepAspectRatio);
                ui->coffeetablelbl->setPixmap(pixmap);
            }
            else if (line.find("tvstand") != string::npos)
            {
                QSize labelSize = ui->tvstandlbl->size();
                pixmap = pixmap.scaled(labelSize, Qt::KeepAspectRatio);
                ui->tvstandlbl->setPixmap(pixmap);
            }
            else if (line.find("shelf") != string::npos)
            {
                QSize labelSize = ui->bookshelflbl->size();
                pixmap = pixmap.scaled(labelSize, Qt::KeepAspectRatio);
                ui->bookshelflbl->setPixmap(pixmap);
            }
            else if (line.find("rug") != string::npos)
            {
                QSize labelSize = ui->ruglbl->size();
                pixmap = pixmap.scaled(labelSize, Qt::KeepAspectRatio);
                ui->ruglbl->setPixmap(pixmap);
            }
            else if (line.find("lamp") != string::npos)
            {
                QSize labelSize = ui->lamplbl->size();
                pixmap = pixmap.scaled(labelSize, Qt::KeepAspectRatio);
                ui->lamplbl->setPixmap(pixmap);
            }
            else if (line.find("decItems") != string::npos)
            {
                QSize labelSize = ui->decItemslbl->size();
                pixmap = pixmap.scaled(labelSize, Qt::KeepAspectRatio);
                ui->decItemslbl->setPixmap(pixmap);
            }
            else if (line.find("flooring") != string::npos)
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

viewlivingroom::~viewlivingroom()
{
    delete ui;
}
