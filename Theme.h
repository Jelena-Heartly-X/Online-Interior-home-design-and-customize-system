#ifndef THEME_H
#define THEME_H
#include <iostream>
#include <string>
#include <QDialog>
#include <QString>

using namespace std;

class BTheme
{
private:
    string colourPalette;
public:
    BTheme();
    BTheme(string palette);
    BTheme(const BTheme & theme);
    ~BTheme();
    string getColourPalette();
    void setColourPalette(const QString & palette);
public slots:
    void setColourPalettePath(const QString & path);
};

#endif // THEME_H
