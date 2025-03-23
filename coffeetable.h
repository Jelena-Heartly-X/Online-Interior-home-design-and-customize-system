#ifndef COFFEETABLE_H
#define COFFEETABLE_H

#include "lfurniture.h"
#include <QDialog>
#include <QPushButton>
#include <iostream>

namespace Ui {
class coffeeTable;
}

class coffeeTable : public QDialog
{
    Q_OBJECT

public:
    explicit coffeeTable(QWidget *parent = nullptr);
    ~coffeeTable();
signals:
    void imagePathChanged(const QString &imagePath);

public slots:
    void displayImage();

private:
    Ui::coffeeTable *ui;
    QString selectedImagePath;
    LFurniture *lfur;
};

#endif // COFFEETABLE_H
