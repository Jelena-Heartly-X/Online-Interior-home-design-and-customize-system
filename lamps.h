#ifndef LAMPS_H
#define LAMPS_H

#include <QDialog>
#include "Furniture.h"
#include <QPushButton>
#include <iostream>

using namespace std;

namespace Ui {
class lamps;
}

class lamps : public QDialog
{
    Q_OBJECT

public:
    explicit lamps(QWidget *parent = nullptr);
    ~lamps();

signals:
    void imagePathChanged(const QString &imagePath);

public slots:
    void displayImage();

public:
    Ui::lamps *ui;
    QString selectedImagePath;
    BFurniture *bfur;
};

#endif // LAMPS_H
