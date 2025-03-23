#ifndef KTHEME_H
#define KTHEME_H
#include <iostream>
#include <string>
#include <QDialog>
#include <QString>

using namespace std;

class KTheme
{
private:
    string colourPalette;
public:
    KTheme();
    KTheme(string palette);
    KTheme(const KTheme & theme);
    ~KTheme();
    string getColourPalette();
    void setColourPalette(const QString & palette);
public slots:
    void setColourPalettePath(const QString & path);
};

#endif // KTHEME_H
