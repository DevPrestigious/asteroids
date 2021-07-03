/*********************************************************************
 * File: game.cpp
 * Description: Contains the implementaiton of the game class
 *  methods.
 *
 *********************************************************************/

#include "game.h"

// These are needed for the getClosestDistance function...
#include <limits>
#include <algorithm>
using namespace std;


// You may find this function helpful...

/**********************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **********************************************************/
/*
float Game :: getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const
{
   // find the maximum distance traveled
   float dMax = max(abs(obj1.getVelocity().getDx()), abs(obj1.getVelocity().getDy()));
   dMax = max(dMax, abs(obj2.getVelocity().getDx()));
   dMax = max(dMax, abs(obj2.getVelocity().getDy()));
   dMax = max(dMax, 0.1f); // when dx and dy are 0.0. Go through the loop once.
   
   float distMin = std::numeric_limits<float>::max();
   for (float i = 0.0; i <= dMax; i++)
   {
      Point point1(obj1.getPoint().getX() + (obj1.getVelocity().getDx() * i / dMax),
                     obj1.getPoint().getY() + (obj1.getVelocity().getDy() * i / dMax));
      Point point2(obj2.getPoint().getX() + (obj2.getVelocity().getDx() * i / dMax),
                     obj2.getPoint().getY() + (obj2.getVelocity().getDy() * i / dMax));
      
      float xDiff = point1.getX() - point2.getX();
      float yDiff = point1.getY() - point2.getY();
      
      float distSquared = (xDiff * xDiff) +(yDiff * yDiff);
      
      distMin = min(distMin, distSquared);
   }
   
   return sqrt(distMin);
}
*/


/*************************************************************
 * File: game.cpp
 * Author: Alexander Dohms
 *
 * Description: Contains the implementations of the
 *  method bodies for the game class.
 *
 * Please DO NOT share this code with other students from
 *  other sections or other semesters. They may not receive
 *  the same code that you are receiving.
 *************************************************************/

#include "game.h"
#include "ship.h"

using namespace std;

#define OFF_SCREEN_BORDER_AMOUNT 5


/***************************************
 * GAME CONSTRUCTOR
 ***************************************/
Game :: Game(Point tl, Point br)
 : topLeft(tl), bottomRight(br)
{
   // Set up the initial conditions of the game
   // TODO: Set your bird pointer to a good initial value (e.g., NULL)
   //bird = NULL;
}

/****************************************
 * GAME DESTRUCTOR
 ****************************************/
Game :: ~Game()
{
   // TODO: Check to see if there is currently any rocks or bullets? allocated
   //       and if so, delete it.
}

/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game :: advance()
{
   advanceBullets();
   advanceShip();

   handleCollisions();
   cleanUpZombies();
}

/***************************************
 * GAME :: ADVANCE BULLETS
 * Go through each bullet and advance it.
 ***************************************/
void Game :: advanceBullets()
{
   // Move each of the bullets forward if it is alive
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i].isAlive())
      {
         // this bullet is alive, so tell it to move forward
         bullets[i].advance();
         
         if (!isOnScreen(bullets[i].getPoint()))
         {
            // the bullet has left the screen
            bullets[i].kill();
         }
         
      }
   }
}


/**************************************************************************
 * GAME :: ADVANCE BIRD
 *
 * 1. If there is no bird, create one with some probability
 * 2. If there is a bird, and it's alive, advance it
 * 3. Check if the bird has gone of the screen, and if so, "kill" it
 **************************************************************************/
void Game :: advanceShip()
{
   {
      // we have a ship, make sure it's alive
      //if (ship.isAlive())
      {
         ship.advance();
         // move it forward
         //bird->advance();
         // check if the bird has gone off the screen
         //if (!isOnScreen(bird->getPoint()))
         {
            // We have missed the bird
           // bird->kill();
         }
      }
   }
   
}

/**************************************************************************
 * GAME :: CREATE BIRD
 * Create a bird of a random type according to the rules of the game.
 **************************************************************************/
/*
Bird* Game :: createBird()
{
   Create bird is special here because it will only create a
   total of 10 Tough or Angry birds, making the highscore more
   challenging, and also to make the game not feel like an endless
   loop
   // TODO: Fill this in
   
   int randomNum = random(1, 4);
   Bird* newBird = NULL;
   switch (randomNum)
   {
      case 1:
         newBird = new Bird();
         if (birdAmount < 1) {
            return 0;
         }
         --birdAmount;
         return newBird;
      case 2:
         newBird = new ToughBird();
         if (birdAmount < 1) {
            return 0;
         }
         --birdAmount;
         return newBird;
      case 3:
         newBird = new SacredBird();
         if (birdAmount < 1) {
            return 0;
         }
         //Sacred bird does not affect birdAmount
         return newBird;
      
   }
   return 0;
}
*/
/**************************************************************************
 * GAME :: IS ON SCREEN
 * Determines if a given point is on the screen.
 **************************************************************************/
