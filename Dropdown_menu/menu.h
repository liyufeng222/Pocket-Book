#ifndef MENU_H
#define MENU_H

#include "guicomponent.h"
#include "textbox.h"
#include <string>
#include "font.h"
#include "history.h"
#include "itemlist.h"


class Menu : public GUIComponent
{
public:
    Menu();
    Menu(sf::Vector2f position, sf::Vector2f label_bound, string menu_name, vector<std::string> items);

    //from the sf::Drawable class
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    // from EventHandler
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();

    //from SnapshotInterface
    SnapShot& getSnapshot();
    void applySnapshot(const SnapShot& snapshot);

private:
    //States state;
    Font f;
    //sf::Text label;
    sf::Text label;
    ItemList itemList;
    TextBox text_box;


};

#endif // MENU_H
