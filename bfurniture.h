#ifndef BFURNITURE_H
#define BFURNITURE_H
#include "Furniture.h"
#include <QDialog>

namespace Ui {
class bfurui;
}

class bfurui : public QDialog
{
    Q_OBJECT

public:
    explicit bfurui(QWidget *parent = nullptr);
    ~bfurui();

public slots:
    void on_bedbtn_clicked();

    void on_wardrobebtn_clicked();

    void on_deskbtn_clicked();

    void on_lampbtn_clicked();

    void on_rugbtn_clicked();

    void on_decbtn_clicked();

public:
    Ui::bfurui *ui;
};

#endif // BFURNITURE_H
