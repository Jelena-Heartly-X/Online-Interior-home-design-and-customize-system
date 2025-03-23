#ifndef LDECITEMS_H
#define LDECITEMS_H

#include "lfurniture.h"
#include <QDialog>
#include <QPushButton>
#include <iostream>

namespace Ui {
class ldecitems;
}

class ldecitems : public QDialog
{
    Q_OBJECT

public:
    explicit ldecitems(QWidget *parent = nullptr);
    ~ldecitems();

signals:
    void imagePathChanged(const QString &imagePath);

public slots:
    void displayImage();

private:
    Ui::ldecitems *ui;
    QString selectedImagePath;
    LFurniture *lfur;
};

#endif //LDECITEMS_H
