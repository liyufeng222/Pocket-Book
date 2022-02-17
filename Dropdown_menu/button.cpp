#include "button.h"

Button::Button()
{
    Font f;
    this->button_name.setFont(f.font);
}

Button::Button(string Button_name, sf::Vector2f position, sf::Vector2f bound){
    Font f;
    this->button_name.setFont(f.font);



    text_box.setOutlineThickness(2);
    text_box.setFillColor(sf::Color::Transparent);
    text_box.setSize(bound);

    _button_name = Button_name;
    this->button_name.setString(Button_name);
    this->button_name.setCharacterSize(CHARACTERS_SIZE);
    this->button_name.setFillColor(sf::Color::White);

    set_position(position);
}


void Button::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(text_box);
    window.draw(button_name);
}

// from EventHandler
void Button::addEventHandler(sf::RenderWindow& window, sf::Event event){
    auto mouse_pos = sf::Mouse::getPosition(window);
    auto translated_pos = window.mapPixelToCoords(mouse_pos);

    if(get_text_box().getGlobalBounds().contains(translated_pos)){
        sf::Color shadow = sf::Color::Red;
        shadow.a = 70;
        set_color(shadow);
    }else{
        set_color(sf::Color::Transparent);
    }
}
void Button::update(){

}

//from SnapshotInterface
SnapShot& Button::getSnapshot(){

}
void Button::applySnapshot(const SnapShot& snapshot){

}

//========================================================

void Button::set_bound(sf::Vector2f bound){
    text_box.setSize(bound);
}
void Button::set_color(sf::Color color){
    text_box.setFillColor(color);
}
void Button::set_position(sf::Vector2f position){
    text_box.setPosition(position);
    button_name.setPosition(position.x + text_box.getGlobalBounds().width/2 - button_name.getGlobalBounds().width/2,
                         position.y + text_box.getGlobalBounds().height/2 - button_name.getGlobalBounds().height);
}

sf::Vector2f Button::get_bound() const{
    return text_box.getSize();
}

string Button::get_button_name() const{
    return _button_name;
}

sf::RectangleShape& Button::get_text_box(){
    return text_box;
}
