#include "history.h"

std::stack<SnapShot> History::stack;
std::stack<SnapShot> History::stack_2;
std::map<std::string, GUIComponent*> History::components;

void History::pushHistory(const SnapShot& snapshot){
    stack.push(snapshot);
}
SnapShot& History::topHistory(){
    return stack.top();
}
void History::popHistory(){
    if(!stack.empty()){
        stack.pop();
    }
}
void History::addEventHandler(sf::RenderWindow& window, sf::Event event){

}
History::Response& History::getComponent(std::string componentID){

}
void History::addComponent(std::string componentID, GUIComponent* component){

}

bool History::is_Empty_stack(){
    return stack.empty();
}

void History::pushHistory_2(const SnapShot& snapshot){
    stack_2.push(snapshot);
}
SnapShot& History::topHistory_2(){
    return stack_2.top();
}
void History::popHistory_2(){
    if(!stack_2.empty()){
        stack_2.pop();
    }
}
bool History::is_Empty_stack_2(){
    return stack_2.empty();
}
