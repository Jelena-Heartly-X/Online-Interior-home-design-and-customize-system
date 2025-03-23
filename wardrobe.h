#ifndef WARDROBE_H
#define WARDROBE_H

#include <QPushButton>
#include "Furniture.h"
#include <QDialog>
#include <iostream>

using namespace std;

namespace Ui {
class wardrobe;
}

class wardrobe : public QDialog
{
    Q_OBJECT

public:
    explicit wardrobe(QWidget *parent = nullptr);
    ~wardrobe();

signals:
    BFurniture imagePathChanged(const QString &imagePath);

public slots:
    void displayImage();

public:
    Ui::wardrobe *ui;
    QString selectedImagePath;
    BFurniture *bfur;
};

#endif // WARDROBE_H


