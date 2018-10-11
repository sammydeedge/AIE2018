#include "Fancy_Matrices_GameApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "CLDR.h"


Fancy_Matrices_GameApp::Fancy_Matrices_GameApp() {

}

Fancy_Matrices_GameApp::~Fancy_Matrices_GameApp() {

}

bool Fancy_Matrices_GameApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font			= new aie::Font("../bin/font/abduction2002.ttf", 32);
	m_titlefont		= new aie::Font("../bin/font/RIOTSQUA.ttf", 70);


	Vector2 P1Pos = Vector2((getWindowWidth() / 2.0f) - 50.0f, getWindowHeight() / 2.0f);
	Vector2 P2Pos = Vector2((getWindowWidth() / 2.0f) + 50.0f, getWindowHeight() / 2.0f);

	//Creating scene_objects
	m_P1body				= new scene_object(scene_object::P1Tank, P1Pos.x, P1Pos.y, 180);
	m_P1barrel				= new scene_object(scene_object::P1Barrel, P1Pos.x, P1Pos.y, 180);
	m_P2body				= new scene_object(scene_object::P2Tank, P2Pos.x, P2Pos.y, 180);
	m_P2barrel				= new scene_object(scene_object::P2Barrel, P2Pos.x, P2Pos.y, 180);

	//Creating player data files
	m_P1data				= new player_data();
	m_P2data				= new player_data();


	m_P1body->addChild(m_P1barrel);
	m_P2body->addChild(m_P2barrel);

	return true;
}

void Fancy_Matrices_GameApp::shutdown() {


	delete	m_P2barrel;
	delete	m_P2body;
	delete	m_P1barrel;
	delete	m_P1body;

	delete	m_font;
	delete	m_2dRenderer;
}

