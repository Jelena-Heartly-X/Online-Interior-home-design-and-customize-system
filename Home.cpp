#include <iostream>
#include <string>
#include <vector>
#include "Home.h"

using namespace std;

Home::Home():area(0.0)
{

}

Home::Home(double area1):area(area1)
{

}

Home::Home(const Home &home1)
{
    this->area=home1.area;
}

double Home::getArea()
{
    return area;
}

void Home::setArea(double area1)
{
    area=area1;
}

