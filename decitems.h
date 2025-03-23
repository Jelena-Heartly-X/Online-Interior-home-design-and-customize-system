#ifndef DECITEMS_H
#define DECITEMS_H

#include <QDialog>
#include "Furniture.h"
#include <QPushButton>
#include <iostream>

using namespace std;

namespace Ui {
class decItems;
}

class decItems : public QDialog
{
    Q_OBJECT

public:
    explicit decItems(QWidget *parent = nullptr);
    ~decItems();

signals:
    void imagePathChanged(const QString &imagePath);

public slots:
    void displayImage();

public:
    Ui::decItems *ui;
    QString selectedImagePath;
    BFurniture *bfur;
};

#endif // DECITEMS_H
