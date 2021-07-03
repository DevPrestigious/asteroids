//
//  flyingObject.h
//  flyingObject
//
//  Created by Alexander Dohms on 6/14/21.
//

#ifndef FLYING_OBJECT_H
#define FLYING_OBJECT_H

#include "point.h"
#include "velocity.h"
#include "uiDraw.h"

class FlyingObject
{
protected:
   Point point;
   Velocity velocity;
   bool alive;
   float angle;
   //int startY = random(-200,200);
public:
   
   
   
   FlyingObject() { alive = true; }
   virtual ~FlyingObject() { }

   Point getPoint() const { return point; }
   
   Velocity getVelocity() const { return velocity; }

   void setAlive(bool alive) { this->alive = alive; }
   virtual bool isAlive() const { return alive; }
   
   void setPoint(const Point & point) { this->point = point; }
   void setVelocity(const Velocity & velocity) { this->velocity = velocity ;}
   void kill() { alive = false;}
   
   virtual void advance();
   virtual void draw() = 0;
   /*
   //Function for other birds virtical velocity
   int velY(int startY)
   {
      // If startY is not negative, then descend, otherwise rise
       if (this->startY * -1 > 0)
           return startY = random(0, 5);
       else
           return startY = random(-4, 1);
   }
   //Function for toughbirds vertical velocity
   int tVelY(int startY)
   {
      // If startY is not negative, then ascend, otherwise descend
       if (this->startY * -1 > 0)
           return startY = random(0, 4);
       else
           return startY = random(-3, 1);
   }
   */
   
};

#endif
