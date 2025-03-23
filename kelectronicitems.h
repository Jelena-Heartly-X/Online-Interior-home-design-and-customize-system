#ifndef KELECTRONICITEMS_H
#define KELECTRONICITEMS_H
#include <iostream>
#include <string>
#include <QObject>
using namespace std;

class KElectronicItems
{
private:
    string refridgerator;
    string microwaveOven;
    string stove;

public:
    KElectronicItems();
    KElectronicItems(string fridge,string oven,string stove);
    KElectronicItems(const KElectronicItems & eItems);
    ~KElectronicItems();
    string getFridge();
    string getOven();
    string getStove();
    void setFridge(const QString &refridgerator);
    void setOven(const QString &microwaveoven);
    void setStove(const QString & stove);
public slots:
    void setFridgePath(const QString &path);
    void setOvenPath(const QString &path);
    void setStovePath(const QString &path);

};

#endif // KELECTRONICITEMS_H
