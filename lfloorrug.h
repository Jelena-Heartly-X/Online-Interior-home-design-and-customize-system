#ifndef LFLOORRUG_H
#define LFLOORRUG_H

#include "lfurniture.h"
#include <QDialog>
#include <QPushButton>
#include <iostream>

namespace Ui {
class lfloorRug;
}

class lfloorRug : public QDialog
{
    Q_OBJECT

public:
    explicit lfloorRug(QWidget *parent = nullptr);
    ~lfloorRug();
signals:
    void imagePathChanged(const QString &imagePath);

public slots:
    void displayImage();
public:
    Ui::lfloorRug *ui;
    QString selectedImagePath;
    LFurniture *lfur;
};

#endif // LFLOORRUG_H
