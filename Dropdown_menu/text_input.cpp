#include "text_input.h"

Text_Input::Text_Input()
{
    //default text_box
    text_box.set_bound(TEXT_BOX_1_BOUND);
    text_box.set_OutLine_color(sf::Color::Blue);
    text_box.set_OutLine_thick(2);
    text_box.set_position(TEXT_BOX_1_POS);
}

Text_Input::Text_Input(sf::Vector2f box_pos, sf::Vector2f box_bound, sf::Color box_color)
{
    text_box.set_bound(box_bound);
    text_box.set_OutLine_color(box_color);
    text_box.set_OutLine_thick(2);
    text_box.set_position(box_pos);

    typing = Typing(box_pos,box_bound);
}

void Text_Input::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(label);
    window.draw(text_box);
    window.draw(typing);
    window.draw(_cursor);
}

// from EventHandler
void Text_Input::addEventHandler(sf::RenderWindow& window, sf::Event event){
    if(MouseEvents<sf::RectangleShape>::mouseClicked(get_TextBox(), window)){
        //States::disable_state(HIDDEN);
        _cursor.toggle_state(true);
        //click_event.setString("One Click inside box (1)");
    }else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && !MouseEvents<sf::RectangleShape>::mouseClicked(get_TextBox(), window)){
        //click but not click the box
        //States::enable_state(HIDDEN);
        _cursor.toggle_state(false);
        //click_event.setString("One Click outside box (1)");
    }


    //if(!is_State_Enable(HIDDEN)){
    if(_cursor.is_show()){
        typing.addEventHandler(window, event);
    }
}
void Text_Input::update(){
    //once typing update, cursor get the typing text postion for draw cursor
    typing.update();
   _cursor.find_position(typing.getText_Bound());
   //text_box.set_bound(sf::Vector2f(TEXT_BOX_1_BOUND.x, TEXT_BOX_1_BOUND.y + typing.getText_Bound().top - TEXT_BOX_1_POS.y));
   _cursor.update();

}

//from SnapshotInterface
SnapShot& Text_Input::getSnapshot(){
    return typing.getSnapshot();
}
void Text_Input::applySnapshot(const SnapShot& snapshot){
    typing.applySnapshot(snapshot);
}

//============================================================


void Text_Input::setLabel(string label_text){
    label.set_string(label_text);
}
void Text_Input::setlabel_size(unsigned int size){
    label.set_size(size);
}

void Text_Input::setlabel_color(const sf::Color& color){
    label.set_color(color);
}
void Text_Input::setlabel_position(float x, float y){
    label.set_position(sf::Vector2f(x,y));
}
//=============================================================

void Text_Input::setText_box_bound(sf::Vector2f bound){
    text_box.set_bound(bound);
}
void Text_Input::setText_box_color(sf::Color color){
    text_box.set_color(color);
}
void Text_Input::setText_box_position(sf::Vector2f position){
    text_box.set_position(position);
}


//=================================================================

sf::RectangleShape& Text_Input::get_TextBox(){
    return text_box.get_text_box();
}

string Text_Input::get_Value() const{
    return typing.get_Value();
}

void Text_Input::set_string(string st){
    typing.set_string(st);
}




