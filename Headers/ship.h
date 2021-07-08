#ifndef ship_h
#define ship_h

#define SHIP_SIZE 10

#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5


#include "velocity.h"
#include "point.h"
#include "uiDraw.h"

#include "flyingObject.h"
// Put your Ship class here

class Ship : public FlyingObject
{
   
private:
   bool thrust;
   
public:
   Ship()
   {
      Point(0,0);
      isAlive();
      thrust = false;
      rotation = 0;
   }
   
   Point getPoint() const { return point; }
   Velocity getVelocity() const { return velocity; }
   Point getPointX() { return point.getX(); }
   
   bool isAlive()
   {
      return FlyingObject::isAlive();
   };
   
   void setThrust(bool thrust) {this->thrust = thrust; }
   bool isThrust() const { return thrust; }
   
   void setAlive(bool alive) { this->alive = alive; }
   
   void applyThrustUp();
   
   int posRotation();

   void advance();
   
   void draw() const;
   
};

#endif /* ship_h */
