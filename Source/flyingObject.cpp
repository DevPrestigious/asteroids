//
//  flyingObject.cpp
//  skeetSkeet
//
//  Created by Alexander Dohms on 6/14/21.
//
#include "game.h"
#include "flyingObject.h"

//#include <corecrt_math_defines.h>


/**************************************************************************
 * FlyingObject::advance()
 * A default advance function. No function actually uses it
 * as each object using advance has it's own rules.
 **************************************************************************/
void FlyingObject::advance()
{
   velocity.setDy(velocity.getDy() - (THRUST_AMOUNT * (-cos(M_PI / 180.0 * rotation))));
   velocity.setDx(velocity.getDx() - (THRUST_AMOUNT * (sin(M_PI / 180.0 * rotation))));
};

/**************************************************************************
 * FlyingObject::handleBounds()
 * This is a fun funtion that makes it so if an object goes off screen, or
 * out of bounds, then it will push or set the object to the otherside of
 * the game.
 **************************************************************************/
void FlyingObject::handleBounds()
{
   if (point.getX() >= 200)
   {
      point.setX(-200);
   }
   else if (point.getX() <= -200)
   {
      point.setX(200);
   }
   if (point.getY() >= 200)
   {
      point.setY(-200);
   }
   else if (point.getY() <= -200)
   {
      point.setY(200);
   }
}
