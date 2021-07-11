//
//  bullet.cpp
//  skeetSkeet
//
//  Created by Alexander Dohms on 6/14/21.
//

#include "bullet.h"


void Bullet::advance()
{
   // Counts +1 eachtime advanced is called
   frameCount++;
   // Once the object flies for 40 counts then it is killed.
   if (frameCount >= 40)
   {
      kill();
   }
   // Gives the bullet velocity, by giving it bullet speed, and adding ships velocity
   point.addX(bulletVelocity.getDx() + BULLET_SPEED * (-cos(M_PI / 180.0 * ((rotation) - 90))));
   point.addY(bulletVelocity.getDy() + BULLET_SPEED * (sin(M_PI / 180.0 * ((rotation) + 90))));
}

void Bullet::draw()
{
   drawDot(Bullet::getPoint());
}

void Bullet::fire(Point point, int rotation, Velocity shipVelocity)
{
   // Sets passed variables from ship to the bullet object
   // Assists in knowing what direction to shoot bullet, where to shoot bullet from
   // and what velocity.
   this->rotation = rotation;
   this->point = point;
   this->bulletVelocity = shipVelocity;
};
