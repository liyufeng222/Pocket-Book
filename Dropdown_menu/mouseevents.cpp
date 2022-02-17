#include "mouseevents.h"
#include <iostream>
using namespace std;

template <typename T>
sf::Clock MouseEvents<T>::clock;

template <typename T>
int MouseEvents<T>::clicks;

template <typename T>
bool MouseEvents<T>::mouseClicked(T& object, sf::RenderWindow& window){
    auto mouse_pos = sf::Mouse::getPosition(window);
    auto translated_pos = window.mapPixelToCoords(mouse_pos);
    return object.getGlobalBounds().contains(translated_pos) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

template <typename T>
bool MouseEvents<T>::mouseClicked( sf::RenderWindow& window, sf::Event event){
    if(event.type == sf::Event::MouseButtonPressed){
        cout<< sf::Mouse::getPosition(window).x<< "    "<< sf::Mouse::getPosition(window).y<<endl;
        if((sf::Mouse::getPosition(window).x < (TEXT_BOX_POS.x + TEXT_BOX_BOUND.x)) && (sf::Mouse::getPosition(window).x > (TEXT_BOX_POS.x))
                && (sf::Mouse::getPosition(window).y < (TEXT_BOX_POS.y + TEXT_BOX_BOUND.y)) && (sf::Mouse::getPosition(window).y > (TEXT_BOX_POS.y))){
            //in the text box

            states.disable_state(HIDDEN);
        }else{
            //out side the text box

            states.enable_state(HIDDEN);
        }
    }
}

template <typename T>
bool MouseEvents<T>::mouseDoubleClicked(){
    return clicks == 2;
}

template <typename T>
bool MouseEvents<T>::mouseTripleClicked(){
    return  clicks == 3;
}

template <typename T>
bool MouseEvents<T>::draggedOver(T& object, sf::RenderWindow& window, sf::Event event){
    /*if(event.type == sf::Event::MouseButtonPressed){
        auto mouse_pos = sf::Mouse::getPosition(window);
        auto translated_pos = window.mapPixelToCoords(mouse_pos);
        if(object.getGlobalBounds().contains(translated_pos) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            //object.
            //sf::Text do not have background
        }
    }*/

}

template <typename T>
bool MouseEvents<T>::hovered(T& object, sf::RenderWindow& window){

}

template <typename T>
void MouseEvents<T>::countClicks(sf::Event event){
    if(clock.getElapsedTime().asMilliseconds() > 500){
        clicks = 0;
        clock.restart();
    }

    if(event.type == sf::Event::MouseButtonReleased){
        //use released, because one click done on released
        clicks++;
    }
}
