#include "ship.h"
#include "uiInteract.h"
// Put your ship methods here

void Ship :: applyThrustUp()
{
   velocity.setDy(velocity.getDy() - (THRUST_AMOUNT * (-cos(M_PI / 180.0 * rotation))));
   velocity.setDx(velocity.getDx() - (THRUST_AMOUNT * (sin(M_PI / 180.0 * rotation))));
   //std::cout << "Dx: " << velocity.getDx() << " "
   ///< "Dy: " << velocity.getDy() << std::endl;
}


void Ship :: advance()
{
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
