#include "map.h"

Map::Road::Road(std::string name, size_t num_lanes, Intersection *first, Intersection *second) : street_name(name), start(first), end(second), num_lanes(num_lanes) {
    
    Lane *l = new Lane(100, 100, 1000, 100);
    lanes.push_back(l);
}

Map::Road::~Road() {
    for(Lane *l : lanes) {
        delete l;
    }
}

void Map::init() {
    Map::Intersection i1, i2;
    Map::Road road("Main St", 1, &i1, &i2);
    addRoad(&road);
}

Map::Road::Lane::Lane(float start_x, float start_y, float end_x, float end_y) {
    start_point = std::make_pair(start_x, start_y);
    end_point = std::make_pair(end_x, end_y);
}