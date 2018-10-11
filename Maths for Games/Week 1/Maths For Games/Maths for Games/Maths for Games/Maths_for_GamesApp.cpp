#include "Maths_for_GamesApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

Maths_for_GamesApp::Maths_for_GamesApp() {

}

Maths_for_GamesApp::~Maths_for_GamesApp() {

}

bool Maths_for_GamesApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	return true;
}

void Maths_for_GamesApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void Maths_for_GamesApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Maths_for_GamesApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}