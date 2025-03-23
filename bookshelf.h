#ifndef BOOKSHELF_H
#define BOOKSHELF_H

#include "lfurniture.h"
#include <QDialog>
#include <QPushButton>
#include <iostream>

namespace Ui {
class bookshelf;
}

class bookshelf : public QDialog
{
    Q_OBJECT

public:
    explicit bookshelf(QWidget *parent = nullptr);
    ~bookshelf();
signals:
    void imagePathChanged(const QString &imagePath);

public slots:
    void displayImage();
private:
    Ui::bookshelf *ui;
    QString selectedImagePath;
    LFurniture *lfur;
};

#endif // BOOKSHELF_H
