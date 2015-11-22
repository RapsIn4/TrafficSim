#include <iostream>

#include "simulation.h"
#include "map.h"
#include "vehicle.h"

void Simulation::init_simulation() {
    map1->init();
    map2->init();
    entities.push_back(new Vehicle());
}

void Simulation::start_simulation() {
    while(time_passed < simulation_length) {
        for(Entity *e : entities) {
            e->update(map1, map2);
        }
        for(Entity *e : entities) {
            std::cout << '(' << e->getPosition().first << ", " << e->getPosition().second << ')' << std::endl;
        }
        time_passed += INTERVAL_IN_MS;
    }
}