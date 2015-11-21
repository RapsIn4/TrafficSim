#ifndef simulation_h
#define simulation_h

class Simulation {
public:
    Simulation();
    Simulation(float simulation_length) : simulation_length(simulation_length) {}
    ~Simulation();
    
    void start_simulation();
    
private:
    float time_passed;
    float simulation_length;
};

#endif /* simulation_h */
