#ifndef LFURUI_H
#define LFURUI_H

#include <QDialog>
#include <QPushButton>

namespace Ui {
class lfurui;
}

class lfurui : public QDialog
{
    Q_OBJECT

public:
    explicit lfurui(QWidget *parent = nullptr);
    ~lfurui();

private slots:
    void on_sofabtn_clicked();

    void on_coffeetablebtn_clicked();

    void on_tvstandbtn_clicked();

    void on_bookshelfbtn_clicked();

    void on_lampbtn_clicked();

    void on_decitembtn_clicked();

    void on_lfloorrugbtn_clicked();

private:
    Ui::lfurui *ui;
};

#endif // LFURUI_H
