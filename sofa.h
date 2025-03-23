#ifndef SOFA_H
#define SOFA_H


#include "lfurniture.h"
#include <QDialog>
#include <QPushButton>
#include <iostream>

using namespace std;

namespace Ui {
class sofa;
}

class sofa : public QDialog
{
    Q_OBJECT

public:
    explicit sofa(QWidget *parent = nullptr);
    ~sofa();
signals:
    void imagePathChanged(const QString &imagePath);

public slots:
    void displayImage();
public:
    Ui::sofa *ui;
    QString selectedImagePath;
    LFurniture *lfur;
};

#endif // SOFA_H
