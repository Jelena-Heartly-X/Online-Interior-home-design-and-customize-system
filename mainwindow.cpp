#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "interiordesign.h"
#include <QPixmap>
#include <QScreen>
#include <iostream>
#include <fstream>
#include <cassert>
#include <QMessageBox>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::OnlineInterior)
{
    ui->setupUi(this);
    QPixmap pic("D:/E-books/SEM 2/Object Oriented Programming/Package_Images/house1.jpg"); // give the image path here
    ui->lblhouse->setPixmap(pic);
    ui->lblhouse->setScaledContents(true);
    ui->MainLabel->setAlignment(Qt::AlignCenter);
    ui->lblhouse->setAlignment(Qt::AlignRight);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_sign_in_clicked()
{
    QString username = ui->sign_user->text();
    QString password = ui->sign_pass->text();
    fstream file;
    file.open("login_info.txt", ios::app);
    try
    {
        if(!file.is_open())
        {
            string errorMsg="Login info File not found!!!";
            throw errorMsg;
        }
    }
    catch(string errorMsg)
    {
        cout<<errorMsg<<endl;
        assert(false);
    }
    file<<username.toStdString()<<","<<password.toStdString()<<endl;
    file.close();
    QMessageBox::about(this,"Signed in","You have Successfully Signed In ! Now you can Log in to your account!");
    ui->sign_user->clear();
    ui->sign_pass->clear();
}


void MainWindow::on_log_in_clicked()
{
    QString username = ui->log_user->text();
    QString password = ui->log_pass->text();
    vector<pair<string, string>> credentials;
    ifstream file("login_info.txt");
    string line, user, pass;
    if (file.is_open())
    {
        while (getline(file, line))
        {
            size_t pos = line.find(",");
            if (pos != string::npos)
            {
                user = line.substr(0, pos);
                pass = line.substr(pos + 1);
                credentials.push_back(make_pair(user, pass));
            }
        }
    }
    else
    {
        cout << "Unable to open file!" << endl;
        assert(false);
    }
    int check=0;
    for (const auto& cred : credentials)
    {
        if (username.toStdString() == cred.first && password.toStdString() == cred.second)
        {
            InteriorDesign win;
            QScreen *primaryScreen = QApplication::primaryScreen();
            QRect screenGeometry = primaryScreen->geometry();
            win.resize(screenGeometry.size());
            win.setModal(true);
            win.exec();

            check=1;
            ui->log_user->clear();
            ui->log_pass->clear();
            break;
        }
    }
    if(check==0)
    {
        QMessageBox::warning(this,"Login","Username and password is not correct");
    }
    file.close();
}
