#ifndef INTERIORDESIGN_H
#define INTERIORDESIGN_H

#include <QDialog>

namespace Ui {
class InteriorDesign;
}

class InteriorDesign : public QDialog
{
    Q_OBJECT

public:
    explicit InteriorDesign(QWidget *parent = nullptr);
    ~InteriorDesign();

private slots:
    void on_btn_bedroom_clicked();

    void on_btn_livingroom_clicked();

    void on_btn_kitchen_clicked();

private:
    Ui::InteriorDesign *ui;
};

#endif // INTERIORDESIGN_H
