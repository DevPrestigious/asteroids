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
   int frameCount;
public:
  // Bullet()
  // {
    //  point = Point(200,-200);
      //velocity = Velocity();
      //isAlive();
      //rotation = 0;
   //}
   //finish draw functions using uiRectangle and circle., and advance.
   void draw();
   
   void fire(Point point, int rotation, Velocity shipVelocity);

   void advance();
   
   
};

#endif /* bullet_h */
