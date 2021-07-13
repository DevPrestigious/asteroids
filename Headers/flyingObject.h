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
#include "uiInteract.h"
#include "corecrt_math_defines.h"
#include "vector"

class FlyingObject
{

protected:
   
   Point point;
   Velocity velocity;

   bool alive;
   float angle;
   int rotation;

public:
   
   FlyingObject() { alive = true; }
   virtual ~FlyingObject() { }

   Point getPoint() const { return point; }
   void setPoint(Point point) { this->point = point;}
   float getRotation() const { return rotation; }
   
   Velocity getVelocity() const { return velocity; }

   void setAlive(bool alive) { this->alive = alive; }
   virtual bool isAlive() const { return alive; }

   void setVelocity(const Velocity & velocity) { this->velocity = velocity ;}
   void kill() { alive = false;}
   void handleBounds();
   
   virtual void advance();
   virtual void draw(){};
   void rotateLeft();
   void rotateRight();
   
};

#endif
