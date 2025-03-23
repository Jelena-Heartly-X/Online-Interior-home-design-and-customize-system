#ifndef BED_H
#define BED_H

#include "Furniture.h"
#include <QDialog>
#include <QPushButton>
#include <iostream>

using namespace std;

namespace Ui {
class bed;
}

class bed : public QDialog
{
    Q_OBJECT

public:
    explicit bed(QWidget *parent = nullptr);
    ~bed();

signals:
    void imagePathChanged(const QString &imagePath);

public slots:
    void displayImage();

public:
    Ui::bed *ui;
    QString selectedImagePath;
    BFurniture *bfur;
};

#endif // BED_H
