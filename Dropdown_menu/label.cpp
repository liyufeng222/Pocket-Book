#include "label.h"

Label::Label()
{
    Font f;
    label.setFont(f.font);
}


//from the sf::Drawable class
void Label::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(label);
}

// from EventHandler
void Label::addEventHandler(sf::RenderWindow& window, sf::Event event){

}
void Label::update(){

}

//from SnapshotInterface
SnapShot& Label::getSnapshot(){

}
void Label::applySnapshot(const SnapShot& snapshot){

}

void Label::set_string(string label_text){
    label.setString(label_text);
}
void Label::set_size(unsigned int size){
    label.setCharacterSize(size);
}
void Label::set_color(sf::Color color){
    label.setFillColor(color);
}
void Label::set_position(sf::Vector2f position){
    label.setPosition(position);
}

