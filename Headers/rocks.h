#ifndef rocks_h
#define rocks_h

#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10

#include "flyingObject.h"

// Define the following classes here:
//   Rock
//   BigRock
//   MediumRock
//   SmallRock

/**************************************************************************
 * Rock::public FlyingObject
 * Inherits some functions from flyingObject, then it adds some functions
 * that are shared among the other rocks.
 **************************************************************************/
class Rock : public FlyingObject
{
protected:
   int randomNum = random(-20000,20000);
   float collisionSize = 0;

public:
   bool isAlive() { return alive; }
   float getCollisionSize() { return collisionSize; }
   // Passes the vector of pRocks and uses tht to add more
   // rocks to the vector.
   virtual void breakApart(std::vector<Rock*>& pRocks) {};
};

/**************************************************************************
 * BigRock: Rock
 * BigRock inherited from Rock
 **************************************************************************/
class BigRock : public Rock
{
public:
   BigRock()
   {
      point = Point(randomNum,randomNum);
      alive = true;
      collisionSize = BIG_ROCK_SIZE;
   }
   void draw();
   void advance();
   void breakApart(std::vector<Rock*>& pRocks);
};

/**************************************************************************
 * MediumRock:Rock
 * MediumRock inherited from Rock
 **************************************************************************/
class MediumRock : public Rock
{
public:
   MediumRock(Point point)
   {
      this->point = point;
      alive = true;
      collisionSize = MEDIUM_ROCK_SIZE;
   }
   
   void draw();
   void advance();
   void breakApart(std::vector<Rock*>& pRocks);
};

/**************************************************************************
 * SmallRock:Rock
 * SmallRock inherited from Rock
 **************************************************************************/
class SmallRock : public Rock
{
public:
   SmallRock(Point point)
   {
      this->point = point;
      alive = true;
      collisionSize = SMALL_ROCK_SIZE;
   }
   
   void draw();
   void advance();
};
#endif /* rocks_h */
