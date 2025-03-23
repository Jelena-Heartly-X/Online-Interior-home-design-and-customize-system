#include <iostream>
#include "Room.h"

using namespace std;

Room::Room():type(""),length(0.0),breadth(0.0),height(0.0)
{

}

Room::Room(string roomType,double l,double h,double b):type(roomType),length(l),breadth(b),height(h)
{

}

Room::Room(const Room &room1):type(room1.type),length(room1.length),breadth(room1.breadth),height(room1.height)
{

}

Room::~Room()
{

}

string Room::getType()
{
    return type;
}

double Room::getLength()
{
    return length;
}

double Room::getBreadth()
{
    return breadth;
}

double Room::getHeight()
{
    return height;
}

void Room::setType(string roomType)
{
    type=roomType;
}

void Room::setLength(double l)
{
    length=l;
}

void Room::setBreadth(double b)
{
    breadth=b;
}

void Room::setHeight(double h)
{
    height=h;
}
