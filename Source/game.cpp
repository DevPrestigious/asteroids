/*********************************************************************
 * File: game.cpp
 * Description: Contains the implementaiton of the game class
 *  methods.
 *********************************************************************/

#include "game.h"
// These are needed for the getClosestDistance function...
#include <limits>
#include <algorithm>

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
#include "flyingObject.h"

/***************************************
 * GAME CONSTRUCTOR
 ***************************************/
Game :: Game(Point tl, Point br)
: topLeft(tl), bottomRight(br)
{
   // Creates 5 bigRocks for pRocks the vector.
   for (int i = 0; i < 5; i++)
   {
      pRocks.push_back(new BigRock());
   }
}

/****************************************
 * GAME DESTRUCTOR
 ****************************************/
Game :: ~Game()
{
   // If the bullets are not alive, we will delete them.
   for (int i = 0; i < bullets.size(); i++)
   {
      if (!bullets[i].isAlive())
      {
         delete &bullets[i];
      }
   }
   // If the pRocks are not alive, we will delete them.
   for (int i = 0; i < pRocks.size(); i++)
   {
      if (!pRocks[i]->isAlive())
      {
         delete &pRocks[i];
      }
   }
}

/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game :: advance()
{
   // advance the objects
   {
   advanceBullets();
   advanceRocks();
   advanceShip();
   }
   // handle collisions and deleting objects
   {
   handleCollisions();
   cleanUpZombies();
   }
}

/**************************************************************************
 * GAME :: ADVANCE ROCKS
 * 1. For loop to go through the bullets till it hits the end of the vector.
 * 2. Check if the bullets are alive.
 * 3. Advance them if they're alive.
 * 4. handleBounds() to handle if the bullet goes off the screen.
 **************************************************************************/
void Game :: advanceBullets()
{
   
   // Move each of the bullets forward if it is alive.
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i].isAlive())
      {
         // This bullet is alive, so tell it to move forward.
         bullets[i].advance();
         
         // Keeps bullet from travelling more than 40 frames.
         bullets[i].bulletKiller();
         
         // Pushes the bullet to the other side of the screen.
         bullets[i].handleBounds();
      }
   } // for loop
}

/**************************************************************************
 * GAME :: ADVANCE ROCKS
 * 1. For loop to go through the rocks till it hits the end of the vector.
 * 2. Check if the rocks are alive.
 * 3. Advance them if they're alive.
 * 4. handleBounds() to handle if the rock goes off the screen.
 **************************************************************************/
void Game :: advanceRocks()
{
   // Move each of the rocks forward if it is alive
   for (int i = 0; i < pRocks.size(); i++)
   {
      if (pRocks[i]->isAlive())
      {
         // This rock is alive, so tell it to move forward.
         pRocks[i]->advance();
         
         // Pushes the rock to the other side of the screen.
         pRocks[i]->handleBounds();
      }
   } // for loop
}

/**************************************************************************
 * GAME :: ADVANCE SHIP
 * 1. If the ship is alive, then advance it.
 * 2. HandleBounds() to handle if the ship goes off the screen.
 **************************************************************************/
void Game :: advanceShip()
{
   // we have a ship, make sure it's alive
   if (ship.isAlive())
   {
      // Move it forward.
      ship.advance();
      // Lets ship "scroll" on the screen.
      ship.handleBounds();
   }
}

/**********************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **********************************************************/
float Game::getClosestDistance(const FlyingObject& obj1, const FlyingObject& obj2) const
{
   // find the maximum distance traveled
   float dMax = std::max(abs(obj1.getVelocity().getDx()), abs(obj1.getVelocity().getDy()));
   dMax = std::max(dMax, abs(obj2.getVelocity().getDx()));
   dMax = std::max(dMax, abs(obj2.getVelocity().getDy()));
   dMax = std::max(dMax, 0.1f); // when dx and dy are 0.0. Go through the loop once.

   float distMin = std::numeric_limits<float>::max();
   for (float i = 0.0; i <= dMax; i++)
   {
      Point point1(obj1.getPoint().getX() + (obj1.getVelocity().getDx() * i / dMax),
         obj1.getPoint().getY() + (obj1.getVelocity().getDy() * i / dMax));
      Point point2(obj2.getPoint().getX() + (obj2.getVelocity().getDx() * i / dMax),
         obj2.getPoint().getY() + (obj2.getVelocity().getDy() * i / dMax));

      float xDiff = point1.getX() - point2.getX();
      float yDiff = point1.getY() - point2.getY();

      float distSquared = (xDiff * xDiff) + (yDiff * yDiff);

      distMin = std::min(distMin, distSquared);
   }
   return sqrt(distMin);
}

