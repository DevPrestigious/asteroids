#include "ship.h"
// Put your ship methods here

void Ship :: applyThrustUp()
{
   velocity.setDy(velocity.getDy() - (THRUST_AMOUNT * (-cos(M_PI / 180.0 * rotation))));
   velocity.setDx(velocity.getDx() - (THRUST_AMOUNT * (sin(M_PI / 180.0 * rotation))));
}


void Ship :: advance()
{
   
   if (point.getX() >= 200)
   {
      point.setX(-200);
   }
   else if (point.getX() <= -200)
   {
      point.setX(200);
   }
   else if (point.getY() >= 200)
   {
      point.setY(-200);
   }
   else if (point.getY() <= -200)
   {
      point.setY(200);
   }
    
   velocity.advancePoint(point);
}

void Ship::draw() const
{
   if (FlyingObject::isAlive())
   {
      drawShip(point, rotation, thrust);
   }
}

void FlyingObject :: rotateLeft()
{
   if (rotation == 360)
   {
      rotation = 0;
   }
   rotation += ROTATE_AMOUNT;
   
}

void FlyingObject :: rotateRight()
{
   if (rotation == -360)
   {
      rotation = 0;
   }
   rotation -= ROTATE_AMOUNT;
}
