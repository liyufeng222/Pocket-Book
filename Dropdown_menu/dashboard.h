#ifndef DASHBOARD_H
#define DASHBOARD_H

#include "textbox.h"
#include "label.h"
#include "guicomponent.h"
#include "single_term.h"
#include "mouseevents.h"
#include "fstream"
#include "sstream"


class DashBoard : public GUIComponent
{
public:
    DashBoard();

    //from the sf::Drawable class
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    // from EventHandler
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();

    //from SnapshotInterface
    SnapShot& getSnapshot();
    void applySnapshot(const SnapShot& snapshot);

    //=========================================================================
    void add_item(string item_name, string amount_value, string type);
    void edit_item(string item_name, string amount_value, string type);
    void delect();

    double get_total();

    bool get_is_update() const;
    void set_is_update();

    string get_current_name();
    string get_current_amount();
    string get_current_type();

    void output_file(string file_address);
    void open_file(string file_address);

private:
    //Dashboard
    TextBox tb;
    Label topic;

    int current_index = -1;

    double total_value;
    Label balance;
    Label value;

    vector<Single_Term> terms;

    //void get_current_index(sf::RenderTarget& window);
    bool is_update = true;

    SnapShot sp;
};

#endif // DASHBOARD_H
