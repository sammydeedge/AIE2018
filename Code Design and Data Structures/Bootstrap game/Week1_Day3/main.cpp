#include "Week1_Day3App.h"
#include "Sprite.h"
#include "Renderer2D.h"
#include "Font.h"

Week1_Day3App* game;

enum screenState
{
	opening,
	gameplay,
	gameOver
};

/*
void screen_Opening()
{
	auto m_2dRenderer = new aie::Renderer2D();
	auto m_font = new aie::Font("../bin/font/AldotheApache.ttf", 32);
	m_2dRenderer->drawText(m_font, "Hit the Deck", 600, 450);
	m_2dRenderer->drawText(m_font, "Press S to start", 600, 400);
}*/



void screen_Game()
{
	// allocation
	auto app = new Week1_Day3App();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

}

//void screen_GameOver()
//{
//	auto m_font = new aie::Font("../bin/font/AldotheApache.ttf", 32);
//	m_2dRenderer->drawText(m_font, "Hit the Deck", 600, 450);
//}


int main() {
	screenState currentScreen = gameplay; //change to opening

	if (currentScreen == gameplay)
	{
		screen_Game();
	}
	else if (currentScreen == opening)
	{
		//screen_Game();
	}
	else if (currentScreen == gameOver)
	{
		/*screen_GameOver();*/
	}
	
}