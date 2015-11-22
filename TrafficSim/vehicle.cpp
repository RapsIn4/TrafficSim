#include "vehicle.h"
#include <algorithm>


void Vehicle::update(Map *input, Map *output) {
    // Update lits of cars
    
    updatePosition();
}

void Vehicle::updatePosition() {
    std::pair<float, float> direction = getDirection();
    
    // Update position based on direction
    position.first += direction.first;
    position.second += direction.second;
}