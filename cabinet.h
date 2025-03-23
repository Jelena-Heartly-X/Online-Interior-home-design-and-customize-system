#ifndef CABINET_H
#define CABINET_H

#include <QDialog>
#include "kfurniture.h"
#include <iostream>
using namespace std;

namespace Ui {
class cabinet;
}

class cabinet : public QDialog
{
    Q_OBJECT

public:
    explicit cabinet(QWidget *parent = nullptr);
    ~cabinet();

signals:
    void imagePathChanged(const QString &imagePath);

public slots:
    void displayImage();

public:
    Ui::cabinet *ui;
    QString selectedImagePath;
    KFurniture *kfur;
};

#endif // CABINET_H
