#ifndef IMAGE_H
#define IMAGE_H

#include <map>
#include <SFML/Graphics.hpp>
#include <string>

class Image
{
public:
    enum image{FOLDER, FILE};
    static std::map<image, sf::Texture> images;
    static std::map<image, bool> loaded;
    static sf::Texture& getImage(image image);
    static void loadImage(image image);
    static std::string getImagePath(image image);
};

#endif // IMAGE_H
