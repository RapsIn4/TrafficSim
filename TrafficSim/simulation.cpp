#include "simulation.h"
#include "map.h"

void Simulation::init_simulation() {
    map1->init();
    map2->init();
}

void Simulation::start_simulation() {
    while(time_passed < simulation_length) {
        for(Entity *e : entities) {
            e->update(map1, map2);
        }
        time_passed += INTERVAL_IN_MS;
    }
}