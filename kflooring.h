#ifndef KFLOORING_H
#define KFLOORING_H
#include <iostream>
#include <string>
#include <QString>
using namespace std;

class KFlooring
{
private:
    string flooringName;
public:
    KFlooring();
    KFlooring(string name);
    KFlooring(const KFlooring & floor);
    ~KFlooring();
    string getFlooringName();
    void setFlooringName(const QString& name);
public slots:
    void setFlooringNamePath(const QString & path);
};

#endif // KFLOORING_H
