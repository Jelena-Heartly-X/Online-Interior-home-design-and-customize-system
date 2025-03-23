#ifndef HOME_H
#define HOME_H
#include "Room.h"
#include <vector>

using namespace std;

class Home
{
private:
    double area;
public:
    Home();
    Home(double area1);
    Home(const Home &home1);
    double getArea();
    void setArea(double area1);
    void addRoom(Room * room);
};

#endif // HOME_H
