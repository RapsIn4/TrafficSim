#include "simulation.h"

void Simulation::start_simulation() {
    while(time_passed < simulation_length) {
        for(Entity *e : entities) {
            e->update();
        }
        time_passed += INTERVAL_IN_MS;
    }
}