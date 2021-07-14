/*********************************************************************
 * File: game.h
 * Description: Defines the game class for Asteroids
 *
 *********************************************************************/

#ifndef GAME_H
#define GAME_H

/*************************************************************
 * File: game.h
 * Author: Alexander Dohms
 *
 * Description: The game of Skeet. This class holds each piece
 *  of the game (birds, bullets, rifle, score). It also has
 *  methods that make the game happen (advance, interact, etc.)
 *
 * Please DO NOT share this code with other students from
 *  other sections or other semesters. They may not receive
 *  the same code that you are receiving.
 *************************************************************/

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "velocity.h"
#include <iostream>
#include <fstream>
#include "string.h"
#include <exception>
#include <memory>
#include <vector>

// TODO: include your rocks, ship and bullet
#include "bullet.h"
#include "rocks.h"
#include "ship.h"

/*****************************************
 * GAME
 * The main game class containing all the state
 *****************************************/
class Game
{
public:
   /*********************************************
    * Constructor
    * Initializes the game
    *********************************************/
   Game(Point tl, Point br);
   ~Game();
   
   /*********************************************
    * Function: handleInput
    * Description: Takes actions according to whatever
    *  keys the user has pressed.
    *********************************************/
   void handleInput(const Interface & ui);
   
   /*********************************************
    * Function: advance
    * Description: Move everything forward one
    *  step in time.
    *********************************************/
   void advance();
   
   /*********************************************
    * Function: draw
    * Description: draws everything for the game.
    *********************************************/
   void draw(const Interface & ui);
   
protected:
   // The coordinates of the screen
   Point topLeft;
   Point bottomRight;
   Ship ship;
   
   // Declare a vector of bullets
   std::vector<Bullet> bullets;
   
   // Declare a vector of pointers (pRocks) to Rock
   std::vector<Rock*> pRocks;

   /*************************************************
    * Private methods to help with the game logic.
    *************************************************/

   /*********************************************
    * Function: advance*()
    * Description: Allows objects advance functions to be called
    * if they meet certain criteria!
    *********************************************/
   void advanceBullets();
   void advanceRocks();
   void advanceShip();
   
   /*********************************************
    * Function: getClosestDistance
    * Description: Returns the closest distance of any two objects.
    *********************************************/
   float getClosestDistance(const FlyingObject& obj1, const FlyingObject& obj2) const;
   
   /*********************************************
    * Function: handleCollisions()
    * Description: calls functions based on a collision, or when any two objects get too close
    * to eachother acording to rules.
    *********************************************/
   void handleCollisions();
   
   /*********************************************
    * Function: cleanUpZombies
    * Description: Erases and deletes objects out of vectors
    * acording to if they are alive or not. Useful for cleaning up memory.
    * DoN't Be A sLoB!
    *********************************************/
   void cleanUpZombies();
   
};

#endif /* GAME_H */
