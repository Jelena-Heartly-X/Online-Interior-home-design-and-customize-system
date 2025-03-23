#ifndef KITCHENDESIGN_H
#define KITCHENDESIGN_H

#include <QDialog>
#include "Room.h"
#include "kfurniture.h"
#include "kflooring.h"
#include "ktheme.h"

namespace Ui {
class kitchenDesign;
}

class kitchenDesign : public QDialog
{
    Q_OBJECT

public:
    explicit kitchenDesign(QWidget *parent = nullptr);
    ~kitchenDesign();

private slots:
    void on_kfurbtn_clicked();

    void on_kfloorbtn_clicked();

    void on_kthemebtn_clicked();

    void on_keitembtn_clicked();

    void on_viewbtn_clicked();

private:
    Ui::kitchenDesign *ui;
};
\
class Kitchen:public Room
{
private:
    KFurniture kitcFur;
    KFlooring kitcFloor;
    KTheme kitcTheme;
public:
    Kitchen();
    Kitchen(KFurniture fur,KFlooring floor,KTheme theme);
    Kitchen(const Kitchen & obj);
    ~Kitchen();
};

#endif // KITCHENDESIGN_H
