#ifndef BFLOORING1_H
#define BFLOORING1_H

#include <QDialog>
#include "Flooring.h"
#include <QPushButton>
#include <iostream>

namespace Ui {
class bflooring1;
}

class bflooring1 : public QDialog
{
    Q_OBJECT

public:
    explicit bflooring1(QWidget *parent = nullptr);
    ~bflooring1();

signals:
    void imagePathChanged(const QString &imagePath);

public slots:
    void displayImage();

public:
    Ui::bflooring1 *ui;
    QString selectedImagePath;
    BFlooring *bfloor;
};

#endif // BFLOORING1_H
