#include "rocks.h"

// Put your Rock methods here

void BigRock::draw()
{
   drawLargeAsteroid(Rock::getPoint(), rotate);
   rotate = rotate + 1;
}

void BigRock::advance()
{
   point.addX(6 * (-cos(M_PI / 180.0 * (randomNum))));
   point.addY(6 * (sin(M_PI / 180.0 * (randomNum))));
}

void MediumRock::draw()
{
   drawMediumAsteroid(Point(0,0), 5);
}

void SmallRock::draw()
{
   drawSmallAsteroid(Point(0,0), 10);
}
