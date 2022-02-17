#include "textbox.h"

TextBox::TextBox()
{
    text_box.setOutlineThickness(0);
    text_box.setFillColor(sf::Color::Transparent);
}

void TextBox::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(text_box);
}

// from EventHandler
void TextBox::addEventHandler(sf::RenderWindow& window, sf::Event event){

}
void TextBox::update(){

}

//from SnapshotInterface
SnapShot& TextBox::getSnapshot(){

}
void TextBox::applySnapshot(const SnapShot& snapshot){

}

//========================================================

void TextBox::set_bound(sf::Vector2f bound){
    text_box.setSize(bound);
}
void TextBox::set_color(sf::Color color){
    text_box.setFillColor(color);
}
void TextBox::set_position(sf::Vector2f position){
    text_box.setPosition(position);
}

void TextBox::set_OutLine_color(sf::Color color){
    text_box.setOutlineColor(color);
}
void TextBox::set_OutLine_thick(float size){
    text_box.setOutlineThickness(size);
}

sf::Vector2f TextBox::get_bound() const{
    return text_box.getSize();
}

//===========================================================
sf::RectangleShape& TextBox::get_text_box(){
    return text_box;
}

