#ifndef FURNITURE_H
#define FURNITURE_H
#include <string>
#include <iostream>
#include <QObject>

using namespace std;

class BFurniture
{
    private:
        string bed;
        string wardrobe;
        string desk;
        string lamps;
        string floorRug;
        string decItems;
    public:
        BFurniture();
        BFurniture(string bed,string wardrobe,string desk,string lamps,string floorRug,string decItems);
        BFurniture(const BFurniture & fur);
        ~BFurniture();
        string getBed();
        string getWardrobe();
        string getDesk();
        string getLamps();
        string getFloorRug();
        string getDecItems();
        void setBed(const QString &bed);
        void setWardrobe(const QString &wardrobe);
        void setdesk(const QString & desk);
        void setLamps(const QString & lamp);
        void setFloorRug(const QString & rug);
        void setDecItems(const QString & items);
    public slots:
        void setBedPath(const QString &path);
        void setWardRobePath(const QString &path);
        void setDeskPath(const QString &path);
        void setLampsPath(const QString &path);
        void setFloorRugPath(const QString &path);
        void setDecItemsPath(const QString &path);

};
    #endif // FURNITURE_H
