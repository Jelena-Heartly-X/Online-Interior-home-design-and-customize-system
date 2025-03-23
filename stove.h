#ifndef STOVE_H
#define STOVE_H
#include "kelectronicitems.h"
#include <QDialog>
#include <QPushButton>
#include <iostream>

namespace Ui {
class stove;
}

class stove : public QDialog
{
    Q_OBJECT

public:
    explicit stove(QWidget *parent = nullptr);
    ~stove();

signals:
    void imagePathChanged(const QString &imagePath);
public slots:
    void displayImage();
private:
    Ui::stove *ui;
    QString selectedImagePath;
    KElectronicItems *eitem;
};

#endif // STOVE_H
