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
    Vehicle();
    ~Vehicle();
    
    override void update();
    
    void setDirection(Direction direction);
    Direction getDirection() const;
    void setSpeed(float speed);
    float getSpeed() const;
    void setRecommendedAcceleration(float speed);
    float getRecommendedAcceleration() const;
    void setRecommendedDeceleration(float speed);
    float getRecommendedDeceleration() const;
    
    
private:
    VehicleType vehicle_type;
    float speed;
    Direction direction;
    float recommended_acceleration;
    float recommended_deceleration;
};

#endif /* vehicle_h */
