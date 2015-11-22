#include "vehicle.h"
#include <algorithm>


void Vehicle::update(Map *input, Map *output) {
    // Update lits of cars
    
    updateVelocity();
    updatePosition();
    updateDirection();
}

void Vehicle::updateDirection() {
    Map::Road::Lane *lane = this->getLane();
    direction = lane->getDirection();
}

void Vehicle::updatePosition() {
    std::pair<float, float> direction = getDirection();
    
    // Update position based on direction
    position.first += direction.first;
    position.second += direction.second;
}

void Vehicle::updateVelocity() {
    // Calculate speed
    float first_x = position.first;
    float first_y = position.second;
    float second_x = position.first + direction.first;
    float second_y = position.second + direction.second;
    
    float diff_x = first_x - second_x;
    
    std::pair<float, float> velocity;
    velocity.first = 0;
    velocity.second = 0;
//    setVelocity((m_Direction * m_Velocity.norme()) + m_Acceleration * Simulation::m_PasSimulation);
//    if (qAbs(m_Velocity.angle(true) - m_Direction.angle(true)) >= 90.0f)
//        setVelocity(Point());
}

void Vehicle::updateAcceleration() {
    
}