#ifndef TYPING_H
#define TYPING_H
#include "guicomponent.h"
#include <string>
#include "font.h"
#include "multi_text.h"
#include "history.h"
using namespace std;


class Typing : public GUIComponent
{
public:
    Typing();
    Typing(sf::Vector2f box_pos, sf::Vector2f box_bound);

    //from the sf::Drawable class
    //draw all the onbject in Multi_Text (class multi_text draw)
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    // from EventHandler
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();

    //from SnapshotInterface
    SnapShot& getSnapshot();
    void applySnapshot(const SnapShot& snapshot);

    //==============================================================
    sf::FloatRect getText_Bound();

    //item_name or amount
    string get_Value() const;

    void set_string(string st);

private:
    string myString;
    sf::Text text;   //temporary replace with Multi-text later
    Multi_Text texts;
    SnapShot new_snapshot;
};

#endif // TYPING_H
