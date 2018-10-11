#include "CheckersVSApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

CheckersVSApp::CheckersVSApp() {

}

CheckersVSApp::~CheckersVSApp() {

}

bool CheckersVSApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font					= new aie::Font("../bin/font/Rusted Orlando Sans Demo.ttf", 50);

	m_boardTexture			= new aie::Texture("../bin/textures/board.png");
	m_orangepieceTexture	= new aie::Texture("../bin/textures/orangepiece.png");
	m_orangekingTexture		= new aie::Texture("../bin/textures/orangeking.png");
	m_violetpieceTexture	= new aie::Texture("../bin/textures/violetpiece.png");
	m_violetkingTexture		= new aie::Texture("../bin/textures/violetking.png");

	return true;
}

void CheckersVSApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void CheckersVSApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void CheckersVSApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	m_2dRenderer->drawSprite(m_boardTexture, 640, 360);

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}