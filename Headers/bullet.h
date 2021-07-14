#ifndef bullet_h
#define bullet_h

#define BULLET_SPEED 5
#define BULLET_LIFE 40
// Put your Bullet class here
#include "flyingObject.h"

#include <cmath> // used for sin, cos, and M_PI

class Bullet : public FlyingObject
{
protected:
   Velocity bulletVelocity;
   int frameCount = 0;
public:

   void draw();
   
   void fire(Point point, int rotation, Velocity shipVelocity);
   
   void bulletKiller();
   
   void advance();
   
};

#endif /* bullet_h */
