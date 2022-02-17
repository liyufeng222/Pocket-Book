#include "cursor.h"

Cursor::Cursor(){
    Font f;
    cursor.setFont(f.font);

    cursor.setString("|");
    //cursor.setPosition(630,300);   //default position
    cursor.setCharacterSize(CHARACTERS_SIZE_1);
    //cursor size, position, color
}

bool Cursor::is_show() const{
    return state;
}

void Cursor::toggle_state(bool s){
    state = s;
}

void Cursor::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    if(blinking){
        window.draw(cursor);
    }
}

// from EventHandler
void Cursor::addEventHandler(sf::RenderWindow& window, sf::Event event){

}
void Cursor::update(){
    //if(is_State_Enable(HIDDEN)){
    if(!state){
        blinking = false;
    }
    if(my_clock.getElapsedTime().asMilliseconds() > blinkSpeed){
        changeState();
        my_clock.restart();
    }
    cursor.setPosition(x, y);
}

//from SnapshotInterface
SnapShot& Cursor::getSnapshot(){

}
void Cursor::applySnapshot(const SnapShot& snapshot){

}

void Cursor::find_position(sf::FloatRect text_bound){  //spaceing then broke
    x = text_bound.left + text_bound.width + LETTER_SPACEING;
    y = text_bound.top;//TEXT_HEAD_POS.y;  //move it a little up
}

void Cursor::changeState(){
    //if(!is_State_Enable(HIDDEN)){
    if(state){
        if(blinking)
            blinking = false;
        else {
            blinking = true;
        }
    }else{
        blinking = false;
    }
}


