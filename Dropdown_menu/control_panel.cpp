#include "control_panel.h"

Control_Panel::Control_Panel()
{
    t1 = Text_Input(TEXT_BOX_1_POS, TEXT_BOX_1_BOUND, sf::Color::Blue);
    t1.setLabel("Item Name:");
    t1.setlabel_size(CHARACTERS_SIZE_1);
    t1.setlabel_color(sf::Color::Blue);
    t1.setlabel_position(TEXT_BOX_1_POS.x,TEXT_BOX_1_POS.y - 80);

    t2 = Text_Input(TEXT_BOX_2_POS, TEXT_BOX_2_BOUND, sf::Color::Green);
    t2.setLabel("Amount:");
    t2.setlabel_size(CHARACTERS_SIZE_1);
    t2.setlabel_color(sf::Color::Green);
    t2.setlabel_position(TEXT_BOX_2_POS.x - 200,TEXT_BOX_2_POS.y);

    type.set_string("Type: ");
    type.set_size(CHARACTERS_SIZE_1);
    type.set_color(sf::Color::Red);
    type.set_position(sf::Vector2f{TEXT_BOX_3_POS.x-150,TEXT_BOX_3_POS.y});

    b1 = Button("Add", sf::Vector2f(1530, 900), sf::Vector2f(200, 80));
    b2 = Button("Delete", sf::Vector2f(1530, 1000), sf::Vector2f(200, 80));
    b3 = Button("Edit", sf::Vector2f(1530, 1100), sf::Vector2f(200, 80));

    /*//dashboard
    tb.set_bound(sf::Vector2f(1700,730));
    tb.set_position(sf::Vector2f(50,130));
    tb.set_OutLine_color(sf::Color::Cyan);
    tb.set_OutLine_thick(2);

    topic.set_string("Detail: ");
    topic.set_size(CHARACTERS_SIZE_1);
    topic.set_color(sf::Color::Cyan);
    topic.set_position(sf::Vector2f{30,50});*/
}

//from the sf::Drawable class
void Control_Panel::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(t1);
    window.draw(t2);

    window.draw(d1);
    window.draw(type);

    window.draw(b1);
    window.draw(b2);
    window.draw(b3);

    window.draw(db);
}

// from EventHandler
void Control_Panel::addEventHandler(sf::RenderWindow& window, sf::Event event){
    t1.addEventHandler(window, event);
    t2.addEventHandler(window, event);

    d1.addEventHandler(window,event);

    b1.addEventHandler(window,event);
    b2.addEventHandler(window,event);
    b3.addEventHandler(window,event);

    db.addEventHandler(window,event);

    //add
    if(MouseEvents<sf::RectangleShape>::mouseClicked(b1.get_text_box(), window)){
        History::pushHistory_2(db.getSnapshot());
        //cout<< "Name: "<< t1.get_Value()<<endl;

        db.add_item(name, amount, type_text);
        t1.set_string("");
        t2.set_string("");
        d1.set_string("Choose Type");
    }
    //delect
    if(MouseEvents<sf::RectangleShape>::mouseClicked(b2.get_text_box(), window)){
        History::pushHistory_2(db.getSnapshot());
        //cout<<"DEL"<<endl;
        db.delect();

    }
    //edit
    if(MouseEvents<sf::RectangleShape>::mouseClicked(b3.get_text_box(), window)){
        History::pushHistory_2(db.getSnapshot());
        //cout<<"DEL"<<endl;
        db.edit_item(name, amount, type_text);

    }
}
void Control_Panel::update(){
    t1.update();
    t2.update();

    d1.update();
    db.update();

    if(!db.get_is_update()){
        t1.set_string(db.get_current_name());
        t2.set_string(db.get_current_amount());
        d1.set_string(db.get_current_type());
        db.set_is_update();
    }


    name = t1.get_Value();
    amount = t2.get_Value();
    type_text = d1.get_Value();
}

//from SnapshotInterface
SnapShot& Control_Panel::getSnapshot(){

}
void Control_Panel::applySnapshot(const SnapShot& snapshot){
    db.applySnapshot(snapshot);
}

void Control_Panel::output_file(string file_address){
    db.output_file(file_address);
}

void Control_Panel::open_file(string file_address){
    db.open_file(file_address);
}

