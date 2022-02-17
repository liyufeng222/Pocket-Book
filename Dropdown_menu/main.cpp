#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <time.h>
//#include "dropdown_menu.h"
#include "font.h"
//#include "mouseevents.h"
//#include "constansts.h"
//#include "keyshortcuts.h"
//#include "history.h"
#include "menubar.h"
#include "filetree.h"
//#include "text_input.h"
//#include "button.h"
#include "control_panel.h"
#include "states.h"

//test
//#include "fileitem.h"
//#include "filenode.h"

using namespace std;

void update_1(Control_Panel& cp);//sf::RenderWindow& window, sf::Event event);
void new_window();
static int file_name = 0;

int main(int argc, char *argv[])
{
    //----------S E T U P ------------------------------:

    //declare a window object:
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT),
                                                       "Yufeng_Project");

    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

    MenuBar m1;

    //control panel
    Control_Panel cp;


    //shadow top
    TextBox top;
    top.set_bound(sf::Vector2f(1800,50));
    top.set_position(sf::Vector2f(0,0));
    sf::Color shadow = sf::Color::Black;
    shadow.a = 50;
    top.set_color(sf::Color(93,93,93));


    while(window.isOpen())
        {
            sf::Event event;
            while(window.pollEvent(event))
            {
                if(event.type == sf::Event::Closed)
                    window.close();


                m1.addEventHandler(window,event);
                //add_event_1(window,event);
                if(!States::is_State_Enable(CLOSE)){
                    cp.addEventHandler(window, event);
                }
            }

            if(!States::is_State_Enable(CLOSE)){
                cp.update();
            }
            update_1(cp);

            window.clear();

            //draw=====================
            if(!States::is_State_Enable(CLOSE)){
                window.draw(cp);
            }

            window.draw(top);
            window.draw(m1);


            window.display();
        }
    return 0;
}

void update_1(Control_Panel& cp){
    /*if(States::is_State_Enable(CLOSE)){
        cout<< "Close"<<endl;
        States::disable_state(CLOSE);
    }else */if(States::is_State_Enable(OPEN)){
        new_window();
        States::disable_state(OPEN);
        if(States::is_State_Enable(OPEN_FILE)){
            //cout<<"Here"<<endl;
            //cp to open the file
            cp = Control_Panel();
            cp.open_file(States::get_current_file());
            States::disable_state(OPEN_FILE);
        }
    }else if(States::is_State_Enable(NEW)){
        cout<< "New"<<endl;
        cp = Control_Panel();
        States::disable_state(CLOSE);
        States::disable_state(NEW);
    }else if(States::is_State_Enable(SAVE)){
        cout<< "Save"<<endl;
        cp.output_file(States::get_current_file());
        States::disable_state(SAVE);
    }else if(States::is_State_Enable(UNDO)){
        cout<< "Undo"<<endl;
        if(!History::is_Empty_stack_2()){
            cp.applySnapshot(History::topHistory_2());
            //apply the top snapshot
            History::popHistory_2();   //pop the top snapshot, because has used
        }
        States::disable_state(UNDO);
    }else if(States::is_State_Enable(REDO)){
        cout<< "Redo"<<endl;
        cp = Control_Panel();
        States::disable_state(REDO);
    }else if(States::is_State_Enable(EXPORT)){
        cout<< "Export"<<endl;
        cp.output_file("../file"+to_string(file_name)+".txt");
        file_name++;
        cp = Control_Panel();
        States::disable_state(EXPORT);
    }
}

void new_window(){
    //----------S E T U P ------------------------------:

    //declare a window object:
    sf::RenderWindow window(sf::VideoMode(800, 500),
                                                       "File_Tree");

    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

    FileTree ft;

    while(window.isOpen())
        {
            sf::Event event;
            while(window.pollEvent(event))
            {
                if(event.type == sf::Event::Closed){
                    States::disable_state(OPEN);
                    window.close();
                }


                    ft.addEventHandler(window, event);

            }

            ft.update();


            window.clear();

            //draw=====================

            window.draw(ft);

            window.display();
        }
}
