#include "snapshot.h"

SnapShot::SnapShot()
{
    myString = "UNKNOW";
}

SnapShot::SnapShot(string s){
    myString = s;
}

string SnapShot::get_string_data() const{
    return myString;
}

void SnapShot::set_String(string s){
    myString = s;
}

bool operator !=(const SnapShot& left, const SnapShot& right){
    return left.myString != right.myString;
}
bool operator ==(const SnapShot& left, const SnapShot& right){
    return left.myString == right.myString;
}

void SnapShot::set_states(std::map<ObjectState, bool> pre_states){
    this->pre_states = pre_states;
}
std::map<ObjectState, bool> SnapShot::get_pre_states() const{
    return pre_states;
}

void SnapShot::set_terms(std::vector<pair<string,double>> terms){
    this->terms = terms;
}
std::vector<pair<string,double>> SnapShot::get_terms() const{
    return terms;
}
