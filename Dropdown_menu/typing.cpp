#include "typing.h"
#include "constansts.h"
#include "keyshortcuts.h"    //###

Typing::Typing()
{

}

Typing::Typing(sf::Vector2f box_pos, sf::Vector2f box_bound){
    texts = Multi_Text(box_pos,box_bound);
}

void Typing::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    //window.draw(text);
    window.draw(texts);
}

// from EventHandler
void Typing::addEventHandler(sf::RenderWindow& window, sf::Event event){
    if(event.type != sf::Event::TextEntered){
        return;
    }
    if(event.text.unicode == 8){    //delet key
        if(!myString.empty()){
            History::pushHistory(getSnapshot());
        }     //only save the string when not empty
        myString = myString.substr(0,myString.size()-1);
    }else if(event.text.unicode == 13 || (31<event.text.unicode && event.text.unicode <127)){
        History::pushHistory(getSnapshot());
        myString += static_cast<char>(event.text.unicode);   //add the letter to string

    }else if(KeyShortcuts::isUndo(event)){    //when key board ask to undo
        if(!History::is_Empty_stack()){
            applySnapshot(History::topHistory());
            //apply the top snapshot
            History::popHistory();   //pop the top snapshot, because has used
        }
    }/*else if(event.text.unicode == 13){
        cout <<"return"<<endl;
    }*/
}
void Typing::update(){
    texts.set_String(myString);
    //text.setString(myString);
    texts.update();
}

//from SnapshotInterface
SnapShot& Typing::getSnapshot(){
    new_snapshot.set_String(myString);
    return new_snapshot;
}
void Typing::applySnapshot(const SnapShot& snapshot){
    myString = snapshot.get_string_data();
}


//==============================================

sf::FloatRect Typing::getText_Bound(){
    return texts.getLast_Text_Bounds();
}

string Typing::get_Value() const{
    return texts.get_Value();
}

void Typing::set_string(string st){
    myString = st;
}







