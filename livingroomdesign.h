#ifndef LIVINGROOMDESIGN_H
#define LIVINGROOMDESIGN_H

#include <QDialog>
#include "Room.h"
#include "lfurniture.h"
#include "lflooring.h"
#include "ltheme.h"

namespace Ui {
class LivingroomDesign;
}

class LivingroomDesign : public QDialog
{
    Q_OBJECT

public:
    explicit LivingroomDesign(QWidget *parent = nullptr);
    ~LivingroomDesign();

private slots:

    void on_lfurbtn_clicked();

    void on_lfloorbtn_clicked();

    void on_lthemebtn_clicked();

    void on_viewbtn_clicked();

private:
    Ui::LivingroomDesign *ui;
};

class LivingRoom:public Room
{
private:
    LFurniture livFur;
    LFlooring livFloor;
    LTheme livTheme;
public:
    LivingRoom();
    LivingRoom(LFurniture fur,LFlooring floor,LTheme theme);
    LivingRoom(const LivingRoom & obj);
    ~LivingRoom();
};

#endif // LIVINGROOMDESIGN_H
