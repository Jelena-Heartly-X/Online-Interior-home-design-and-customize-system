#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <string>

using namespace std;

class Room
{
private:
    string type;
    double length;
    double height;
    double breadth;
public:
    Room();
    Room(string roomType,double l,double h,double b);
    Room(const Room &room1);
    ~Room();
    string getType();
    double getLength();
    double getBreadth();
    double getHeight();
    void setType(string roomType);
    void setLength(double l);
    void setBreadth(double b);
    void setHeight(double h);
};

#endif // ROOM_H
