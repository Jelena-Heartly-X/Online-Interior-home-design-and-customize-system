#ifndef OVEN_H
#define OVEN_H
#include "kelectronicitems.h"
#include <QPushButton>
#include <iostream>
#include <QDialog>

namespace Ui {
class oven;
}

class oven : public QDialog
{
    Q_OBJECT

public:
    explicit oven(QWidget *parent = nullptr);
    ~oven();

signals:
    void imagePathChanged(const QString &imagePath);
public slots:
    void displayImage();
private:
    Ui::oven *ui;
    QString selectedImagePath;
    KElectronicItems *eitem;
};

#endif // OVEN_H
