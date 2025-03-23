#ifndef VIEWKITCHEN_H
#define VIEWKITCHEN_H

#include <QDialog>

namespace Ui {
class viewkitchen;
}

class viewkitchen : public QDialog
{
    Q_OBJECT

public:
    explicit viewkitchen(QWidget *parent = nullptr);
    ~viewkitchen();

private:
    Ui::viewkitchen *ui;
};

#endif // VIEWKITCHEN_H
