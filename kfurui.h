#ifndef KFURUI_H
#define KFURUI_H

#include <QDialog>

namespace Ui {
class kfurui;
}

class kfurui : public QDialog
{
    Q_OBJECT

public:
    explicit kfurui(QWidget *parent = nullptr);
    ~kfurui();

private slots:
    void on_diningTablebtn_clicked();

    void on_counterTopbtn_clicked();

    void on_cabinetbtn_clicked();

    void on_sinkbtn_clicked();

private:
    Ui::kfurui *ui;
};

#endif // KFURUI_H
