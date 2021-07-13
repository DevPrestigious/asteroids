#include "rocks.h"

// Put your Rock methods here

void BigRock::draw()
{
   drawLargeAsteroid(Rock::getPoint(), rotation);
   rotation += BIG_ROCK_SPIN;
}

void BigRock::advance()
{
   point.addX(1 * (-cos(M_PI / 180.0 * (randomNum))));
   point.addY(1 * (sin(M_PI / 180.0 * (randomNum))));
}

void BigRock::breakApart(std::vector<Rock*>& pRocks)
{
   pRocks.push_back(new MediumRock());
   pRocks.push_back(new MediumRock());
}

void MediumRock::draw()
{
   drawMediumAsteroid(Rock::getPoint(), rotation);
   rotation += MEDIUM_ROCK_SPIN;
}

void MediumRock::advance()
{
   point.addX(1 * (-cos(M_PI / 180.0 * (randomNum))));
   point.addY(1 * (sin(M_PI / 180.0 * (randomNum))));
}

void MediumRock::breakApart(std::vector<Rock*>& pRocks)
{
   pRocks.push_back(new SmallRock());
   pRocks.push_back(new SmallRock());
}

void SmallRock::draw()
{
   drawSmallAsteroid(Rock::getPoint(), rotation);
   rotation += SMALL_ROCK_SPIN;
}

void SmallRock::advance()
{
   point.addX(1 * (-cos(M_PI / 180.0 * (randomNum))));
   point.addY(1 * (sin(M_PI / 180.0 * (randomNum))));
}

