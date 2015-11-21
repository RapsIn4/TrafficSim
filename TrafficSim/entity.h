
#ifndef entity_h
#define entity_h

#include "map.h"

class Entity {
public:
    virtual void update(Map *input, Map *output) = 0;
};

#endif /* entity_h */
