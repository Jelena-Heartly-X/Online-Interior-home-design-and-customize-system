#ifndef KFLOORUI_H
#define KFLOORUI_H

#include <QDialog>
#include "kflooring.h"
#include <QPushButton>
#include <iostream>

namespace Ui {
class kfloorui;
}

class kfloorui : public QDialog
{
    Q_OBJECT

public:
    explicit kfloorui(QWidget *parent = nullptr);
    ~kfloorui();

signals:
    void imagePathChanged(const QString &imagePath);

public slots:
    void displayImage();

public:
    Ui::kfloorui *ui;
    QString selectedImagePath;
    KFlooring *kfloor;
};


#endif // KFLOORUI_H
