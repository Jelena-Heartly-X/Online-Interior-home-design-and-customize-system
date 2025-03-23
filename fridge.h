#ifndef FRIDGE_H
#define FRIDGE_H
#include "kelectronicitems.h"
#include <QDialog>
#include <QPushButton>
#include <iostream>

namespace Ui {
class fridge;
}

class fridge : public QDialog
{
    Q_OBJECT

public:
    explicit fridge(QWidget *parent = nullptr);
    ~fridge();

signals:
    void imagePathChanged(const QString &imagePath);
public slots:
    void displayImage();
private:
    Ui::fridge *ui;
    QString selectedImagePath;
    KElectronicItems *eitem;
};

#endif // FRIDGE_H
