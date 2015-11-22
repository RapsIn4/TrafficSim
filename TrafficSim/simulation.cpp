#include <iostream>

#include "simulation.h"
#include "map.h"
#include "vehicle.h"
#include "json/json.h"
#include <iostream>

void Simulation::init_simulation() {
    map1->init();
    map2->init();
    entities.push_back(new Vehicle());
}

void parseRoads() {
    
}

void parseIntersections() {
    
}

void Simulation::start_simulation() {
    while(time_passed < simulation_length) {
        for(Entity *e : entities) {
            e->update(map1, map2);
        }
        
//        for(Entity *e : entities) {
//            std::cout << '(' << e->getPosition().first << ", " << e->getPosition().second << ')' << std::endl;
//        }
      
        
        std::vector<Map::Road*> roads = map2->getRoads();
        std::vector<Map::Intersection*> intersections = map2->getIntersections();
        
        Json::Value json_roads;
        Json::Value json_road_vec(Json::arrayValue);
        
        for(Map::Road *r : roads) {
            std::vector<Map::Road::Lane*> lanes = r->getLanes();
            
            Json::Value json_lane, json_road;
            Json::Value json_lane_vec(Json::arrayValue);
            
            for(Map::Road::Lane *l : lanes) {
                // Add points from lane
                int start_x, start_y, end_x, end_y;
                
                std::pair<float,float> startPt = l->get_starting_pt();
                std::pair<float,float> endPt = l->get_end_pt();
                
                start_x = startPt.first;
                start_y = startPt.second;
                end_x = endPt.first;
                end_y = endPt.second;
                
                // Serialize points here
                Json::Value json_point;
                
                json_point["start_point"]["x"] = start_x;
                json_point["start_point"]["y"] = start_y;
                json_point["end_point"]["x"] = end_x;
                json_point["end_point"]["y"] = end_y;
                
                json_lane["lane"] = json_point;
                json_lane_vec.append(json_lane);
            }
            
            json_road["road"] = json_lane_vec;
            json_road_vec.append(json_road);
        }
        
        json_roads["roads"] = json_road_vec;
        
        std::cout << json_roads << std::endl;

        time_passed += INTERVAL_IN_MS;
    }
}