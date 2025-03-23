#ifndef KFURNITURE_H
#define KFURNITURE_H
#include <iostream>
#include <string>
#include <QString>

using namespace std;
class KFurniture
{
private:
    string diningTable;
    string counterTop;
    string cabinet;
    string sink;
public:
    KFurniture();
    KFurniture(string diningTable,string counterTop,string cabinet,string sink);
    KFurniture(const KFurniture & fur);
    ~KFurniture();
    string getDiningTable();
    string getCounterTop();
    string getCabinet();
    string getSink();
    void setDiningTable(const QString &  diningTable);
    void setCounterTop(const QString & counterTop);
    void setCabinet(const QString & cabinet);
    void setSink(const QString & sink);
public slots:
    void setDiningTablePath(const QString & path);
    void setCounterTopPath(const QString & path);
    void setCabinetPath(const QString & path);
    void setSinkPath(const QString & path);
};

#endif // KFURNITURE_H
