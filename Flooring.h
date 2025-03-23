#ifndef FLOORING_H
#define FLOORING_H
#include <iostream>
#include <string>
#include <QString>

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
    string getFlooringName();
    void setFlooringName(const QString & flooring);
public slots:
    void setFlooringNamePath(const QString & path);
};



#endif // FLOORING_H
