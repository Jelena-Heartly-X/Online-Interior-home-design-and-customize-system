#ifndef BTHEME1_H
#define BTHEME1_H

#include <QDialog>
#include "Theme.h"
#include <QPushButton>
#include <iostream>

namespace Ui {
class btheme1;
}

class btheme1 : public QDialog
{
    Q_OBJECT

public:
    explicit btheme1(QWidget *parent = nullptr);
    ~btheme1();

signals:
    void imagePathChanged(const QString &imagePath);

public slots:
    void displayImage();

public:
    Ui::btheme1 *ui;
    QString selectedImagePath;
    BTheme *btheme;
};

#endif // BTHEME1_H
