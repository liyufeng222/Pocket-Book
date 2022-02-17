#ifndef BUTTON_H
#define BUTTON_H

#include "guicomponent.h"
#include "font.h"

class Button : public GUIComponent
{
public:
    Button();
    Button(string item_name, sf::Vector2f position, sf::Vector2f bound);

    void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    // from EventHandler
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    // use for detect the button


    void update();

    //from SnapshotInterface
    SnapShot& getSnapshot();
    void applySnapshot(const SnapShot& snapshot);

    void set_bound(sf::Vector2f bound);
    void set_color(sf::Color color);
    void set_position(sf::Vector2f position);

     sf::Vector2f get_bound() const;

     string get_button_name() const;

     sf::RectangleShape& get_text_box();



private:
    sf::RectangleShape text_box;
    string _button_name;
    sf::Text button_name;

};

#endif // BUTTON_H
