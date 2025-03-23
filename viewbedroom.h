#ifndef VIEWBEDROOM_H
#define VIEWBEDROOM_H

#include <QDialog>

namespace Ui {
class viewBedroom;
}

class viewBedroom : public QDialog
{
    Q_OBJECT

public:
    explicit viewBedroom(QWidget *parent = nullptr);
    ~viewBedroom();

private:
    Ui::viewBedroom *ui;
};

#endif // VIEWBEDROOM_H
