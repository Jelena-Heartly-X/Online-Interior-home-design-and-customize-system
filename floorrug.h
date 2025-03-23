#ifndef FLOORRUG_H
#define FLOORRUG_H

#include <QDialog>
#include "Furniture.h"
#include <QPushButton>
#include <iostream>

using namespace std;

namespace Ui {
class floorRug;
}

class floorRug : public QDialog
{
    Q_OBJECT

public:
    explicit floorRug(QWidget *parent = nullptr);
    ~floorRug();

signals:
    void imagePathChanged(const QString &imagePath);

public slots:
    void displayImage();

public:
    Ui::floorRug *ui;
    QString selectedImagePath;
    BFurniture *bfur;
};

#endif // FLOORRUG_H
