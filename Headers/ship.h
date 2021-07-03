#ifndef ship_h
#define ship_h

#define SHIP_SIZE 10

#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5

#include "velocity.h"
#include "point.h"

// Put your Ship class here
class Ship
{
private:
   Point point;
   Velocity velocity;
   bool alive;
   bool thrust;
   int rotation;
   
   
public:
   Ship() : point(0, 0), alive(true), rotation(180), thrust(false){}
   
   Point getPoint() const { return point; }
   Velocity getVelocity() const { return velocity; }
   float getRotation() const { return rotation; }
   
   bool isAlive() const { return alive; }
   bool isThrust() const { return thrust; }
   
   void setAlive(bool alive) { this->alive = alive; }
   
   void applyThrustUp();
   
   
   void rotateLeft();
   void rotateRight();
   int posRotation();

   void advance();
   
   void draw() const;
   
};

#endif /* ship_h */
