#ifndef KTHEMEUI_H
#define KTHEMEUI_H

#include <QDialog>
#include "kTheme.h"
#include <QPushButton>
#include <iostream>

namespace Ui {
class kthemeui;
}

class kthemeui : public QDialog
{
    Q_OBJECT

public:
    explicit kthemeui(QWidget *parent = nullptr);
    ~kthemeui();

signals:
    void imagePathChanged(const QString &imagePath);

public slots:
    void displayImage();

public:
    Ui::kthemeui *ui;
    QString selectedImagePath;
    KTheme *ktheme;
};
#endif //KTHEMEUI_H
