#ifndef LLAMPS_H
#define LLAMPS_H

#include "lfurniture.h"
#include <QDialog>
#include <QPushButton>
#include <iostream>

namespace Ui {
class llamps;
}

class llamps : public QDialog
{
    Q_OBJECT

public:
    explicit llamps(QWidget *parent = nullptr);
    ~llamps();
signals:
    void imagePathChanged(const QString &imagePath);

public slots:
    void displayImage();
public:
    Ui::llamps *ui;
    QString selectedImagePath;
    LFurniture *lfur;
};

#endif // LLAMPS_H
