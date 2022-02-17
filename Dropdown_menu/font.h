#ifndef FONT_H
#define FONT_H

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;


class Font
{
public:
    static sf::Font font;
private:
    static void loadFont();
    static sf::Font getFont();
};

#endif // FONT_H
