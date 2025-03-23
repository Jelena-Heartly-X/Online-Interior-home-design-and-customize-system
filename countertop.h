#ifndef COUNTERTOP_H
#define COUNTERTOP_H

#include <QDialog>
#include "kfurniture.h"
#include <iostream>
using namespace std;

namespace Ui {
class counterTop;
}

class counterTop : public QDialog
{
    Q_OBJECT

public:
    explicit counterTop(QWidget *parent = nullptr);
    ~counterTop();

signals:
    void imagePathChanged(const QString &imagePath);

public slots:
    void displayImage();

public:
    Ui::counterTop *ui;
    QString selectedImagePath;
    KFurniture *kfur;
};

#endif // COUNTERTOP_H
