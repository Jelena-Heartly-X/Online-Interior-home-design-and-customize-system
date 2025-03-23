#ifndef LTHEME_H
#define LTHEME_H
#include <iostream>
#include <string>
#include <QString>

using namespace std;

class LTheme
{
private:
    string colourPalette;
public:
    LTheme();
    LTheme(string pallete);
    LTheme(const LTheme & theme);
    ~LTheme();
    string getColourPalette();
    void setColourPalette(const QString & palette);
public slots:
    void setColourPalettePath(const QString & path);
};
#endif // LTHEME_H
