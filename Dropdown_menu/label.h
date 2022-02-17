#ifndef LABEL_H
#define LABEL_H

#include "guicomponent.h"
#include "font.h"


class Label : public GUIComponent
{
public:
    Label();

    //from the sf::Drawable class
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    // from EventHandler
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();

    //from SnapshotInterface
    SnapShot& getSnapshot();
    void applySnapshot(const SnapShot& snapshot);

    void set_string(string label_text);
    void set_size(unsigned int size);
    void set_color(sf::Color color);
    void set_position(sf::Vector2f position);

private:
    sf::Text label;
};

#endif // LABEL_H
