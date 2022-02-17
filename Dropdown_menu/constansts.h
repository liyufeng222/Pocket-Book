#ifndef CONSTANSTS_H
#define CONSTANSTS_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

// /*
const sf::Vector2f TEXT_BOX_BOUND = sf::Vector2f{200,50};
const sf::Vector2f TEXT_BOX_POS = sf::Vector2f{200,175};
const int CHARACTERS_SIZE = 30;

const float SPACE = 35;

const float Y_SPACE = 30;

//static float BOTTOM = 0;

// */

 /*
const sf::Vector2f TEXT_BOX_BOUND = sf::Vector2f{500,80};
const sf::Vector2f TEXT_BOX_POS = sf::Vector2f{50,100};
const int CHARACTERS_SIZE = 25;

 */

const sf::Vector2f DEFAULT_SIZE = sf::Vector2f{150, 30};

const sf::Vector2f TEXT_LABLE_POS = sf::Vector2f{50,200};


//const sf::Vector2f TEXT_HEAD_POS = sf::Vector2f{630,200};

const float LETTER_SPACEING = 2;

const int SCREEN_WIDTH = 1800;
const int SCREEN_HEIGHT = 1200;


const std::vector<std::string> KEY_WORD = {"int", "char", "double", "float", "for", "while", "if", "else"};

//const std::vector<std::string> ITEMS = {"int", "char", "double", "float"};
const std::vector<std::string> ITEMS = {"Income", "Cost"};


//Menus bar items
const std::vector<std::string> FILE_ITEMS = {"Close", "New", "Open", "Save"};
const std::vector<std::string> EDIT_ITEMS = {"Undo", "Redo"};
const std::vector<std::string> RENDER_ITEMS = {"Export"};

//text_box_item_name
const sf::Vector2f TEXT_BOX_1_BOUND = sf::Vector2f{700,90};
const sf::Vector2f TEXT_BOX_1_POS = sf::Vector2f{80,950};
const int CHARACTERS_SIZE_1 = 50;

//text_box_amount
const sf::Vector2f TEXT_BOX_2_BOUND = sf::Vector2f{500,90};
const sf::Vector2f TEXT_BOX_2_POS = sf::Vector2f{280,1075};

//type_box
const sf::Vector2f TEXT_BOX_3_BOUND = sf::Vector2f{350,80};
const sf::Vector2f TEXT_BOX_3_POS = sf::Vector2f{1050,950};
const int CHARACTERS_SIZE_2 = 35;

#endif // CONSTANSTS_H
