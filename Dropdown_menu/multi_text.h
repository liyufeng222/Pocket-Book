#ifndef MULTI_TEXT_H
#define MULTI_TEXT_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "guicomponent.h"
#include "constansts.h"
#include <sstream>
#include "font.h"

using namespace std;

class Multi_Text : public GUIComponent
{
public:
    Multi_Text();

    Multi_Text(sf::Vector2f box_pos, sf::Vector2f box_bound);

    //from the sf::Drawable class
    //draw all the onbject in Multi_Text (class multi_text draw)
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    // from EventHandler
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();

    //from SnapshotInterface
    SnapShot& getSnapshot();
    void applySnapshot(const SnapShot& snapshot);

    //===================================================
    void set_String(string s);

    sf::FloatRect getLast_Text_Bounds();

    string get_Value() const;


private:
    Font f;
    string myString;
    vector<sf::Text> texts;

    sf::Vector2f TEXT_HEAD_POS; //= sf::Vector2f{TEXT_BOX_1_POS.x+30,TEXT_BOX_1_POS.y + TEXT_BOX_1_BOUND.y/2 - CHARACTERS_SIZE_1/2};

    float new_line_y = TEXT_HEAD_POS.y;

    //change the string to texts vector  (A big version)
    vector<sf::Text> stringToTexts(string s);

    //change the string to string vector
    //(helper function for stringToTexts(string s))
    vector<string> stringTokener(string s);
    //change the string vector to text vector
    //(helper function for stringToTexts(string s))
    vector<sf::Text> tokenerToTexts(vector<string> token);

    //the total width for all texts (x direction)
    void set_Texts_position();

    bool isKeyWord(string s);
};

#endif // MULTI_TEXT_H
