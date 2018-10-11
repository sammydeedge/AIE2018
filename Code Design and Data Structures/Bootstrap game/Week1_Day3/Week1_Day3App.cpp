#include "Week1_Day3App.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Sprite.h"
#include "Enemy.h"
#include <cassert>
<<<<<<< HEAD
#include <vector>
#include <random>
#include <ctime>
#include <string>
=======
#include <random>
#include <ctime>
#include <string>
#include <vector>
>>>>>>> 743611b5c5a55a637547fe8cd86b648d4b645c77

//struct sprite
//{
//	aie::Texture image;
//	float x, y;
//};

int score = 0;

<<<<<<< HEAD
//Spawns new enemies
void Week1_Day3App::EnemySpawn()
{
	enemy* foe = new enemy();
	m_enemyList.push_back(foe);
}




=======

void Week1_Day3App::EnemySpawn()
{
	enemy* foe  = new enemy();
	m_enemyList.push_back(*foe);
	m_enemyCount++;
}

>>>>>>> 743611b5c5a55a637547fe8cd86b648d4b645c77
Week1_Day3App::Week1_Day3App() {

}

Week1_Day3App::~Week1_Day3App() {

}

bool Week1_Day3App::startup() {
	
<<<<<<< HEAD
	srand((unsigned int)time(nullptr));
=======
>>>>>>> 743611b5c5a55a637547fe8cd86b648d4b645c77
	m_2dRenderer = new aie::Renderer2D();

	/// TODO: remember to change this when redistributing a build!
	/// the following path would be used instead: "./font/consolas.ttf"
	//Setting up custom font
	m_font = new aie::Font("../bin/font/AldotheApache.ttf", 32);

	//Intialising all the textures being used in game
	m_playertexture = new aie::Texture("../bin/textures/JD.png");
<<<<<<< HEAD
	m_playerinvtexture = new aie::Texture("../bin/textures/JDinv.png");
=======
>>>>>>> 743611b5c5a55a637547fe8cd86b648d4b645c77
	m_goldtexture = new aie::Texture("../bin/textures/gold.png");

	//Creates sprites
	m_player = new sprite(m_playertexture, 500.0f, 500.0f, 12);
	m_gold = new sprite(m_goldtexture, 100.0f, 200.0f, 0);
	EnemySpawn();
<<<<<<< HEAD

=======
	
>>>>>>> 743611b5c5a55a637547fe8cd86b648d4b645c77
	
	return true;
}

void Week1_Day3App::shutdown() {

	//deletes intialised textures, font and renderer
	delete m_playertexture;
	delete m_font;
	delete m_2dRenderer;
}

