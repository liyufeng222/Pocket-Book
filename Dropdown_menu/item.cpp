#include "item.h"

Item::Item()
{
    Font f;
    this->item_name.setFont(f.font);
}

Item::Item(string item_name, sf::Vector2f position, sf::Vector2f bound){
    Font f;
    this->item_name.setFont(f.font);



    text_box.setOutlineThickness(2);
    text_box.setFillColor(sf::Color::Transparent);
    text_box.setSize(bound);

    _item_name = item_name;
    this->item_name.setString(item_name);
    this->item_name.setCharacterSize(CHARACTERS_SIZE);
    this->item_name.setFillColor(sf::Color::White);

    set_position(position);
}


void Item::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(text_box);
    window.draw(item_name);
}

// from EventHandler
void Item::addEventHandler(sf::RenderWindow& window, sf::Event event){
    if(_item_name == "Close" && MouseEvents<sf::RectangleShape>::mouseClicked(get_text_box(), window)){
        //cout<<"hhh"<<endl;
        States::enable_state(CLOSE);
    }else if(_item_name == "Open" && MouseEvents<sf::RectangleShape>::mouseClicked(get_text_box(), window)){
        States::enable_state(OPEN);
    }else if(_item_name == "New" && MouseEvents<sf::RectangleShape>::mouseClicked(get_text_box(), window)){
        States::enable_state(NEW);
    }else if(_item_name == "Save" && MouseEvents<sf::RectangleShape>::mouseClicked(get_text_box(), window)){
        States::enable_state(SAVE);
    }else if(_item_name == "Undo" && MouseEvents<sf::RectangleShape>::mouseClicked(get_text_box(), window)){
        States::enable_state(UNDO);
    }else if(_item_name == "Redo" && MouseEvents<sf::RectangleShape>::mouseClicked(get_text_box(), window)){
        States::enable_state(REDO);
    }else if(_item_name == "Export" && MouseEvents<sf::RectangleShape>::mouseClicked(get_text_box(), window)){
        States::enable_state(EXPORT);
    }
}
void Item::update(){

}

//from SnapshotInterface
SnapShot& Item::getSnapshot(){

}
void Item::applySnapshot(const SnapShot& snapshot){

}

//========================================================

void Item::set_bound(sf::Vector2f bound){
    text_box.setSize(bound);
}
void Item::set_color(sf::Color color){
    text_box.setFillColor(color);
}
void Item::set_position(sf::Vector2f position){
    text_box.setPosition(position);
    item_name.setPosition(position.x + text_box.getGlobalBounds().width/2 - item_name.getGlobalBounds().width/2,
                         position.y + text_box.getGlobalBounds().height/2 - item_name.getGlobalBounds().height);
}

sf::Vector2f Item::get_bound() const{
    return text_box.getSize();
}

string Item::get_item_name() const{
    return _item_name;
}

sf::RectangleShape& Item::get_text_box(){
    return text_box;
}

