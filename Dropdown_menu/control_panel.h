#ifndef CONTROL_PANEL_H
#define CONTROL_PANEL_H

//#include "guicomponent.h"
#include "text_input.h"
#include "dropdown_menu.h"
#include "button.h"
#include "dashboard.h"

class Control_Panel : public GUIComponent
{
public:
    Control_Panel();

    //from the sf::Drawable class
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    // from EventHandler
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();

    //from SnapshotInterface
    SnapShot& getSnapshot();
    void applySnapshot(const SnapShot& snapshot);

    void output_file(string file_address);
    void open_file(string file_address);

private:
    //text box 1(item name)
    Text_Input t1;
    //label 1(item name)

    //text box 2(Amount)
    Text_Input t2;
    //label 2(Amount)

    //dropdown Menu(type)
    Dropdown_menu d1;
    //label 3(type)
    Label type;

    //button(add)
    Button b1;
    //button(delete)
    Button b2;
    //butteon(edit)
    Button b3;

    //Dashboard
    DashBoard db;


    //Data
    string name;
    string amount;
    string type_text;
};

#endif // CONTROL_PANEL_H
