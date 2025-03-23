#ifndef VIEWLIVINGROOM_H
#define VIEWLIVINGROOM_H

#include <QDialog>

namespace Ui {
class viewlivingroom;
}

class viewlivingroom : public QDialog
{
    Q_OBJECT

public:
    explicit viewlivingroom(QWidget *parent = nullptr);
    ~viewlivingroom();

private:
    Ui::viewlivingroom *ui;
};

#endif // VIEWLIVINGROOM_H
