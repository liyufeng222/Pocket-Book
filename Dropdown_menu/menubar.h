#ifndef MENUBAR_H
#define MENUBAR_H

#include "guicomponent.h"
#include "textbox.h"
#include <string>
#include "font.h"
#include "history.h"
#include "itemlist.h"
#include "menu.h"


class MenuBar : public GUIComponent
{
public:
    MenuBar();

    //from the sf::Drawable class
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    // from EventHandler
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();

    //from SnapshotInterface
    SnapShot& getSnapshot();
    void applySnapshot(const SnapShot& snapshot);

private:
    vector<Menu> menus;

    float last_x;
};

#endif // MENUBAR_H
