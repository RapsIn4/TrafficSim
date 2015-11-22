#ifndef map_h
#define map_h

#include <vector>
#include <string>

class Vehicle;

#define LANE_WIDTH 3 // 3 meters
class Map {
public:
    class Road;
    class Intersection;
    
    void init();
    void rm();
    
    void addRoad(Road *road) { listRoads.push_back(road); }
    std::vector<Road*> getRoads() { return listRoads; }
    void addIntersection(Intersection *intersection) { listIntersections.push_back(intersection); }
    std::vector<Intersection*> getIntersections() { return listIntersections; }
    
private:
    std::vector<Road*> listRoads;
    std::vector<Intersection*> listIntersections;
};

class Map::Road {
public:
    class Lane;
    Road(std::string name, size_t num_lanes, Intersection *first, Intersection *second);
    ~Road();
    std::pair<float, float> getDirection() { return direction; }
    void setDirection(std::pair<float, float> direction) { this->direction = direction; }
    std::vector<Lane*> getLanes() { return lanes; }
    std::string getStreetName() { return street_name; }
    size_t getNumLanes() { return num_lanes; }

private:
    std::string street_name;
    std::vector<Lane*> lanes;
    std::pair<float, float> direction;
    Intersection *start, *end;
    size_t num_lanes;
};

class Map::Road::Lane {
public:
    Lane(float start_x, float start_y, float end_x, float end_y);
    std::pair<float, float> getStartingPt() { return start_point; }
    std::pair<float, float> getEndPt() { return end_point; }
    std::vector<Vehicle*> getVehicles() { return vehicles; }
    std::pair<float, float> getDirection() { return direction; }
    void setDirection(std::pair<float, float> direction) { this->direction = direction; }
private:
    std::pair<float, float> start_point;
    std::pair<float, float> end_point;
    std::vector<Vehicle*> vehicles;
    std::pair<float, float> direction;

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
