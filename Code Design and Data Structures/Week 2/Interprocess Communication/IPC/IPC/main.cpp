#include "IPCApp.h"

int main() {
	
	// allocation
	auto app = new IPCApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}