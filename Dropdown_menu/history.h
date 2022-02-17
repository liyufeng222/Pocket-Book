#ifndef HISTORY_H
#define HISTORY_H

#include <stack>
#include <map>
#include "snapshot.h"
#include "guicomponent.h"


class History  {


private:
    static std::stack<SnapShot> stack;
    static std::stack<SnapShot> stack_2;
    static std::map<std::string, GUIComponent*> components;
public:
    struct Response{
        bool found = false;
        GUIComponent* component;
    };
    static void pushHistory(const SnapShot& snapshot);
    static bool is_Empty_stack();
    static SnapShot& topHistory();
    static void popHistory();

    static void pushHistory_2(const SnapShot& snapshot);
    static bool is_Empty_stack_2();
    static SnapShot& topHistory_2();
    static void popHistory_2();

    static void addEventHandler(sf::RenderWindow& window, sf::Event event);
    static Response& getComponent(std::string componentID);
    static void addComponent(std::string componentID, GUIComponent* component);

};

#endif // HISTORY_H
