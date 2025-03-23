#ifndef FLOORING_H
#define FLOORING_H
#include <iostream>
#include <string>

using namespace std;

class BFlooring
{
private:
    string flooringName;
public:
    BFlooring();
    BFlooring(string name);
    BFlooring(const BFlooring & floor);
    ~BFlooring();
};

class LFlooring
{
private:
    string flooringName;
public:
    LFlooring();
    LFlooring(string name);
    LFlooring(const BLlooring & floor);
    ~LFlooring();
};

class KFlooring
{
private:
    string flooringName;
public:
    KFlooring();
    KFlooring(string name);
    KFlooring(const BKlooring & floor);
    ~KFlooring();
};

#endif // FLOORING_H
