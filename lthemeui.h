#ifndef LTHEMEUI_H
#define LTHEMEUI_H

#include <QDialog>
#include <QPushButton>
#include "ltheme.h"

namespace Ui {
class lthemeui;
}

class lthemeui : public QDialog
{
    Q_OBJECT

public:
    explicit lthemeui(QWidget *parent = nullptr);
    ~lthemeui();
signals:
    void imagePathChanged(const QString &imagePath);

public slots:
    void displayImage();
private:
    Ui::lthemeui *ui;
    QString selectedImagePath;
    LTheme *ltheme;
};

#endif // LTHEMEUI_H
