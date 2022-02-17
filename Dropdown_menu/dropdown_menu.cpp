#include "dropdown_menu.h"

Dropdown_menu::Dropdown_menu()
{


    //default text_box
    text_box.set_bound(TEXT_BOX_3_BOUND);
    text_box.set_OutLine_color(sf::Color::White);
    text_box.set_OutLine_thick(2);
    text_box.set_position(TEXT_BOX_3_POS);

    label.setFont(f.font);
    label.setFillColor(sf::Color::White);
    label.setCharacterSize(CHARACTERS_SIZE_2);
    label.setString(itemList.get_current_item());
    label.setPosition(TEXT_BOX_3_POS.x + text_box.get_text_box().getGlobalBounds().width/2 - label.getGlobalBounds().width/2,
                      TEXT_BOX_3_POS.y + text_box.get_text_box().getGlobalBounds().height/2 - label.getGlobalBounds().height);

    itemList.set_hidden(true);
}


//from the sf::Drawable class
void Dropdown_menu::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(label);
    window.draw(text_box);
    window.draw(itemList);
}

// from EventHandler
void Dropdown_menu::addEventHandler(sf::RenderWindow& window, sf::Event event){
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
void Dropdown_menu::update(){
    label.setString(itemList.get_current_item());
    label.setPosition(TEXT_BOX_3_POS.x + text_box.get_text_box().getGlobalBounds().width/2 - label.getGlobalBounds().width/2,
                      TEXT_BOX_3_POS.y + text_box.get_text_box().getGlobalBounds().height/2 - label.getGlobalBounds().height);
    itemList.update();

}

//from SnapshotInterface
SnapShot& Dropdown_menu::getSnapshot(){

}
void Dropdown_menu::applySnapshot(const SnapShot& snapshot){

}

string Dropdown_menu::get_Value(){
    return itemList.get_current_item();
}

void Dropdown_menu::set_string(string st){
    itemList.set_string(st);
}
