#include "ship.h"
#include "uiInteract.h"
// Put your ship methods here

void Ship :: applyThrustUp()
{
   FlyingObject::advance();
}


void Ship :: advance()
{
   // Lets ship "scroll" on the screen
   handleBounds();
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
