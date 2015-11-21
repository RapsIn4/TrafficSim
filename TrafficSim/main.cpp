#include <iostream>
#include "simulation.h"

int main(int argc, const char * argv[]) {
    Map map1, map2;
    Simulation simulation(&map1, &map2, 30000);
    simulation.init_simulation();
    simulation.start_simulation();
    return 0;
}
