#ifndef LFLOORUI_H
#define LFLOORUI_H

#include <QDialog>
#include <QPushButton>
#include "lflooring.h"

namespace Ui {
class lfloorui;
}

class lfloorui : public QDialog
{
    Q_OBJECT

public:
    explicit lfloorui(QWidget *parent = nullptr);
    ~lfloorui();

signals:
    void imagePathChanged(const QString &imagePath);

public slots:
    void displayImage();

private:
    Ui::lfloorui *ui;
    QString selectedImagePath;
    LFlooring *lfloor;

};

#endif // LFLOORUI_H
