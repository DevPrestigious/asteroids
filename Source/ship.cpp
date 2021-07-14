#include "ship.h"
#include "uiInteract.h"

/**************************************************************************
 * Ship :: applyThrustUp()
 * Applys velocity whenever called, in the correct direction, with the correct amount
 * by THRUST_AMOUNT.
 * The math behind this would look like point += point.
 * Essentially it's constantly increasing in "speed" by applying velocity.
 * DoEs tHaT mAkE sEnSe?
 **************************************************************************/
void Ship :: applyThrustUp()
{
   velocity.setDy(velocity.getDy() - (THRUST_AMOUNT * (-cos(M_PI / 180.0 * rotation))));
   velocity.setDx(velocity.getDx() - (THRUST_AMOUNT * (sin(M_PI / 180.0 * rotation))));
}

/**************************************************************************
 * Ship :: advance()
 * esentially has point continue to update it's position, but doesn't add.
 * the math behind this would look like point + point, it's just continue it's direction
 * without velocity. DoEs tHaT mAkE sEnSe?
 **************************************************************************/
void Ship :: advance()
{
   velocity.advancePoint(point);
}

/**************************************************************************
 * Ship::draw()
 * If ship is alive, then drawShip, with the point required, the rotation, and possibly with thrust
 * Thrust will get turned on or off in game.cpp with uiInteract.
 **************************************************************************/
void Ship::draw() const
{
   if (FlyingObject::isAlive())
   {
      drawShip(point, rotation, thrust);
   }
}

/**************************************************************************
 * FlyingObject::rotateLeft()
 * Rotates left. Pretty simple. rotateLeft gets called by game.cpp according to
 * uiInteract. If statement to make the rotation reset to 0, just because numbers
 * it's nice to have number based of a 360 rotation and not a 9000 rotation.
 **************************************************************************/
void FlyingObject :: rotateLeft()
{
   if (rotation == 360)
   {
      rotation = 0;
   }
   rotation += ROTATE_AMOUNT;
   
}

/**************************************************************************
 * FlyingObject::rotateRight()
 * Rotates left. Pretty simple. rotateRight gets called by game.cpp according to
 * uiInteract. If statement to make the rotation reset to 0, just because numbers
 * it's nice to have number based of a 360 rotation and not a 9000 rotation.
 **************************************************************************/
void FlyingObject :: rotateRight()
{
   if (rotation == -360)
   {
      rotation = 0;
   }
   rotation -= ROTATE_AMOUNT;
}
