#ifndef TEXT_INPUT_H
#define TEXT_INPUT_H

#include "guicomponent.h"
#include "typing.h"
#include "textbox.h"
#include "cursor.h"
#include <string>
#include "font.h"
#include "history.h"
#include "label.h"
#include "mouseevents.h"

using namespace std;


class Text_Input : public GUIComponent
{
public:
    Text_Input();
    Text_Input(sf::Vector2f box_pos, sf::Vector2f box_bound, sf::Color box_color);

    //from the sf::Drawable class
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    // from EventHandler
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();

    //from SnapshotInterface
    SnapShot& getSnapshot();
    void applySnapshot(const SnapShot& snapshot);

    //===================================================================
    void setLabel(string label_text);
    void setlabel_size(unsigned int size);
    void setlabel_color(const sf::Color& color);
    void setlabel_position(float x, float y);
    //====================================================================
    void setText_box_bound(sf::Vector2f bound);
    void setText_box_color(sf::Color color);
    void setText_box_position(sf::Vector2f position);
    //====================================================================

    //item_name or amount
    string get_Value() const;

    void set_string(string st);

    sf::RectangleShape& get_TextBox();

private:
    //States state;
    Font f;
    //sf::Text label;
    Label label;
    Typing typing;
    TextBox text_box;
    Cursor _cursor;

    //History history;

    //sf::Text text;   //temporary replace with Multi-text later
};

#endif // TEXT_INPUT_H
