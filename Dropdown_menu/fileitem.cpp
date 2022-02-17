#include "fileitem.h"

FileItem::FileItem()
{

}

FileItem::FileItem(Image::image icon, std::string text, sf::Vector2f size, sf::Vector2f position) : Item(text, position, size){
    _icon = icon;
    setIcon(icon);
    setPosition(position);
}

void FileItem::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    Item::draw(window, states);
    window.draw(icon);
}

// from EventHandler
void FileItem::addEventHandler(sf::RenderWindow& window, sf::Event event){
    if(MouseEvents<sf::RectangleShape>::mouseClicked(get_text_box(), window) && _icon == Image::FILE){
        //need name
        //cout<<"HERE"<<endl;
        cout<<get_item_name()<<endl;
        States::set_current_file("../"+get_item_name());
        States::enable_state(OPEN_FILE);
        window.close();
    }
    Item::addEventHandler(window, event);
}




//========================================================


sf::FloatRect FileItem::getGlobalBounds() const{

}
//returns the size of the item
sf::Vector2f FileItem::getSize() const{

}
//returns the size of the item
sf::Vector2f FileItem::getPosition() const{
    return sf::Vector2f(icon.getGlobalBounds().left, icon.getGlobalBounds().top);
}
//sets the position of the item
void FileItem::setPosition(sf::Vector2f pos){
    icon.setPosition(pos);
    Item::set_position(pos);
}
//uses an enum to change the icon to a folder or file
void FileItem::setIcon(Image::image icon){
    _icon = icon;
    this->icon.setTexture(Image::getImage(icon));
    if(icon == Image::FILE){
        this->icon.setScale(sf::Vector2f(0.05f, 0.05f));
    }else{
        this->icon.setScale(sf::Vector2f(0.025f, 0.025f));
    }

}
