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

// TODO: include your rocks, ship and bullet
#include "bullet.h"
#include "rocks.h"
#include "ship.h"
#include <vector>


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

   float getClosestDistance(const FlyingObject& obj1, const FlyingObject& obj2) const; 
   
   
protected:
   // The coordinates of the screen
   Point topLeft;
   Point bottomRight;
   Ship ship;
   
   std::vector<Bullet> bullets;
     
   std::vector<Rock*> pRocks;

   /*************************************************
    * Private methods to help with the game logic.
    *************************************************/

   void advanceBullets();
   void advanceRocks();
   void advanceShip();
   
   void handleCollisions();
   void cleanUpZombies();
   
};

#endif /* GAME_H */
