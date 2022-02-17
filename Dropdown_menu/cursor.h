#ifndef CURSOR_H
#define CURSOR_H

#include "guicomponent.h"
#include "font.h"

//static sf::Clock my_clock;


class Cursor : public GUIComponent
{
public:
    Cursor();

    //from the sf::Drawable class
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    // from EventHandler
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();

    //from SnapshotInterface
    SnapShot& getSnapshot();
    void applySnapshot(const SnapShot& snapshot);

    //================================================
    void find_position(sf::FloatRect text_bound);

    //================================================
    void toggle_state(bool s);
    bool is_show() const;


private:
    //sf::Clock clock;
    sf::Text cursor;
    float x;
    float y;
    int blinkSpeed = 500;

    bool blinking = true;

    bool state = false;

    void changeState();

    sf::Clock my_clock;

};

#endif // CURSOR_H