void Fancy_Matrices_GameApp::clearBullets()
{
	for (auto bullet : m_bulletVector)									//For every bullet in the list of available bullet
	{
		delete bullet;
	}

}
void Fancy_Matrices_GameApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	//turns P1
	if (input->isKeyDown(aie::INPUT_KEY_A))
	{
		m_P1body->rotate(deltaTime);
	}
	if (input->isKeyDown(aie::INPUT_KEY_D))
	{
		m_P1body->rotate(-deltaTime);
	}

	//turns P2
	if (input->isKeyDown(aie::INPUT_KEY_KP_4))
	{
		m_P2body->rotate(deltaTime);
	}
	if (input->isKeyDown(aie::INPUT_KEY_KP_6))
	{
		m_P2body->rotate(-deltaTime);
	}

	//speed settings
	float setspeed = 100;
	float adj_speed = deltaTime * setspeed;

	//move P1 forwards and backwards
	if (input->isKeyDown(aie::INPUT_KEY_W))
	{
		auto facing = m_P1body->getLocalTransformColumnVector(1) * adj_speed;
		m_P1body->translate(facing.x, facing.y, deltaTime);
	}
	if (input->isKeyDown(aie::INPUT_KEY_S))
	{
		auto facing = m_P1body->getLocalTransformColumnVector(1) * -adj_speed;
		m_P1body->translate(facing.x, facing.y, deltaTime);
	}

	//move P2 forwards and backwards
	if (input->isKeyDown(aie::INPUT_KEY_KP_8))
	{
		auto facing = m_P2body->getLocalTransformColumnVector(1) * adj_speed;
		m_P2body->translate(facing.x, facing.y, deltaTime);
	}
	if (input->isKeyDown(aie::INPUT_KEY_KP_2))
	{
		auto facing = m_P2body->getLocalTransformColumnVector(1) * -adj_speed;
		m_P2body->translate(facing.x, facing.y, deltaTime);
	}

	// turns P1 turrent
	if (input->isKeyDown(aie::INPUT_KEY_Q))
	{
		m_P1barrel->rotate(deltaTime);
	}
	if (input->isKeyDown(aie::INPUT_KEY_E))
	{
		m_P1barrel->rotate(-deltaTime);
	}

	// turns P2 turrent
	if (input->isKeyDown(aie::INPUT_KEY_KP_7))
	{
		m_P2barrel->rotate(deltaTime);
	}
	if (input->isKeyDown(aie::INPUT_KEY_KP_9))
	{
		m_P2barrel->rotate(-deltaTime);
	}
	
	
	int fireDelay = 30;
	int reloadDelay = 100;

	//fires P1 bullet
	int P1ammo = m_P1data->getAmmoCount();										//Creates variables used for bool checks
	bool P1fire = m_P1data->getRecentFire();

	if (input->isKeyDown(aie::INPUT_KEY_SPACE) && P1ammo > 0 && !P1fire)						//If Space is pressed, P1 has ammo, and is not on fire cooldown
	{
  		m_bullet = new scene_object(scene_object::Bullet, m_P1barrel->getGlobalTransform());		//Create a bullet with a transform matching the barrel
		m_bulletVector.push_back(m_bullet);														//add to the list of bullets
		m_P1data->setAmmoCount(P1ammo - 1);														//remove 1 from ammo count
		m_P1data->setRecentFire(true);															//cooldown starts
		m_P1data->resetTimer();																	//with a reset timer
	}
	int P1timeCheck = m_P1data->getTimer();														//get the timer value
	if (P1fire && P1timeCheck < fireDelay)										//If in cooldown, and has not reached the end of the cooldown timer
	{
		m_P1data->incrementTimer();												//Keep the timer ticking over
	}
	else if (P1fire && P1timeCheck >= fireDelay)								//Otherwise if in cooldown, and reached the end of the delay
	{		
		m_P1data->setRecentFire(false);											//turn off the firing cooldown
		m_P1data->resetTimer();													//reset the timer to 0
	}
	if (!P1fire && P1ammo < 3 && P1timeCheck < reloadDelay)						//If not on cooldown, ammo is not full, and has not reached end of reload timer
	{
		m_P1data->incrementTimer();												//Keep the timer ticking over
	}
	else if (!P1fire && P1ammo < 3 && P1timeCheck >= reloadDelay)				//If not on cooldown, ammo is not full, and has reached end of reload timer
	{
		m_P1data->setAmmoCount(P1ammo + 1);										//Add 1 to the ammo
		m_P1data->resetTimer();													//reset the timer
	}

	//fires P2 bullet, functions same as previous
	int P2ammo = m_P2data->getAmmoCount();
	bool P2fire = m_P2data->getRecentFire();
	if (input->isKeyDown(aie::INPUT_KEY_KP_0) && P2ammo > 0 && !P2fire)
	{
		m_bullet = new scene_object(scene_object::Bullet,m_P2barrel->getGlobalTransform());
		m_bulletVector.push_back(m_bullet); 
		m_P2data->setAmmoCount(P2ammo - 1);
		m_P2data->setRecentFire(true);
		m_P2data->resetTimer();
	}
	int P2timeCheck = m_P2data->getTimer();
	if (P2fire && P2timeCheck < fireDelay)
	{
		m_P2data->incrementTimer();
	}
	else if (P2fire && P2timeCheck >= fireDelay)
	{
		m_P2data->setRecentFire(false);
		m_P2data->resetTimer();
	}
	if (!P2fire && P2ammo < 3 && P2timeCheck < reloadDelay)
	{
		m_P2data->incrementTimer();
	}
	else if (!P2fire && P2ammo < 3 && P2timeCheck >= reloadDelay)
	{
		m_P2data->setAmmoCount(P2ammo + 1);
		m_P2data->resetTimer();
	}

	for (auto bullet : m_bulletVector)									//For every bullet in the list of available bullet
	{
		auto facing = bullet->getLocalTransformColumnVector(1);			//get a vector that contains information for moving "forward"
		bullet->translate(facing.x, facing.y, deltaTime);				//Translate based on that vector

		/*if (CLDR::overlaps(bullet->m_collider.sphere, m_walls))*/

		if (CLDR::overlaps(bullet->m_collider.sphere, m_P1body->m_collider.AABB))
		{
			m_P1data->loseLife();
			clearBullets();
		}
	}

	

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Fancy_Matrices_GameApp::showPlayerstats()
{

	int P1livesCount = m_P1data->getLives();												//Set variables to equal P1 data values
	int P1ammoCount = m_P1data->getAmmoCount();
	
	std::string StatsDisplayP1 = "Lives: ";											//Creates lives string and add lives count value
	StatsDisplayP1 += std::to_string(P1livesCount);
	StatsDisplayP1 += " Ammo: ";													//Creates ammo string and add ammo count value
	StatsDisplayP1 += std::to_string(P1ammoCount);


	int P2livesCount = m_P2data->getLives();												//Set variables to equal P2 data values
	int P2ammoCount = m_P2data->getAmmoCount();

	std::string StatsDisplayP2 = "Lives: ";											//Creates lives string and add lives count value
	StatsDisplayP2 += std::to_string(P2livesCount);
	StatsDisplayP2 += " Ammo: ";													//Creates ammo string and add ammo count value
	StatsDisplayP2 += std::to_string(P2ammoCount);

	m_2dRenderer->drawText(m_titlefont, "P1", 20, 650);
	m_2dRenderer->drawText(m_font, StatsDisplayP1.c_str(), 100, 650);
	m_2dRenderer->drawText(m_titlefont, "P2", 520, 650);
	m_2dRenderer->drawText(m_font, StatsDisplayP2.c_str(), 600, 650);

}



void Fancy_Matrices_GameApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	m_P1body->draw(m_2dRenderer);
	m_P2body->draw(m_2dRenderer);

	//For all bullets in the list, draw
	for (auto bullet : m_bulletVector)
	{
		bullet->draw(m_2dRenderer);
	}

	
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);
	showPlayerstats();

	// done drawing sprites
	m_2dRenderer->end();
}