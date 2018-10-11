#include "idle_clicker_helper.h"

bool shouldContinueRunning = true;
int bits = 0;
int bytes = 0;
int kilobytes = 0;
int megabytes = 0;
int gigabytes = 0;
int cpus = 0;
int mBoards = 0;
int graphicCard = 0;
int monitor = 0;
int electro = 0;
int peripherals = 0;
int computer = 0;
int money = 0;
bool mBoardsPrice = false;
bool peripheralsPrice = false;
bool monitorPrice = false;
bool computerPrice = false;

void conversionCheck()
	{
	while (bits >= 8) {
		bits = bits - 8;
		bytes = bytes + 1;
	}

	while (bytes >= 1000) {
		bytes = bytes - 1000;
		kilobytes = kilobytes + 1;
	}

	while (kilobytes >= 1000) {
		kilobytes = kilobytes - 1000;
		megabytes = megabytes + 1;
	}

	while (megabytes >= 1000) {
		megabytes -= 1000;
		gigabytes++;
	}
	}

void update() {
	mBoardsPrice = (cpus >= 15) && (bytes >= 25) && (electro >= 20);
	peripheralsPrice = (cpus >= 7) && (electro >= 20) && (bytes >= 10);
	monitorPrice = (electro >= 15) && (graphicCard >= 20) && (bytes >= 25);
	computerPrice = (mBoards >= 5) && (peripherals >= 3) && (monitor >= 1) && (megabytes >= 1);

	bits += (cpus + electro) * 3;
	bytes += graphicCard * 10;
	kilobytes += mBoards * 1;
	
	conversionCheck();

}

void insufficient() {
	std::cout << "Insufficient resources! Sorry!\n";
}
void draw()
{
	system("cls");
	if (money > 0) {
		std::cout << "You have $" << money << std::endl;
	}
	if (computer > 0) {
		std::cout << "You have " << computer << " computers" << std::endl;
	}
	if (monitor > 0) {
		std::cout << "You have " << monitor << " monitors" << std::endl;
	}
	if (peripherals > 0) {
		std::cout << "You have " << peripherals << " peripherals" << std::endl;
	}
	if (mBoards > 0) {
		std::cout << "You have " << mBoards << " motherboards" << std::endl;
	}
	if (graphicCard > 0) {
		std::cout << "You have " << graphicCard << " graphics Cards" << std::endl;
	}
	if (electro > 0) {
		std::cout << "You have " << electro << " electronics" << std::endl;
	}
	if (cpus > 0) {
		std::cout << "You have " << cpus << " CPUs" << std::endl;
	}
	if (gigabytes > 0) {
		std::cout << "You have " << gigabytes << " gigabytes" << std::endl;
	}
	if (megabytes > 0) {
		std::cout << "You have " << megabytes << " megabytes" << std::endl;
	}
	if (kilobytes > 0) {
		std::cout << "You have " << kilobytes << " kilobytes" << std::endl;
	}
	if (bytes > 0) {
		std::cout << "You have " << bytes << " bytes" << std::endl;
	}
	std::cout << "You have " << bits << " bits" << std::endl;

}

void handleKey(char c)
{
	//If the user hits the Q, quit
	if (c == 'q')
	{
		std::cout << "Quit intialised" << std::endl;
		shouldContinueRunning = false;
	}

	if (c == '1')
	{
		bits = bits + 1;
		conversionCheck();
		draw();
	}

	if (c == '2')
	{
		if (bytes >= 20)
		{
			bytes -= 20;
			cpus++;
			draw();
		}
		else {
			insufficient();
		}

	}

	if (c == '3') {
		if (bytes >= 50)
		{
			bytes -= 50;
			graphicCard++;
			draw();
		}
		else {
			insufficient();
		}
	}

	if (c == '4') {
		if (bytes >= 10)
		{
			bytes -= 10;
			electro++;
			draw();
		}
		else {
			insufficient();
		}
	}
	if (c == '5') {
		if (mBoardsPrice)
		{
			cpus -= 15;
			bytes -= 25;
			electro -= 20;
			mBoards++;
			draw();
		}
		else {
			insufficient();
		}

	}
	if (c == '6') {
		if (peripheralsPrice)
		{
			cpus -= 7;
			bytes -= 10;
			electro -= 20;
			peripherals++;
			draw();
		}
		else {
			insufficient();
		}

	}
	if (c == '7') {
		if (monitorPrice)
		{
			graphicCard -= 20;
			bytes -= 25;
			electro -= 15;
			monitor++;
			draw();
		}
		else {
			insufficient();
		}

	}
	if (c == '8') {
		if (computerPrice)
		{
			mBoards -= 5;
			peripherals -= 3;
			monitor--;
			megabytes--;
			computer++;
			draw();
		}
		else {
			insufficient();
		}

	}
	if (c == '9') {
		if (computer >= 1)
		{
			computer--;
			money += 100;
			draw();
		}
		else {
			insufficient();
		}

	}
}

int main()
{
	AsyncKeyboard::setupKeyboard(handleKey);

	while (shouldContinueRunning) 
	{
		update();
		draw();
		std::this_thread::sleep_for(1s);
		
	}

	AsyncKeyboard::shutdown();

	return 0;
}