<<<<<<< HEAD
void Week1_Day3App::printScore(int score)
{
	std::string toDisplay = "Score: ";                                                    //Creates score text
	toDisplay += std::to_string(score);                                                    //Adds the score data
	m_2dRenderer->drawText(m_font, toDisplay.c_str(), 10, getWindowHeight() - 40);        //Prints in top left corner

=======

void Week1_Day3App::printScore(int score)
{
	std::string toDisplay = "Score: ";													//Creates score text
	toDisplay += std::to_string(score);													//Adds the score data
	m_2dRenderer->drawText(m_font, toDisplay.c_str(), 10, getWindowHeight() - 40);		//Prints in top left corner
>>>>>>> 743611b5c5a55a637547fe8cd86b648d4b645c77
}

//Displays number of times crashed into enemy. Remove from code later, for debugging only
void Week1_Day3App::crashed()
{
	std::string toDisplay = "Lives: ";
	toDisplay += std::to_string(livesLeft);
<<<<<<< HEAD
	m_2dRenderer->drawText(m_font, toDisplay.c_str(), 10, 600);
}

void Week1_Day3App::update(float deltaTime) {
=======
	m_2dRenderer->drawText(m_font, toDisplay.c_str(), 10, getWindowHeight()-80);
}

void Week1_Day3App::update(float deltaTime) {
	
>>>>>>> 743611b5c5a55a637547fe8cd86b648d4b645c77

	// input example
	aie::Input* input = aie::Input::getInstance();


	//Moves enemy "forward" at a set speed based on random rotation set
<<<<<<< HEAD
	for (auto it = 0; it < m_enemyList.size(); ++it)								//Iterates through list of enemy sprites
	{
		enemy* curr_enemy = m_enemyList[it];										//gives pointer to current enemy sprite being used
		float speed = curr_enemy->getSpeed();										
		float updateX = (curr_enemy->getXcoeff()) * speed;							//Gets speed and x&y coefficients to get x&y update values
		float updateY = (curr_enemy->getYcoeff()) * speed;

		assert(curr_enemy->m_x > -5 && curr_enemy->m_x < getWindowWidth() + 5		//Makes sure enemy is within screen
			&& curr_enemy->m_y > -5 && curr_enemy->m_y < getWindowHeight() + 5);
		curr_enemy->m_x += updateX;													//Applies the x&y update values, moving the sprite
		curr_enemy->m_y += updateY;
=======
	for (auto it = m_enemyList.cbegin(); it !=m_enemyList.cend(); ++it)
	{
		enemy* curr_enemy = m_enemyList[it];

		assert(curr_enemy.m_x > -2 && curr_enemy.m_x < getWindowWidth() + 2 && curr_enemy.m_y > -2 && curr_enemy.m_y < getWindowHeight() + 2);
		curr_enemy.m_x += curr_enemy.m_updateX;
		curr_enemy.m_y += curr_enemy.m_updateY;
>>>>>>> 743611b5c5a55a637547fe8cd86b648d4b645c77

		int screenXmax = getWindowWidth();
		int screenYmax = getWindowHeight();

<<<<<<< HEAD
		if (curr_enemy->hitEdge(screenXmax, screenYmax) == enemy::wall::leftRight)		//If enemy hits the left or right side of screen:
		{
			curr_enemy->reflectX();														//Reverse x movement, reflecting off edge
		}
		else if (curr_enemy->hitEdge(screenXmax, screenYmax) == enemy::wall::upDown)	//If enemy hits top or bottom of screen:
		{
			curr_enemy->reflectY();														//Reverse y movement, reflecting off edge
		}
	}
	
=======
		if (curr_enemy.hitEdge(screenXmax, screenYmax) == enemy::wall::leftRight)
		{
			curr_enemy.m_updateX = curr_enemy.m_updateX * -1;
		}
		else if (curr_enemy.hitEdge(screenXmax, screenYmax) == enemy::wall::upDown)
		{
			curr_enemy.m_updateY = curr_enemy.m_updateY * -1;
		}
	}
>>>>>>> 743611b5c5a55a637547fe8cd86b648d4b645c77
	/*Set of commands that moves player up, down, left and right, at a set speed, based on arrow key input*/
	if (input->isKeyDown(aie::INPUT_KEY_UP))
	{
		m_player->m_y += m_player->m_speed;
	}

	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
	{
		m_player->m_y -= m_player->m_speed;
	}

	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
	{
		m_player->m_x -= m_player->m_speed;
	}

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
	{
		m_player->m_x += m_player->m_speed;
	}

<<<<<<< HEAD
	if (m_player->collisionCheck(*m_gold))									//If a player collides with gold sprite:
	{
		static int counter = 0;
		counter++;

		int r1 = rand();													//Get two random values
		int r2 = rand();

		int xPos = (r1 % (getWindowWidth() - 20)) + 10;						//use modulus to keep values within screen
		int yPos = (r2 % (getWindowHeight() - 20)) + 10;

		m_gold->m_x = xPos;													//Move gold to x&y values
		m_gold->m_y = yPos;
		assert(m_gold->m_x >= 0 && m_gold->m_x < getWindowWidth() &&		//Check that gold sprite is on screen
			m_gold->m_y >= 0 && m_gold->m_y < getWindowHeight());
		++score;															//Score is increased
		for (auto enemy : m_enemyList)										//Iterate through enemy list
		{
			float speed = enemy->getSpeed();								//Get their speed
			if (speed < 12) { enemy->setSpeed(speed + 0.1f); }				//Increase speed (unless speed is more than or equal to 12)
		}
	}

	bool enemycollision = false;											//set enemy collision checker to false
	for (auto enemy : m_enemyList)											//Iterate through enemy list
	{
		if (m_player->collisionCheck(*enemy))								//If the player has collided with the enemy sprite
		{
			enemycollision = true;											//Set enemy collision check to true
		}
	}				
	if (enemycollision && !(m_player->invulnerable))						//After the iteration, if enemy collsion was detected and the player isn't invulnerable:
	{
		livesLeft--;														//Player loses a life
		m_player->invulnerable = true;										//Player is (temporarily) invulnerable
	}
	else if (!enemycollision)												//If no collison is detected:
	{
		m_player->invulnerable = false;										//Reset the player to be vulnerable again.
	}


	//If score is lower than 1/10 of score, spawn in a new enemy
	if ((score / 5) > m_enemyList.size() - 1)
=======
	if (*m_player == *m_gold)					//If a player collides with gold sprite:
	{
		m_gold->m_x = rand() % 1000;			//Gold moves to a random location
		m_gold->m_y = rand() % 600 + 20;
		++score;								//Score is increased
		for (auto enemy : m_enemyList)
		{
			enemy->updateMovement(enemy->m_speed, (m_enemy->m_speed + 0.1f));
		}				//Enemy speed is increased
	}
	if (*m_player == *m_enemy)					//If player collides with an enemy:
	{
		livesLeft--;								//Increase the crash tally
	}
		
	//If score is lower than 1/10 of score, spawn in a new enemy
	if ((score / 10) > m_enemyCount-1)
>>>>>>> 743611b5c5a55a637547fe8cd86b648d4b645c77
	{
		EnemySpawn();
	}
	
	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Week1_Day3App::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
<<<<<<< HEAD
	if (!(m_player->invulnerable)) { m_2dRenderer->drawSprite(m_playertexture, m_player->m_x, m_player->m_y); }
	if ((m_player->invulnerable)) { m_2dRenderer->drawSprite(m_playerinvtexture, m_player->m_x, m_player->m_y); }
	m_2dRenderer->drawSprite(m_goldtexture, m_gold->m_x, m_gold->m_y);
	for (auto enemy : m_enemyList)
	{
		m_2dRenderer->drawSprite(enemy->m_image, enemy->m_x, enemy->m_y);
	}



=======
	m_2dRenderer->drawSprite(m_playertexture, m_player->m_x, m_player->m_y);
	m_2dRenderer->drawSprite(m_goldtexture, m_gold->m_x, m_gold->m_y);
	for (auto sprite : m_enemyList)
	{
		m_2dRenderer->drawSprite(m_enemytexture, m_enemy->m_x, m_enemy->m_y);
	}


>>>>>>> 743611b5c5a55a637547fe8cd86b648d4b645c77
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 5, 5);

	
	
	printScore(score);
	crashed();
	
	// done drawing sprites
	m_2dRenderer->end();
}
