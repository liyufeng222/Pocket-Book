#ifndef EVENHANDLER_H
#define EVENHANDLER_H

#include <SFML/Graphics.hpp>

class EvenHandler
{
public:
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;

};

#endif // EVENHANDLER_H
