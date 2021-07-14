//
//  bullet.cpp
//  asteroids
//
//  Created by Alexander Dohms on 6/14/21.
//

#include "bullet.h"

/**************************************************************************
 * Bullet::advance()
 * Calls bullet killer which you can read about below,
 * then advances the bullet according to the bulletVelocity, and rotation,
 * all set by the fire() function below.
 **************************************************************************/
void Bullet::advance()
{
   bulletKiller();
   // Gives the bullet velocity, by giving it bullet speed, and adding ships velocity
   point.addX(bulletVelocity.getDx() + BULLET_SPEED * (-cos(M_PI / 180.0 * ((rotation) - 90))));
   point.addY(bulletVelocity.getDy() + BULLET_SPEED * (sin(M_PI / 180.0 * ((rotation) + 90))));
}

/**************************************************************************
 * Bullet::bulletKiller()
 * Kills the bullet if it has reached a frame count of 40.
 **************************************************************************/
void Bullet::bulletKiller()
{
// Counts +1 eachtime advanced is called
frameCount++;
// Once the object flies for 40 counts then it is killed.
if (frameCount >= 40)
{
   kill();
}
};

/**************************************************************************
 * Bullet::draw()
 * Draws the bullet with the getPoint, which is set first by fire, which
 * you can read about below
 **************************************************************************/
void Bullet::draw()
{
   drawDot(Bullet::getPoint());
}

/**************************************************************************
 * Bullett::fire()
 * Even though this is called fire, it really is a glorified setter function.
 **************************************************************************/
void Bullet::fire(Point point, int rotation, Velocity shipVelocity)
{
   // Sets passed variables from ship to the bullet object
   // Assists in knowing what direction to shoot bullet, where to shoot bullet from
   // and what velocity.
   this->rotation = rotation;
   this->point = point;
   this->bulletVelocity = shipVelocity;
};
