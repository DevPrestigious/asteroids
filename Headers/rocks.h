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

class Rock : public FlyingObject
{
protected:
   int randomNum = random(-200,200);
   float collisionSize = 0;

public:
   bool isAlive() { return alive; }
   float getCollisionSize() { return collisionSize; }
   virtual void breakApart(std::vector<Rock*>& pRocks) {};
};

class BigRock : public Rock
{
protected:
   
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

class MediumRock : public Rock
{
protected:
   
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

class SmallRock : public Rock
{
protected:
   
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
