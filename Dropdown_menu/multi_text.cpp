#include "multi_text.h"

Multi_Text::Multi_Text()
{
    texts = stringToTexts(myString);
}

Multi_Text::Multi_Text(sf::Vector2f box_pos, sf::Vector2f box_bound){
    texts = stringToTexts(myString);
    TEXT_HEAD_POS = sf::Vector2f{box_pos.x+30,box_pos.y + box_bound.y/2 - CHARACTERS_SIZE_1/2};
}


void Multi_Text::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    for(sf::Text element : texts){
        window.draw(element);
    }
}

// from EventHandler
void Multi_Text::addEventHandler(sf::RenderWindow& window, sf::Event event){

}
void Multi_Text::update(){
    texts = stringToTexts(myString);
    //set_Texts_position();
}

//from SnapshotInterface
SnapShot& Multi_Text::getSnapshot(){

}
void Multi_Text::applySnapshot(const SnapShot& snapshot){

}

//============================================================================
vector<sf::Text> Multi_Text::stringToTexts(string s){
    vector<string> tokener = stringTokener(s);
    //step 1 get string to separate (act like a tokener)
    vector<sf::Text> texts = tokenerToTexts(tokener);
    //step 2 get the vector from tokener change to Texts vector
    return texts;
}

bool Multi_Text::isKeyWord(string s){
    for(string keyword : KEY_WORD){
        if(keyword == s){
            return true;
        }
    }
    return false;
}

void Multi_Text::set_String(string s){
    myString = s;
}

void Multi_Text::set_Texts_position(){
    float x = TEXT_HEAD_POS.x;
    //float y = TEXT_HEAD_POS.y;
    float y = TEXT_HEAD_POS.y;
    for(vector<sf::Text>::iterator it = texts.begin();it != texts.end();++it){
        (*it).setPosition(x, y);
        //x = x + element.getLocalBounds().width + LETTER_SPACEING;      //by calculating is not work
        x = (*it).getGlobalBounds().left + (*it).getLocalBounds().width + LETTER_SPACEING;
    }
}


sf::FloatRect Multi_Text::getLast_Text_Bounds(){
    vector<sf::Text>::iterator it_last = texts.end() - 1;  //get the last text out
    //sf::Text last = *it_last;
    sf::FloatRect new_rect = (*it_last).getGlobalBounds();
    new_rect.top = new_line_y;
    //return (*it_last).getGlobalBounds();
    return new_rect;
}

vector<string> Multi_Text::stringTokener(string s){
    bool is_need = true;
    vector<string> myStrings;
    string temp;

    for(string::iterator it = s.begin(); it != s.end(); ++it)       //the divider for the string  space or number or operator
    {
        if(*it == 13){
            //cout<< "Enter"<<endl;
            myStrings.push_back(temp);
            temp = "";
            string new_s;
            new_s += *it;
            myStrings.push_back(new_s);
            is_need = false;
        }else if(isspace(*it) || isdigit(*it) || !isalnum(*it)){
            myStrings.push_back(temp);
            temp = "";
            string new_s;
            new_s += *it;
            myStrings.push_back(new_s);
            is_need = false;
        }else{
            temp += *it;
            is_need = true;
        }
    }
    if(is_need){
        myStrings.push_back(temp);
    }

    return myStrings;
}

vector<sf::Text> Multi_Text::tokenerToTexts(vector<string> token){
    vector<sf::Text> texts;

    float x = TEXT_HEAD_POS.x;
    //float y = TEXT_HEAD_POS.y;
    float y = TEXT_HEAD_POS.y;

    bool single_line = true;

    for(std::vector<string>::iterator it = token.begin(); it != token.end(); ++it){
        sf::Text new_text;
        new_text.setString(*it);
        new_text.setFont(f.font);
        new_text.setCharacterSize(CHARACTERS_SIZE_1);
        if(!(*it).empty() && isdigit((*it).at(0))){
            new_text.setFillColor(sf::Color::Red);
            //texts.push_back(new_text);
        }else if(!(*it).empty() && (*it).at(0) == 13){
            new_text.setString("");
            y = y + CHARACTERS_SIZE_1 + LETTER_SPACEING;//(*texts.end()).getLocalBounds().height + LETTER_SPACEING;
            new_line_y = y;
            x = TEXT_HEAD_POS.x;
            single_line = false;
        }else if(!(*it).empty() && !isalnum((*it).at(0))){
            new_text.setFillColor(sf::Color::Green);
            //texts.push_back(new_text);
        }else if(isKeyWord(*it)){
            new_text.setFillColor(sf::Color::Blue);
            //texts.push_back(new_text);
        }else{
            new_text.setFillColor(sf::Color::White);
            //texts.push_back(new_text);
        }

        new_text.setPosition(x, y);
        //x = x + element.getLocalBounds().width + LETTER_SPACEING;      //by calculating is not work
        x = new_text.getGlobalBounds().left + new_text.getLocalBounds().width + LETTER_SPACEING;

        texts.push_back(new_text);
    }

    if(single_line){
        new_line_y = TEXT_HEAD_POS.y;
    }

    return texts;
}

string Multi_Text::get_Value() const{
    string temp = "";
    for(sf::Text element : texts){
        temp += element.getString();
    }
    return temp;
}



