#include "vehicle.h"
#include <algorithm>


void Vehicle::update(Map *input, Map *output) {
    if(speed < DESIRED_SPEED) speed += recommended_acceleration;
    position.first += speed;
}