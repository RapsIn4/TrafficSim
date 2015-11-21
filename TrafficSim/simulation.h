#ifndef simulation_h
#define simulation_h

#include <vector>

#include "entity.h"

class Simulation {
public:
    const int INTERVAL_IN_MS = 14;
    Simulation(Map *m1, Map *m2, float simulation_length) : map1(m1), map2(m2), simulation_length(simulation_length) {}
    
    void init_simulation();
    void start_simulation();
    
private:
    std::vector<Entity*> entities;
    
    Map *map1, *map2;
    float time_passed;
    float simulation_length;
};

#endif /* simulation_h */
