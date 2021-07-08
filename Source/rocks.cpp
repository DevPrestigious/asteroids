#include "rocks.h"

// Put your Rock methods here

void BigRock::draw()
{
   drawLargeAsteroid(Rock::getPoint(), rotate);
   rotate = rotate + 1;
}

void BigRock::advance()
{
   velocity.setDy(.0001);
   velocity.setDx(.0001);
   velocity.advancePoint(point);
   std::cout << point << std::endl;
}

void MediumRock::draw()
{
   drawMediumAsteroid(Point(0,0), 5);
}

void SmallRock::draw()
{
   drawSmallAsteroid(Point(0,0), 10);
}
