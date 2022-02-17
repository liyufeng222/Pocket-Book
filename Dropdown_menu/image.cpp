#include "image.h"

std::map<Image::image, sf::Texture> Image::images;
std::map<Image::image, bool> Image::loaded;


sf::Texture& Image::getImage(image image){
    if(!loaded[image])
        loadImage(image);
    return images[image];
}
void Image::loadImage(image image){
    if(!loaded[image]){
        if(!images[image].loadFromFile("images/"+getImagePath(image)))
            exit(1);
        loaded[image] = true;
    }
}
std::string Image::getImagePath(image image){
    switch (image) {
    case FOLDER:
        return "folder.png";
    case FILE:
        return "file.png";
    }
}
