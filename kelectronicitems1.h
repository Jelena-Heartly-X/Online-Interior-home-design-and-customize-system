#ifndef KELECTRONICITEMS1_H
#define KELECTRONICITEMS1_H

#include <QDialog>

namespace Ui {
class kelectronicitems1;
}

class kelectronicitems1 : public QDialog
{
    Q_OBJECT

public:
    explicit kelectronicitems1(QWidget *parent = nullptr);
    ~kelectronicitems1();

private slots:
    void on_kfridge1btn_clicked();

    void on_kstove2btn_clicked();

    void on_koven3btn_clicked();

private:
    Ui::kelectronicitems1 *ui;
};

#endif // KELECTRONICITEMS1_H
