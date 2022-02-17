#include "states.h"

std::map<ObjectState, bool> States::states;
std::string States::current_file_name;

States::States()
{
    for(int i = 0; i < LASTSTATE; i++){
        states[static_cast<ObjectState>(i)] = false;
    }
}

bool States::is_State_Enable(ObjectState state){
    return states[state];
}
void States::enable_state(ObjectState state){
    states[state] = true;
}
void States::disable_state(ObjectState state){
    states[state] = false;
}

std::map<ObjectState, bool> States::get_states() const{
    return states;
}

void States::set_states(std::map<ObjectState, bool> states){
    this->states = states;
}

void States::set_current_file(std::string file_name){
    current_file_name = file_name;
}
std::string States::get_current_file(){
    return current_file_name;
}
