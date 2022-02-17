#ifndef ITEM_H
#define ITEM_H

#include "guicomponent.h"
#include "font.h"
#include "mouseevents.h"

class Item : public GUIComponent
{
public:
    Item();
    Item(string item_name, sf::Vector2f position, sf::Vector2f bound);

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

     sf::Vector2f get_bound() const;

     string get_item_name() const;

     sf::RectangleShape& get_text_box();


private:
    sf::RectangleShape text_box;
    string _item_name;
    sf::Text item_name;

};

#endif // ITEM_H
