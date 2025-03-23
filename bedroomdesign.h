#ifndef BEDROOMDESIGN_H
#define BEDROOMDESIGN_H

#include <QDialog>
#include "Room.h"
#include "Furniture.h"
#include "Flooring.h"
#include "Theme.h"

using namespace std;

namespace Ui {
class bedroomDesign;
}

class bedroomDesign : public QDialog
{
    Q_OBJECT

public:
    explicit bedroomDesign(QWidget *parent = nullptr);
    ~bedroomDesign();

private slots:

    void on_bfurbtn_clicked();

    void on_bfloorbtn_clicked();

    void on_bthemebtn_clicked();

    void on_viewbtn_clicked();

private:
    Ui::bedroomDesign *ui;
};

class Bedroom:public Room
{
private:
    BFurniture bedFur;
    BFlooring bedFloor;
    BTheme bedTheme;
public:
    Bedroom();
    Bedroom(BFurniture fur,BFlooring floor,BTheme bedTheme);
    Bedroom(const Bedroom & obj);
    ~Bedroom();
};

#endif // BEDROOMDESIGN_H
