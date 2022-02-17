#include "menu.h"

Menu::Menu()
{

}

Menu::Menu(sf::Vector2f position, sf::Vector2f label_bound, string menu_name, vector<std::string> items){
    //default text_box
    text_box.set_bound(label_bound);
    text_box.set_color(sf::Color::Transparent);
    text_box.set_position(position);

    label.setFont(f.font);
    label.setFillColor(sf::Color::White);
    label.setCharacterSize(CHARACTERS_SIZE);
    label.setString(menu_name);
    label.setPosition(position.x + text_box.get_text_box().getGlobalBounds().width/2 - label.getGlobalBounds().width/2,
                      position.y + text_box.get_text_box().getGlobalBounds().height/2 - label.getGlobalBounds().height);

    itemList = ItemList(position, label_bound.y);
    itemList.add_all_items(items);

    itemList.set_all_item_color(sf::Color(93,93,93));
    //cout<<"Here"<<endl;
}

//from the sf::Drawable class
void Menu::draw(sf::RenderTarget& window, sf::RenderStates states) const{

    window.draw(text_box);
    window.draw(label);
    window.draw(itemList);
}

// from EventHandler
void Menu::addEventHandler(sf::RenderWindow& window, sf::Event event){
    auto mouse_pos = sf::Mouse::getPosition(window);
    auto translated_pos = window.mapPixelToCoords(mouse_pos);

    if(text_box.get_text_box().getGlobalBounds().contains(translated_pos)){
        sf::Color shadow = sf::Color::Red;
        shadow.a = 70;
        text_box.set_color(shadow);
    }else{
        text_box.set_color(sf::Color::Transparent);
    }

    itemList.addEventHandler(window,event);
    if(MouseEvents<sf::RectangleShape>::mouseClicked(text_box.get_text_box(), window)){
        //disable_state(HIDDEN);
        itemList.set_hidden(false);

    }else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && !MouseEvents<sf::RectangleShape>::mouseClicked(text_box.get_text_box(), window)){
        //click but not click the box
        //enable_state(HIDDEN);
        itemList.set_hidden(true);

    }
    /*if(!is_State_Enable(HIDDEN)){
        itemList.addEventHandler(window,event);
    }*/

}
void Menu::update(){
    //label.setString(itemList.get_current_item());
    //label.setPosition(TEXT_BOX_POS.x + text_box.get_text_box().getGlobalBounds().width/2 - label.getGlobalBounds().width/2,
     //                 TEXT_BOX_POS.y + text_box.get_text_box().getGlobalBounds().height/2 - label.getGlobalBounds().height);
    itemList.update();

}

//from SnapshotInterface
SnapShot& Menu::getSnapshot(){

}
void Menu::applySnapshot(const SnapShot& snapshot){

}
