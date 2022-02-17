#ifndef DROPDOWN_MENU_H
#define DROPDOWN_MENU_H

#include "guicomponent.h"
#include "textbox.h"
#include <string>
#include "font.h"
#include "history.h"
#include "itemlist.h"
#include "string.h"


class Dropdown_menu : public GUIComponent
{
public:
    Dropdown_menu();

    //Dropdown_menu()

    //from the sf::Drawable class
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    // from EventHandler
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();

    //from SnapshotInterface
    SnapShot& getSnapshot();
    void applySnapshot(const SnapShot& snapshot);

    string get_Value();

    void set_string(string st);

private:
    //States state;
    Font f;
    //sf::Text label;
    sf::Text label;
    ItemList itemList;
    TextBox text_box;


};

#endif // DROPDOWN_MENU_H
