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

/**************************************************************************
 * Ship:FlyingObject
 * Inherited from FlyingObject
 **************************************************************************/
class Ship : public FlyingObject
{
private:
   bool thrust;
public:
   // Default constructor
   Ship()
   {
      Point(0,0);
      isAlive();
      thrust = false;
      rotation = 0;
   }
   
   void setThrust(bool thrust) {this->thrust = thrust; }
   
   // More detail can be found in the .cpp file
   void applyThrustUp();
   void applyThrustDown();

   void advance();
   
   void draw() const;
   
};

#endif /* ship_h */
