//
//  flyingObject.cpp
//  skeetSkeet
//
//  Created by Alexander Dohms on 6/14/21.
//
#include "game.h"
#include "flyingObject.h"
//#include <corecrt_math_defines.h>
#define BULLET_SPEED 10.0


void FlyingObject::advance()
{
   point.addX(BULLET_SPEED * (-cos(M_PI / 180.0 * angle)));
   point.addY(BULLET_SPEED * (sin(M_PI / 180.0 * angle)));
};