/**************************************************************************
 * GAME :: HANDLE COLLISIONS
 * Check for a collision between a bird and a bullet.
 **************************************************************************/
void Game :: handleCollisions()
{
   for (int k = 0; k < pRocks.size(); k++)
   {
      if (getClosestDistance(ship, *pRocks[k]) <= 10)
      {
         ship.kill();
      } // if ship "hits" pRocks
   }// for PRocks
   // now check for a hit (if it is close enough to any live bullets)
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i].isAlive())
      {
         // this bullet is alive, see if its too close
         for (int j = 0; j < pRocks.size(); j++)
         {
            if (pRocks[j]->isAlive())
            {
               if (getClosestDistance(bullets[i], *pRocks[j]) <= pRocks[j]->getCollisionSize())
               {
                  // Kills bullets and rocks, breaks apart rocks.
                  pRocks[j]->breakApart(pRocks);
                  pRocks[j]->kill();
                  bullets[i].kill();
               } // if bullets "hits" pRocks
            }// if pRocks is Alive
         } // for pRocks
      } // if bullet is alive
   } // for bullets
}

/**************************************************************************
 * GAME :: CLEAN UP ZOMBIES
 * Remove any dead objects (take bullets out of the list, erase and delete any rocks)
 **************************************************************************/
void Game :: cleanUpZombies()
{
   // Look for dead bullets and dead rocks.
   // Create iterators for the vector
   std::vector<Bullet>::iterator bulletIt = bullets.begin();
   std::vector<Rock*>::iterator rockIt = pRocks.begin();
   while ((bulletIt != bullets.end()) && (rockIt != pRocks.end()))
   {
      // declaring pointers to the iterators
      Bullet bullet = *bulletIt;
      Rock* pRock = *rockIt;
      // if at the position of the object is not alive, then we will delete them
      // otherwise we will continue through the iterator at the else statement
      if (!bullet.isAlive() && !pRock->isAlive())
      {
         // erasing the rock at the rockIt iterator, if the rock is not alive
         rockIt = pRocks.erase(rockIt);
         delete pRock;
         pRock = NULL;
         // remove from list or advance
         bulletIt = bullets.erase(bulletIt);
      }
      // the else statement as mentioned above, it will allow to continue through the iterator
      else
      {
         bulletIt++; // advance
         rockIt++;
      } // else statement
   } // while the the bullet or rock doesn't equal the end of their respective vectors
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
      // Rotate ship left
      if (ui.isLeft())
      {
         ship.rotateLeft();
      }
      
      // Rotates ship right
      if (ui.isRight())
      {
         ship.rotateRight();
      }
   
      // Moves the ship and turns on the ships flames
      if (ui.isUp())
      {
         ship.applyThrustUp();
         ship.setThrust(true);
      }
      
      // Moves the ship back and turns on the ships flames
      if (ui.isDown())
      {
         ship.applyThrustDown();
         ship.setThrust(true);
      }
      
      // Sets the ships thruster flames off if not being used
      if (!ui.isUp() && !ui.isDown())
      {
         ship.setThrust(false);
      }
   
      // Check for "Spacebar"
      if (ui.isSpace())
      {
         Bullet newBullet;
         newBullet.fire(ship.getPoint(), ship.getRotation(), ship.getVelocity());
         bullets.push_back(newBullet);
      }
   } // if ship is alive
   
   // function to allow for respawning of the ship
   else if  (!ship.isAlive())
   {
      if (ui.isSpace())
      {
         ship.setAlive(true);
      }
   }
}

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game :: draw(const Interface & ui)
{
   // draw the ship if the ship is alive, otherwise
   // draw text to the screen to instruct for respawn
   // and set point and velocity to 0
   {
      if (ship.isAlive())
      {
         ship.draw();
      }
      else if (!ship.isAlive())
      {
      drawText(Point(0,0), "Space to respawn.");
      ship.setPoint(Point(0,0));
      ship.setVelocity(Velocity(0, 0));
      }
   }
   
   // draw the rocks, if they are alive
   for (int i = 0; i < pRocks.size(); i++)
   {
      if (pRocks[i]->isAlive())
      {
         pRocks[i]->draw();
      }
   }
   
   // draw the bullets, if they are alive
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i].isAlive())
      {
         bullets[i].draw();
      }
   }
}


