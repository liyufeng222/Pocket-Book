#ifndef GUICOMPONENT_H
#define GUICOMPONENT_H

#include "evenhandler.h"
#include "states.h"
#include "snapshotinterface.h"
#include <SFML/Graphics.hpp>
#include "constansts.h"

//#include "mouseevents.h"

class GUIComponent : public EvenHandler, public States, public SnapshotInterface, public sf::Drawable, public sf::Transformable{

public:
    //from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const = 0;

    // from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;

    //from SnapshotInterface
    virtual SnapShot& getSnapshot() = 0;
    virtual void applySnapshot(const SnapShot& snapshot) = 0;
};

#endif // GUICOMPONENT_H
