#include "keyshortcuts.h"

#include <iostream>
using namespace std;


bool KeyShortcuts::isUndo(sf::Event event){
    return event.text.unicode == 26;   // ascii 26 is (ctrl + z)
}
