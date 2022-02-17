#include "filenode.h"

FileNode::FileNode()
{

}


FileNode::FileNode(Image::image icon, std::string text, sf::Vector2f size, sf::Vector2f position){
    data = FileItem(icon, text, size, position);
    my_position = position;
    last_y = my_position.y;
    is_show = false;
}

void FileNode::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    if(is_show){
        window.draw(data);
        for(map<string, FileNode*>::const_iterator it = children.begin();
            it != children.end(); ++it)
        {
            window.draw(*(it->second));
        }
    }
}

void FileNode::applySnapshot(const SnapShot& snapshot){

}

void FileNode::addEventHandler(sf::RenderWindow& window, sf::Event event){
    for(map<string, FileNode*>::const_iterator it = children.begin();
        it != children.end(); ++it)
    {
        it->second->addEventHandler(window,event);
    }

    auto mouse_pos = sf::Mouse::getPosition(window);
    auto translated_pos = window.mapPixelToCoords(mouse_pos);

    if(data.get_text_box().getGlobalBounds().contains(translated_pos)){
        sf::Color shadow = sf::Color::Red;
        shadow.a = 70;
        data.set_color(shadow);
    }else{
        data.set_color(sf::Color::Transparent);
    }
    data.addEventHandler(window, event);
    //itemList.addEventHandler(window,event);
    if(MouseEvents<sf::RectangleShape>::mouseClicked(data.get_text_box(), window)){
        //disable_state(HIDDEN);
        toggleChlidren();
    }
}
void FileNode::update(){
    /*if(is_show){
        last_y = update_y(last_y);
        for(map<string, FileNode*>::const_iterator it = children.begin();
            it != children.end(); ++it)
        {
            it->second->update();
        }
    }*/
    last_y = 0;
    update_y(last_y);
}

float FileNode::update_y(float last_y){
    if(is_show){
        data.setPosition(sf::Vector2f(data.getPosition().x, last_y));
        this->last_y = last_y + Y_SPACE;
        for(map<string, FileNode*>::const_iterator it = children.begin();
            it != children.end(); ++it)
        {
            this->last_y = it->second->update_y(this->last_y);
        }
        return this->last_y;
    }
    return last_y;

}

SnapShot& FileNode::getSnapshot(){
    //does nothing now
}

sf::FloatRect FileNode::getGlobalBounds(){
    //does nothing now
}

bool FileNode::isLeaf() const{
    return children.empty();
}

FileItem &FileNode::getData(){
    return data;
}
void FileNode::setData(const FileItem &data){
    this->data = data;
}
std::map<std::string, FileNode*>& FileNode::getChildren(){
    return children;
}

void FileNode::set_state(bool state){
    is_show = state;
}
void FileNode::change_state(){
    is_show = !is_show;
}

void FileNode::add_child(Image::image icon, std::string text){
    last_y += Y_SPACE;
    children[text] = new FileNode(icon, text, DEFAULT_SIZE, sf::Vector2f{my_position.x + SPACE, last_y});
}

FileNode::iterator FileNode::begin(){
    return children.begin();
}
FileNode::iterator FileNode::end(){
    return children.end();
}

//private
void FileNode::toggleChlidren(){
    //cout << "Click"<<endl;
    for(map<string, FileNode*>::const_iterator it = children.begin();
        it != children.end(); ++it)
    {
        it->second->change_state();
    }
}


void FileNode::reposition(){
    //data.setPosition(sf::Vector2f(data.getPosition().x, BOTTOM));
    //BOTTOM += Y_SPACE;
}
