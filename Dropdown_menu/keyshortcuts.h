#ifndef KEYSHORTCUTS_H
#define KEYSHORTCUTS_H

#include <SFML/Graphics.hpp>


class KeyShortcuts
{
public:
    //event detect if use undo keyboard shortcut
    static bool isUndo( sf::Event event);
};

#endif // KEYSHORTCUTS_H
