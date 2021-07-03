#include "ship.h"
#include "uiDraw.h"
// Put your ship methods here

void Ship :: applyThrustUp()
{
   std::cout << getPoint() << std::endl;
   //std::cout << velocity.getDy() << std::endl;
   //velocity.setDy(velocity.getDy() + .5 );
     
   if (rotation > -90 && rotation <= 0)
   {
      velocity.setDy(velocity.getDy() - (.05 * (-cos(M_PI / 180.0 * rotation))));
      velocity.setDx(velocity.getDx() - (.05 * (sin(M_PI / 180.0 * rotation))));
   }
   else if ((rotation >= -180 && rotation <= -90) || rotation == 180)
   {
      velocity.setDy(velocity.getDy() - (.05 * (-cos(M_PI / 180.0 * rotation))));
      velocity.setDx(velocity.getDx() - (.05 * (sin(M_PI / 180.0 * rotation))));
   }
   else if ((rotation < 180 && rotation >= 90) || rotation == 180)
   {
      velocity.setDy(velocity.getDy() - (.05 * (-cos(M_PI / 180.0 * rotation))));
      velocity.setDx(velocity.getDx() - (.05 * (sin(M_PI / 180.0 * rotation))));
   }
   else if (rotation < 90 && rotation > 0)
   {
      velocity.setDy(velocity.getDy() - (.05 * (-cos(M_PI / 180.0 * rotation))));
      velocity.setDx(velocity.getDx() - (.05 * (sin(M_PI / 180.0 * rotation))));
   }
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
   if (isAlive())
   {
      drawShip(point, rotation, thrust);
   }
}

void Ship :: rotateLeft()
{
   if (rotation > 181)
   {
      rotation = rotation * -1;
   }
   std::cout << rotation << std::endl;
   rotation += ROTATE_AMOUNT;
   
}

void Ship :: rotateRight()
{
   std::cout << rotation << std::endl;
   if (rotation < -179) {
      rotation = rotation * -1;
   }
   rotation -= ROTATE_AMOUNT;
}
