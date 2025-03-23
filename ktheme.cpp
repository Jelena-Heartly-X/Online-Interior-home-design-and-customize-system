#include "kthemeui.h"
#include "ui_kthemeui.h"
#include <QPixmap>
#include "ktheme.h"
#include <iostream>
#include <QMessageBox>
#include <fstream>

using namespace std;

KTheme::KTheme():colourPalette()
{

}

KTheme::KTheme(string pallete):colourPalette(pallete)
{

}

KTheme::KTheme(const KTheme & theme):colourPalette(theme.colourPalette)
{

}

KTheme::~KTheme()
{

}

string KTheme::getColourPalette()
{
    return colourPalette;
}

void KTheme::setColourPalette(const QString & palette)
{
    this->colourPalette = palette.toStdString();
}

void KTheme::setColourPalettePath(const QString & path)
{
    this->setColourPalette(path);
}
