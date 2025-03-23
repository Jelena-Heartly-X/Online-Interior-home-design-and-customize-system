#ifndef DININGTABLE_H
#define DININGTABLE_H

#include <QDialog>
#include "kfurniture.h"
#include <QPushButton>
#include <iostream>

using namespace std;

namespace Ui {
class diningTable;
}

class diningTable : public QDialog
{
    Q_OBJECT

public:
    explicit diningTable(QWidget *parent = nullptr);
    ~diningTable();

signals:
    void imagePathChanged(const QString &imagePath);

public slots:
    void displayImage();

public:
    Ui::diningTable *ui;
    QString selectedImagePath;
    KFurniture *kfur;
};

#endif // DININGTABLE_H
