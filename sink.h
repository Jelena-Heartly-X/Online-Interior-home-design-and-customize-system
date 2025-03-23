#ifndef SINK_H
#define SINK_H

#include <QDialog>
#include <QPushButton>
#include "kfurniture.h"
#include <iostream>
using namespace std;

namespace Ui {
class sink;
}

class sink : public QDialog
{
    Q_OBJECT

public:
    explicit sink(QWidget *parent = nullptr);
    ~sink();

signals:
    void imagePathChanged(const QString &imagePath);

public slots:
    void displayImage();

public:
    Ui::sink *ui;
    QString selectedImagePath;
    KFurniture *kfur;
};

#endif // SINK_H
