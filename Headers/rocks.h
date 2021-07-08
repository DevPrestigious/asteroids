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
   
public:
   void draw();
   /*
   void positionUpdater(Point point, int rotation, Velocity shipVelocity)
   {
      // Sets passed variables from ship to the bullet object
      // Assists in knowing what direction to shoot bullet, where to shoot bullet from
      // and what velocity.
      this->rotation = rotation;
      this->point = point;
      this->bulletVelocity = shipVelocity;
   };
    */
};

class BigRock : public Rock
{
protected:
   int rotate;
public:
   void draw();
   void advance();
   
};

class MediumRock : public Rock
{
protected:
   
public:
   void draw();
   
};

class SmallRock : public Rock
{
protected:
   
public:
   void draw();
   
};

#endif /* rocks_h */
