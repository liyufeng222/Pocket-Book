#include "itemlist.h"
#include "keyshortcuts.h"

ItemList::ItemList()
{
    last_x = TEXT_BOX_3_POS.x;
    last_y = TEXT_BOX_3_POS.y + TEXT_BOX_3_BOUND.y;
    generate_items();

    //current_text = items.at(0).get_item_name();
    current_text = "Choose Type";

    enable_state(HIDDEN);
    hidden = true;
}

ItemList::ItemList(sf::Vector2f position, float main_box_y){
    last_x = position.x;
    last_y = position.y + main_box_y;
    //generate_items();

    //current_text = items.at(0).get_item_name();
    current_text = "";

    hidden = true;
}


void ItemList::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    if(!hidden){
        //cout<<"TEST"<<endl;
        for(Item item : items){

            window.draw(item);
        }
    }
}

// from EventHandler
void ItemList::addEventHandler(sf::RenderWindow& window, sf::Event event){
    auto mouse_pos = sf::Mouse::getPosition(window);
    auto translated_pos = window.mapPixelToCoords(mouse_pos);

    /*if(KeyShortcuts::isUndo(event)){    //when key board ask to undo
            if(!History::is_Empty_stack()){
                applySnapshot(History::topHistory());
                //apply the top snapshot
                History::popHistory();   //pop the top snapshot, because has used
            }
    }*/
    if(!hidden){
        /*for(Item item : items){
            if(MouseEvents<sf::RectangleShape>::mouseClicked(item.get_text_box(), window)){
                History::pushHistory(getSnapshot());
                current_text = item.get_item_name();
                enable_state(HIDDEN);
            }
        }*/

        for(vector<Item>::iterator it = items.begin();it != items.end();++it){
            if((*it).get_text_box().getGlobalBounds().contains(translated_pos)){
                sf::Color shadow = sf::Color::Blue;
                shadow.a = 70;
                (*it).set_color(sf::Color::Blue);
            }else{
                (*it).set_color(sf::Color(93,93,93));
            }
            (*it).addEventHandler(window,event);
            if(MouseEvents<sf::RectangleShape>::mouseClicked((*it).get_text_box(), window)){
                History::pushHistory(getSnapshot());
                current_text = (*it).get_item_name();
                //enable_state(HIDDEN);
                hidden = true;
            }
        }
    }

}
void ItemList::update(){
    /*if(is_State_Enable(HIDDEN)){
        hidden = true;
    }else{
        hidden = false;
    }*/
}

//from SnapshotInterface
SnapShot& ItemList::getSnapshot(){
    new_snapshot.set_String(current_text);
    new_snapshot.set_states(get_states());
    return new_snapshot;
}
void ItemList::applySnapshot(const SnapShot& snapshot){
    current_text = snapshot.get_string_data();
    set_states(snapshot.get_pre_states());
}


void ItemList::add_item(string item_name){
    Item new_item(item_name, sf::Vector2f(last_x, last_y), TEXT_BOX_3_BOUND);
    items.push_back(new_item);
}
void ItemList::generate_items(){
    for(string item_name : ITEMS){
        add_item(item_name);
        last_y += TEXT_BOX_3_BOUND.y;
    }
}

void ItemList::add_all_items(vector<std::string> items){
    for(string item_name : items){
        add_item(item_name);
        last_y += TEXT_BOX_3_BOUND.y;
    }
}

void ItemList::set_all_item_color(sf::Color color){
    for(vector<Item>::iterator it = items.begin();it != items.end();++it){
        (*it).set_color(color);
    }
}

string ItemList::get_current_item(){
    return current_text;
}

void ItemList::set_hidden(bool state){
    hidden = state;
}

void ItemList::set_string(string st){
    current_text = st;
}
