#ifndef LFLOORING_H
#define LFLOORING_H
#include <iostream>
#include <string>
#include <QString>

using namespace std;
class LFlooring
{
private:
    string flooringName;
public:
    LFlooring();
    LFlooring(string name);
    LFlooring(const LFlooring & floor);
    ~LFlooring();
    string getFlooringName();
    void setFlooringName(const QString & name);
public slots:
    void setFlooringNamePath(const QString & path);
};
#endif // LFLOORING_H
