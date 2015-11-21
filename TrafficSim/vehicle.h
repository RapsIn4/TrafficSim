#ifndef vehicle_h
#define vehicle_h

#include "entity.h"

enum VehicleType {
    SMALL,
    MEDIUM,
    LARGE,
    XLARGE
};

struct Direction {
    float x, y;
};

class Vehicle : public Entity {
public:
    void update(Map *input, Map *output);
    
    void setDirection(Direction direction) { this->direction = direction; }
    Direction getDirection() const { return direction; }
    void setSpeed(float speed) { this->speed = speed; }
    float getSpeed() const { return speed; }
    void setRecommendedAcceleration(float accel) { this->recommended_acceleration = accel; }
    float getRecommendedAcceleration() const { return recommended_acceleration; }
    void setRecommendedDeceleration(float decel) { this->recommended_deceleration = decel; }
    float getRecommendedDeceleration() const { return recommended_deceleration; }
    
private:
    VehicleType vehicle_type;
    float speed;
    Direction direction;
    float recommended_acceleration;
    float recommended_deceleration;
};

#endif /* vehicle_h */
