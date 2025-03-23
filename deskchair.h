#ifndef DESKCHAIR_H
#define DESKCHAIR_H

#include <QDialog>
#include <QPushButton>
#include "Furniture.h"
#include <iostream>

using namespace std;

namespace Ui {
class deskchair;
}

class deskchair : public QDialog
{
    Q_OBJECT

public:
    explicit deskchair(QWidget *parent = nullptr);
    ~deskchair();

signals:
    void imagePathChanged(const QString &imagePath);

public slots:
    void displayImage();

public:
    Ui::deskchair *ui;
    QString selectedImagePath;
    BFurniture *bfur;
};

#endif // DESKCHAIR_H
