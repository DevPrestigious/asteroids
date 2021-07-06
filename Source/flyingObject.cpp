//
//  flyingObject.cpp
//  skeetSkeet
//
//  Created by Alexander Dohms on 6/14/21.
//
#include "game.h"
#include "flyingObject.h"

//#include <corecrt_math_defines.h>


void FlyingObject::advance()
{
   velocity.setDy(velocity.getDy() - (THRUST_AMOUNT * (-cos(M_PI / 180.0 * rotation))));
   velocity.setDx(velocity.getDx() - (THRUST_AMOUNT * (sin(M_PI / 180.0 * rotation))));
};

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
