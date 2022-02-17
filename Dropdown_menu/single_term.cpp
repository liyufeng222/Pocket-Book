#include "single_term.h"

Single_Term::Single_Term()
{
    name.set_string("UNKNOWN");
    value = "100";
    //amount.set_string(amount_value);
    name.set_size(CHARACTERS_SIZE_2);
    amount.set_size(CHARACTERS_SIZE_2);
        amount.set_string("+ " + value);
        name.set_color(sf::Color::Green);
        amount.set_color(sf::Color::Green);
        is_positive = true;
    text_box.setOutlineThickness(0);
    text_box.setFillColor(sf::Color::Transparent);
    text_box.setSize(sf::Vector2f(1700, CHARACTERS_SIZE_2 + 10));
    text_box.setOutlineColor(sf::Color::White);
}
Single_Term::Single_Term(string item_name, string amount_value, string type){
    name.set_string(item_name);
    value = amount_value;
    name_string = item_name;
    //amount.set_string(amount_value);
    name.set_size(CHARACTERS_SIZE_2);
    amount.set_size(CHARACTERS_SIZE_2);
    if(type == "Income"){
        amount.set_string("+ " + amount_value);
        name.set_color(sf::Color::Green);
        amount.set_color(sf::Color::Green);
        is_positive = true;
    }else{
        amount.set_string("- " + amount_value);
        name.set_color(sf::Color::Red);
        amount.set_color(sf::Color::Red);
        is_positive = false;
    }
    text_box.setOutlineThickness(0);
    text_box.setFillColor(sf::Color::Transparent);
    text_box.setSize(sf::Vector2f(1600, CHARACTERS_SIZE_2));
    text_box.setOutlineColor(sf::Color::White);
}

void Single_Term::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(name);
    window.draw(amount);
    window.draw(text_box);
}

// from EventHandler
void Single_Term::addEventHandler(sf::RenderWindow& window, sf::Event event){
    auto mouse_pos = sf::Mouse::getPosition(window);
    auto translated_pos = window.mapPixelToCoords(mouse_pos);

    if(text_box.getGlobalBounds().contains(translated_pos)){
        sf::Color shadow = sf::Color::Cyan;
        shadow.a = 70;
        text_box.setFillColor(shadow);
    }else{
        text_box.setFillColor(sf::Color::Transparent);
    }

}
void Single_Term::update(){

}

//from SnapshotInterface
SnapShot& Single_Term::getSnapshot(){

}
void Single_Term::applySnapshot(const SnapShot& snapshot){

}

//========================================================================
void Single_Term::set_position(sf::Vector2f position){
    text_box.setPosition(position);
    name.set_position(position);
    amount.set_position(sf::Vector2f(position.x + 300,position.y));
}

double Single_Term::get_Value(){
    if(is_positive){
        return atof(value.c_str());
    }else{
        return -1*atof(value.c_str());
    }
}

sf::RectangleShape& Single_Term::get_text_box(){
    return text_box;
}

void Single_Term::edit(string item_name, string amount_value, string type){
    name.set_string(item_name);
    value = amount_value;
    name_string = item_name;
    //amount.set_string(amount_value);
    if(type == "Income"){
        amount.set_string("+ " + amount_value);
        name.set_color(sf::Color::Green);
        amount.set_color(sf::Color::Green);
        is_positive = true;
    }else{
        amount.set_string("- " + amount_value);
        name.set_color(sf::Color::Red);
        amount.set_color(sf::Color::Red);
        is_positive = false;
    }
}

void Single_Term::set_box_outline(bool is_show){
    if(is_show){
        text_box.setOutlineThickness(1);
    }else{
        text_box.setOutlineThickness(0);
    }
}

string Single_Term::get_name(){
    return name_string;
}
string Single_Term::get_amount(){
    return value;
}
string Single_Term::get_type(){
    if(is_positive){
        return "Income";
    }else{
        return "Cost";
    }
}
