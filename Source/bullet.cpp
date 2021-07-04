//
//  bullet.cpp
//  skeetSkeet
//
//  Created by Alexander Dohms on 6/14/21.
//

#include "bullet.h"


void Bullet::advance()
{
   point.addX(BULLET_SPEED * (-cos(M_PI / 180.0 * (rotation - 90))));
   point.addY(BULLET_SPEED * (sin(M_PI / 180.0 * (rotation + 90))));
}

void Bullet::draw()
{
   drawDot(Bullet::getPoint());
}

void Bullet::fire(Point point, int rotation)
{
   
   std::cout << "Bullet: " << rotation << std::endl;
   
   this->rotation = rotation;
   this->point = point;
};
