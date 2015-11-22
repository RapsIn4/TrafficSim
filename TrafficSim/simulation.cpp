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
//        
        Json::Value laneVec(Json::arrayValue);
        
        int start_x = 0, start_y = 100, end_x = 200, end_y = 100;
        
        Json::Value point;
        point["points"]["start_x"] = start_x;
        point["points"]["start_y"] = start_y;
        point["points"]["end_x"] = end_x;
        point["points"]["end_y"] = end_y;
        
        laneVec.append(point);
        std::cout << laneVec << std::endl;
        
//        
//        std::vector<Map::Road*> roads = map2->getRoads();
//        std::vector<Map::Intersection*> intersections = map2->getIntersections();
//        
//        Json::Value event;
//        Json::Value roadVec(Json::arrayValue);
//        
//        for(Map::Road *r : roads) {
//            std::vector<Map::Road::Lane*> lanes = r->getLanes();
//            
//            Json::Value laneVec(Json::arrayValue);
//            event["roads"]["lanes"] = laneVec;
//            
//            for(Map::Road::Lane *l : lanes) {
//                
//                int start_x, start_y, end_x, end_y;
        Map::Road::Lane *l;
        std::pair<float,float> startPt = l->get_starting_pt();
        std::pair<float,float> endPt = l->get_end_pt();
        
        start_x = startPt.first;
        start_y = startPt.second;
        end_x = endPt.first;
        end_y = endPt.second;
        
        
//                Json::Value point;
//                point["points"]["start_x"] = start_x;
//                point["points"]["start_y"] = start_y;
//                point["points"]["end_x"] = end_x;
//                point["points"]["end_y"] = end_y;
//
//                laneVec.append(point);
//            }
//        }
//        
//        
//        event["intersections"] = "";
        
    
        time_passed += INTERVAL_IN_MS;
    }
}