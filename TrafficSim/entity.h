#ifndef entity_h
#define entity_h

#include "map.h"

class Entity {
public:
    virtual void update(Map *input, Map *output) = 0;
    virtual ~Entity() {}
    std::pair<float, float> getPosition() { return position; }
    
protected:
    std::pair<float, float> position;
};

#endif /* entity_h */
