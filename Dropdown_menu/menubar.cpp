#include "menubar.h"

MenuBar::MenuBar()
{
    Menu m1(sf::Vector2f(0,0), sf::Vector2f(150,50), "File", FILE_ITEMS);
    Menu m2(sf::Vector2f(150,0), sf::Vector2f(150,50), "Edit", EDIT_ITEMS);
    Menu m3(sf::Vector2f(300,0), sf::Vector2f(150,50), "Render", RENDER_ITEMS);

    menus.push_back(m1);
    menus.push_back(m2);
    menus.push_back(m3);

}


//from the sf::Drawable class
void MenuBar::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    for(Menu m : menus){
        window.draw(m);
    }
}

// from EventHandler
void MenuBar::addEventHandler(sf::RenderWindow& window, sf::Event event){
    for(vector<Menu>::iterator it = menus.begin();it != menus.end();++it){
        it->addEventHandler(window, event);
    }

}
void MenuBar::update(){

}

//from SnapshotInterface
SnapShot& MenuBar::getSnapshot(){

}
void MenuBar::applySnapshot(const SnapShot& snapshot){

}
