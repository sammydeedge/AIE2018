#include "Maths_for_GamesApp.h"

int main() {
	
	// allocation
	auto app = new Maths_for_GamesApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}