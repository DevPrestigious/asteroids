#include "rocks.h"

/**************************************************************************
 * BigRock::draw()
 * Draws the asteroid and updates rotation according to the rock's
 * global variable
 **************************************************************************/
void BigRock::draw()
{
   drawLargeAsteroid(getPoint(), rotation);
   rotation += BIG_ROCK_SPIN;
}

/**************************************************************************
 * BigRock::advance()
 * Advances the rock in a random direction.
 * The math looks like point + point.
 **************************************************************************/
void BigRock::advance()
{
   point.addX(1 * (-cos(M_PI / 180.0 * (randomNum))));
   point.addY(1 * (sin(M_PI / 180.0 * (randomNum))));
}

/**************************************************************************
 * BigRock::breakApart()
 * "Breaks" the rock apart by creating two new rocks on the vector
 * in it's place at point. Sets point in the rocks constructor.
 **************************************************************************/
void BigRock::breakApart(std::vector<Rock*>& pRocks)
{
   pRocks.push_back(new MediumRock(getPoint()));
   pRocks.push_back(new MediumRock(getPoint()));
}

/**************************************************************************
 * MediumRock::draw()
 * Draws the asteroid and updates rotation according to the rock's
 * global variable.
 **************************************************************************/
void MediumRock::draw()
{
   drawMediumAsteroid(getPoint(), rotation);
   rotation += MEDIUM_ROCK_SPIN;
}

/**************************************************************************
 * MediumRock::advance()
 * Advances the rock in a random direction.
 * The math looks like point + point.
 **************************************************************************/
void MediumRock::advance()
{
   point.addX(1 * (-cos(M_PI / 180.0 * (randomNum))));
   point.addY(1 * (sin(M_PI / 180.0 * (randomNum))));
}

/**************************************************************************
 * MediumRock::breakApart()
 * "Breaks" the rock apart by creating two new rocks on the vector
 * in it's place at point. Sets point in the rocks constructor.
 **************************************************************************/
void MediumRock::breakApart(std::vector<Rock*>& pRocks)
{
   pRocks.push_back(new SmallRock(getPoint()));
   pRocks.push_back(new SmallRock(getPoint()));
}

/**************************************************************************
 * SmallRock::draw()
 * Draws the asteroid and updates rotation according to the rock's
 * global variable
 **************************************************************************/
void SmallRock::draw()
{
   drawSmallAsteroid(getPoint(), rotation);
   rotation += SMALL_ROCK_SPIN;
}

/**************************************************************************
 * SmallRock::advance()
 * Advances the rock in a random direction.
 * The math looks like point + point.
 **************************************************************************/
void SmallRock::advance()
{
   point.addX(1 * (-cos(M_PI / 180.0 * (randomNum))));
   point.addY(1 * (sin(M_PI / 180.0 * (randomNum))));
}
