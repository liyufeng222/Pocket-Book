#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "guicomponent.h"


class TextBox : public GUIComponent
{
public:
    TextBox();
    //from the sf::Drawable class
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    // from EventHandler
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();

    //from SnapshotInterface
    SnapShot& getSnapshot();
    void applySnapshot(const SnapShot& snapshot);

    void set_bound(sf::Vector2f bound);
    void set_color(sf::Color color);
    void set_position(sf::Vector2f position);

    void set_OutLine_color(sf::Color color);
    void set_OutLine_thick(float size);

    sf::Vector2f get_bound() const;

    sf::RectangleShape& get_text_box();


private:
    sf::RectangleShape text_box;
};

#endif // TEXTBOX_H
