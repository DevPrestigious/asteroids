#include "rocks.h"

// Put your Rock methods here

void BigRock::draw()
{
   drawLargeAsteroid(Rock::getPoint(), rotation);
   rotation += 1;
}

void BigRock::advance()
{
   point.addX(1 * (-cos(M_PI / 180.0 * (randomNum))));
   point.addY(1 * (sin(M_PI / 180.0 * (randomNum))));
}

void MediumRock::draw()
{
   drawMediumAsteroid(Rock::getPoint(), rotation);
   rotation += 5;
}

void MediumRock::advance()
{
   point.addX(1 * (-cos(M_PI / 180.0 * (randomNum))));
   point.addY(1 * (sin(M_PI / 180.0 * (randomNum))));
}


void SmallRock::draw()
{
   drawSmallAsteroid(Point(0,0), 10);
}
