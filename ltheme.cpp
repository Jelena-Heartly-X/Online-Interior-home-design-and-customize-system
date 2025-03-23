#include "ltheme.h"

#include <iostream>

using namespace std;

LTheme::LTheme():colourPalette()
{

}

LTheme::LTheme(string pallete):colourPalette(pallete)
{

}

LTheme::LTheme(const LTheme & theme):colourPalette(theme.colourPalette)
{

}

LTheme::~LTheme()
{

}

string LTheme::getColourPalette()
{
    return colourPalette;
}

void LTheme::setColourPalette(const QString & palette)
{
    this->colourPalette = palette.toStdString();
}

void LTheme::setColourPalettePath(const QString & path)
{
    this->setColourPalette(path);
}
