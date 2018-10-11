#include "Transformation_Matrix_DemoApp.h"

int main() {
	
	// allocation
	auto app = new Transformation_Matrix_DemoApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}