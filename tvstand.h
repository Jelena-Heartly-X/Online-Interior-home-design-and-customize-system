#ifndef TVSTAND_H
#define TVSTAND_H

#include "lfurniture.h"
#include <QDialog>
#include <QPushButton>
#include <iostream>

using namespace std;

namespace Ui {
class tvstand;
}

class tvstand : public QDialog
{
    Q_OBJECT

public:
    explicit tvstand(QWidget *parent = nullptr);
    ~tvstand();

signals:
    void imagePathChanged(const QString &imagePath);

public slots:
    void displayImage();

public:
    Ui::tvstand *ui;
    QString selectedImagePath;
    LFurniture *lfur;
};

#endif // TVSTAND_H
