#ifndef LFURNITURE_H
#define LFURNITURE_H
#include <iostream>
#include <string>
#include <QString>

using namespace std;
class LFurniture
{
private:
    string sofa;
    string table;
    string tvStand;
    string bookShelf;
    string floorRug;
    string lamps;
    string decItems;
public:
    LFurniture();
    LFurniture(string sofa,string table,string tvStand,string bookShelf,string floorRug,string lamps,string decItem);
    LFurniture(const LFurniture & fur);
    ~LFurniture();
    string getSofa();
    string getTable();
    string getTvStand();
    string getBookShelf();
    string getFloorRug();
    string getLamps();
    string getDecItems();
    void setSofa(const QString & sofa);
    void setTable(const QString & table);
    void setTvStand(const QString & tvStand);
    void setBookShelf(const QString & bookShelf);
    void setFloorRug(const QString & floorRug);
    void setLamps(const QString & lamps);
    void setDecItems(const QString & decItems);
public slots:
    void setSofaPath(const QString &path);
    void setTablePath(const QString &path);
    void setTvStandPath(const QString &path);
    void setBookShelfPath(const QString &path);
    void setFloorRugPath(const QString &path);
    void setLampsPath(const QString &path);
    void setDecItemsPath(const QString &path);
};


#endif // LFURNITURE_H
