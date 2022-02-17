#ifndef SNAPSHOT_H
#define SNAPSHOT_H

#include "states.h"
#include <string>
#include "vector"
#include <map>
using namespace std;

class SnapShot
{
public:
    SnapShot();
    SnapShot(string s);

    string get_string_data() const;
    void set_String(string s);

    void set_states(std::map<ObjectState, bool> pre_states);
    std::map<ObjectState, bool> get_pre_states() const;

    void set_terms(std::vector<pair<string,double>> terms);
    std::vector<pair<string,double>> get_terms() const;

    //===========================================
    friend bool operator !=(const SnapShot& left, const SnapShot& right);
    friend bool operator ==(const SnapShot& left, const SnapShot& right);

private:
    string myString;
    std::map<ObjectState, bool> pre_states;
    std::vector<pair<string,double>> terms;
};

#endif // SNAPSHOT_H
