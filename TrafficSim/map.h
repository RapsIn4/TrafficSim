#ifndef map_h
#define map_h

#include <vector>
#include <string>

class Map {
public:
    class Road;
    class Intersection;
    
    std::vector<Road*> getRoadList() { return listRoads; }
    std::vector<Intersection*> getIntersection() { return listIntersection; }
    
private:
    std::vector<Road*> listRoads;
    std::vector<Intersection*> listIntersection;
};

class Map::Road {
public:
    class Lane;
    Road();
    Road(std::string &name, Intersection *first, Intersection *second) : street_name(name), start(first), end(second) {}
    ~Road();
    
private:
    std::string street_name;
    std::vector<Lane*> lanes;
    Intersection *start, *end;
};

class Map::Road::Lane {
private:
    std::tuple<float> start_point;
    std::tuple<float> end_point;
};

enum Trafficlight {
    RED,
    ORANGE,
    GREEN
};

class Map::Intersection {

    
private:
    Trafficlight light_ns;
    Trafficlight light_ew;
    
    /*
     * 0-3 are incoming Traffic from N, E, S, W
     * 4-7 are Outgoing Traffic to N, E, S, W
     */
    std::vector<Road*> roads;
};

#endif /* map_h */
