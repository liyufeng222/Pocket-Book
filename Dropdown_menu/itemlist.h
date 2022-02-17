#ifndef ITEMLIST_H
#define ITEMLIST_H

#include "guicomponent.h"
#include "item.h"
#include "mouseevents.h"
#include "history.h"

class ItemList : public GUIComponent
{
public:
    ItemList();
    ItemList(sf::Vector2f position, float main_box_y);

    void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    // from EventHandler
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();

    //from SnapshotInterface
    SnapShot& getSnapshot();
    void applySnapshot(const SnapShot& snapshot);


    void add_item(string item_name);
    void generate_items();

    void add_all_items(vector<std::string> items);

    void set_all_item_color(sf::Color color);

    string get_current_item();

    void set_hidden(bool state);

    void set_string(string st);

private:
    float last_x;
    float last_y;
    vector<Item> items;

    string current_text;

    bool hidden;

    SnapShot new_snapshot;
};

#endif // ITEMLIST_H