bool Game :: isOnScreen(const Point & point)
{
   return (point.getX() >= topLeft.getX() - OFF_SCREEN_BORDER_AMOUNT
      && point.getX() <= bottomRight.getX() + OFF_SCREEN_BORDER_AMOUNT
      && point.getY() >= bottomRight.getY() - OFF_SCREEN_BORDER_AMOUNT
      && point.getY() <= topLeft.getY() + OFF_SCREEN_BORDER_AMOUNT);
}

/**************************************************************************
 * GAME :: HANDLE COLLISIONS
 * Check for a collision between a bird and a bullet.
 **************************************************************************/
void Game :: handleCollisions()
{
   // now check for a hit (if it is close enough to any live bullets)
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i].isAlive())
      {
         // this bullet is alive, see if its too close

         // check if the rock is at this point (in case it was hit)
         //if (bird != NULL && bird->isAlive())
         {
            // BTW, this logic could be more , but this will
            // get the job done for now...
            //if (fabs(bullets[i].getPoint().getX() - bird->getPoint().getX()) < CLOSE_ENOUGH
            //   && fabs(bullets[i].getPoint().getY() - bird->getPoint().getY()) < CLOSE_ENOUGH)
            {
               //we have a hit!
               
               // hit the bird
               //int points = bird->hit();
               //score += points;
               // the bullet is dead as well
               bullets[i].kill();
            }
         }
      } // if bullet is alive
      
   } // for bullets
}

/**************************************************************************
 * GAME :: CLEAN UP ZOMBIES
 * Remove any dead objects (take bullets out of the list, deallocate bird)
 **************************************************************************/

void Game :: cleanUpZombies()
{

   // Look for dead bullets
   vector<Bullet>::iterator bulletIt = bullets.begin();
   while (bulletIt != bullets.end())
   {
      Bullet bullet = *bulletIt;
      // Asteroids Hint:
      // If we had a list of pointers, we would need this line instead:
      //Bullet* pBullet = *bulletIt;
      
      if (!bullet.isAlive())
      {
         // If we had a list of pointers, we would need to delete the memory here...
         
         
         // remove from list and advance
         bulletIt = bullets.erase(bulletIt);
      }
      else
      {
         bulletIt++; // advance
      }
   }
   
}

/***************************************
 * GAME :: HANDLE INPUT
 * accept input from the user
 ***************************************/
void Game :: handleInput(const Interface & ui)
{
   // Change the direction of the rifle
   if (ship.isAlive())
   {
   if (ui.isLeft())
   {
      ship.rotateLeft();
   }
   if (ui.isRight())
   {
      ship.rotateRight();
   }
   
   if (ui.isUp())
   {
      ship.applyThrustUp();
   }
   
   // Check for "Spacebar
   if (ui.isSpace())
   {

      Bullet newBullet;
      newBullet.fire(ship.getPoint(), ship.getRotation());
      bullets.push_back(newBullet);
   }
   }
}

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game :: draw(const Interface & ui)
{
   /*
   // draw the bird
   // TODO: Check if you have a valid bird and if it's alive
   // then call it's draw method
   if (bird != NULL && bird->isAlive())
   {
  
      bird->draw();
   
   };
  */

   // draw the ship
   ship.draw();
   // draw the bullets, if they are alive
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i].isAlive())
      {
         bullets[i].draw();
      }
   }
   /*
   // Put the score on the screen
   Point scoreLocation;
   scoreLocation.setX(topLeft.getX() + 5);
   scoreLocation.setY(topLeft.getY() - 5);
   drawNumber(scoreLocation, score);
   
   // Puts the old or current highscore on the screen
   Point highScoreLocation;
   highScoreLocation.setX(175);
   highScoreLocation.setY(194);
   drawNumber(highScoreLocation, highscore);
   
   // Puts the amount of remaining birds on the top middle
   Point BirdsRemaining;
   BirdsRemaining.setX(-5);
   BirdsRemaining.setY(194);
   drawNumber(BirdsRemaining, birdAmount);
   
   Point textBirds;
   textBirds.setX(-105);
   textBirds.setY(186);
   drawText(textBirds,"Birds Remaining:");
   
   Point textScore;
   // Adjust the headers if there is a longer number to draw.
   if (score > 9 || score < 0)
   {
      textScore.setX(topLeft.getX() + 35);
      textScore.setY(topLeft.getY() - 14);
   }
   else
   {
      textScore.setX(topLeft.getX() + 20);
      textScore.setY(topLeft.getY() - 14);
   }

   drawText(textScore,":Score");
   
   Point textHighScore;
   textHighScore.setX(100);
   textHighScore.setY(186);
   drawText(textHighScore,"High Score:");
   */


   
}


