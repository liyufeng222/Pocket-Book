#include "font.h"

sf::Font Font::font = getFont();
void Font::loadFont(){
    if (!font.loadFromFile("arial.ttf")){
        std::cout<<"Font failed to load!!!"<<endl;
        std::cin.get();
        exit(-1);
    }
}
sf::Font Font::getFont(){
    loadFont();
    return font;
}
