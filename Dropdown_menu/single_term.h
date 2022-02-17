#ifndef SINGLE_TERM_H
#define SINGLE_TERM_H

#include "guicomponent.h"
#include "font.h"
#include "label.h"
#include <stdlib.h>


class Single_Term : public GUIComponent
{
public:
    Single_Term();
    Single_Term(string item_name, string amount_value, string type);

    void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    // from EventHandler
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();

    //from SnapshotInterface
    SnapShot& getSnapshot();
    void applySnapshot(const SnapShot& snapshot);

    void set_position(sf::Vector2f position);

    double get_Value();

    sf::RectangleShape& get_text_box();

    void edit(string item_name, string amount_value, string type);

    void set_box_outline(bool is_show);

    string get_name();
    string get_amount();
    string get_type();

private:
    sf::RectangleShape text_box;
    Label name;
    Label amount;
    string name_string;
    string value;
    bool is_positive = true;
};

#endif // SINGLE_TERM_H
