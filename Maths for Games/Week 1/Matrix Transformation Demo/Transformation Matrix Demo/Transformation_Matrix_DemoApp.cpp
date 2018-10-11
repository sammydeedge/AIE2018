#include "Transformation_Matrix_DemoApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Sprite.h"

Transformation_Matrix_DemoApp::Transformation_Matrix_DemoApp() {

}

Transformation_Matrix_DemoApp::~Transformation_Matrix_DemoApp() {

}

bool Transformation_Matrix_DemoApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	//Intialising Textures for the tank's body and barrel
	m_tankbodyTexture = new aie::Texture("../bin/textures/tankRed.png");
	m_tankbarrelTexture = new aie::Texture("../bin/textures/barrelRed.png");
	
	//Creating sprite files for the body and barrel
	m_tankbody = new sprite(m_tankbodyTexture, 100, 100, 180);
	m_tankbarrel = new sprite(m_tankbarrelTexture, 100, 100, 180);

	m_tankbody->addChild(m_tankbarrel);
	m_tankbody->setPosition(getWindowWidth() / 2.0f, getWindowHeight() / 2.0f);

	return true;
}

void Transformation_Matrix_DemoApp::shutdown() {

	delete m_tankbarrel;
	delete m_tankbody;
	delete m_font;
	delete m_2dRenderer;
}

void Transformation_Matrix_DemoApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	// turns tank
	if (input->isKeyDown(aie::INPUT_KEY_A))
	{
		m_tankbody->rotate(deltaTime);
	}
	if (input->isKeyDown(aie::INPUT_KEY_D))
	{
		m_tankbody->rotate(-deltaTime);
	}

	//move tank forward and backwards
	float setspeed = 100;
	float adj_speed = deltaTime * setspeed;
	if (input->isKeyDown(aie::INPUT_KEY_W))
	{
		auto facing = m_tankbody->getLocalTransformColumnVector(1) * adj_speed;
		m_tankbody->translate(facing.x, facing.y, deltaTime);
	}
	if (input->isKeyDown(aie::INPUT_KEY_S))
	{
		auto facing = m_tankbody->getLocalTransformColumnVector(1) * -adj_speed;
		m_tankbody->translate(facing.x, facing.y, deltaTime);
	}

	// turns turrent
	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
	{
		m_tankbarrel->rotate(deltaTime);
	}
	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
	{
		m_tankbarrel->rotate(-deltaTime);
	}

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Transformation_Matrix_DemoApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	m_tankbody->draw(m_2dRenderer);
	
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}