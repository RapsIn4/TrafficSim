#ifndef simulation_h
#define simulation_h

#include <vector>

#include "entity.h"

class Simulation {
public:
    const int INTERVAL_IN_MS = 14;
    Simulation(float simulation_length) : simulation_length(simulation_length) {}
    
    void start_simulation();
    
private:
    std::vector<Entity*> entities;
    
    float time_passed;
    float simulation_length;
};

#endif /* simulation_h */
