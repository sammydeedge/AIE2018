#include "AntDemoApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <random>
#include <ctime>

AntDemoApp::AntDemoApp() {
	srand((unsigned int)time(nullptr));
}

AntDemoApp::~AntDemoApp() {

}

void AntDemoApp::makeWeb()
{
	using node = Pathfinder::node;
	node* centre = m_pathfinder.addNode(640, 360);
	m_web.push_back(centre);

	float ring_dist = 200;
	Matrix4 rot_Matrix;
	float rot_deg = 0.7853;
	rot_Matrix.setRotateZ(0);

	for (int ring = 1; ring<3; ++ring)							//For each ring of points
	{
		Vector2 spoke = Vector2(0, ring_dist*ring);				//Create a vector for the distance from centre to new point
		for (int point = 1; point < 9; ++point)					//For each point, 
		{
			node* newNode = m_pathfinder.addNode(centre->position + spoke);  //Make new node spoke distance from centre
			m_web.push_back(newNode);								//Add to "web" list of nodes

			rot_Matrix.setRotateZ(rot_deg);					// make a roatation matrix set to 0.7853 radians aka 45 degrees
			Vector4 spoke_temp = Vector4(spoke, 0, 0);		//Rotate a vector4 containing spoke data
			spoke_temp = rot_Matrix * spoke_temp;
			spoke = Vector2(spoke_temp.x, spoke_temp.y);				//Then set it back to a Vector2
		}
	}

	for (int i = 1; i < 9; ++i)								//For all the inner ring points 1-8
	{
		m_pathfinder.connectSelectedNodes(centre, m_web[i]);			//Connect centre point to point x
		if (i < 8)													//If the point is 1-7
		{
			m_pathfinder.connectSelectedNodes(m_web[i], m_web[i + 1]);			//Connect point to next point in ring
		}
	}
	m_pathfinder.connectSelectedNodes(m_web[1], m_web[8]);				//Then connect point 8 to point 1, closing the ring

	for (int i = 9; i < 17; ++i)									//For all outer ring points 9-16
	{
		m_pathfinder.connectSelectedNodes(m_web[i], m_web[i - 8]);			//Connect to the corresponding inner ring point
		if (i < 16)														//If the point is 9-15
		{
			m_pathfinder.connectSelectedNodes(m_web[i], m_web[i + 1]);			//Connect to the next point in ring
		}
	}
	m_pathfinder.connectSelectedNodes(m_web[9], m_web[16]);							//Then connect point 9 to point 16, closing the ring
}

bool AntDemoApp::startup() {

	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	//Setup textures
	m_greenAntTexture	= new aie::Texture("../bin/textures/ant_green.png");
	m_violAntTexture	= new aie::Texture("../bin/textures/ant_viol.png");
	m_foodTexture		= new aie::Texture("../bin/textures/cherry.png");
	m_greenNestTexture	= new aie::Texture("../bin/textures/anthill_green.png");
	m_violNestTexture	= new aie::Texture("../bin/textures/anthill_viol.png");
	m_spiderTexture		= new aie::Texture("../bin/textures/spider.png");
	m_spiderWebTexture	= new aie::Texture("../bin/textures/web.png");

	greenNestPos		= Vector2(100, 100);
	violNestPos			= Vector2(getWindowWidth()-100, getWindowHeight()-100);

	//Creates nests
	Nest* nest = new Nest(greenNestPos, Ant::Green, m_greenNestTexture);
	m_nests.push_back(nest);

	nest = new Nest(violNestPos, Ant::Violet, m_violNestTexture);
	m_nests.push_back(nest);

	//Intialised ant sprites (change before completion
	spawnNewAnt(Ant::Green);
	spawnNewAnt(Ant::Violet);

	makeWeb();

	m_spider = new spider(this, m_spiderTexture);
	m_spider->setPosition(m_web[0]->position);

	//Launching with pre-set up food
	spawnFood();
	spawnFood();
	spawnFood();

	return true;
}

void AntDemoApp::spawnNewAnt(Ant::Team colour)
{
	Ant* ant;
	aie::Texture* texture;
	Vector2 nestPos;
	
	if (colour == Ant::Green)
	{
		texture = m_greenAntTexture;
		nestPos = greenNestPos;

	}
	if (colour == Ant::Violet)
	{
		texture = m_violAntTexture;
		nestPos = violNestPos;
	}


	ant = new Ant(this, colour, texture);
	ant->setPosition(nestPos);

	m_ants.push_back(ant);
}

void AntDemoApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void AntDemoApp::update(float deltaTime) {
	if (deltaTime > 0.1f) { deltaTime = 0; }
	// input example
	aie::Input* input = aie::Input::getInstance();

	if (input->wasKeyPressed(aie::INPUT_KEY_M))
	{
		m_renderPathfinder = !m_renderPathfinder;
	}

	if (input->wasKeyPressed(aie::INPUT_KEY_W))
	{
		m_removeWeb = !m_removeWeb;
	}

	if (m_renderPathfinder && input->wasMouseButtonPressed(0))
	{

		int x, y;
		input->getMouseXY(&x, &y);

		Vector2 mouseLoc = Vector2((float)x, (float)y);

		Pathfinder::node const* node = m_pathfinder.getClosestNode(mouseLoc, 15.0f);

		if (input->isKeyDown(aie::INPUT_KEY_LEFT_SHIFT))
		{
			if (m_selectedPathfindNode && node)
			{
				m_pathfinder.connectSelectedNodes(m_selectedPathfindNode, node);
			}
		}
		else
		{
			if (node != nullptr)
			{
				m_selectedPathfindNode = node;
			}
			else
			{
				m_selectedPathfindNode = m_pathfinder.addNode(mouseLoc);
			}
		}

	}

	if (m_renderPathfinder && input->wasKeyPressed(aie::INPUT_KEY_DELETE))
	{
		if (m_selectedPathfindNode)
		{
			m_pathfinder.removeNode(m_selectedPathfindNode);
			m_selectedPathfindNode = nullptr;
		}
	}

	if (input->wasKeyPressed(aie::INPUT_KEY_1)) //add team food count condition
	{
		spawnNewAnt(Ant::Green);
	}

	if (input->wasKeyPressed(aie::INPUT_KEY_2)) //add team food count condition
	{
		spawnNewAnt(Ant::Violet);
	}

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();

	//Calls update for all ants
	for (auto* ant : m_ants)
	{
		ant->update(deltaTime);
	}

	//Spawns food after a timer has elapsed
	m_foodTimer += deltaTime;
	if (m_foodTimer > m_foodSpawnTime)
	{
		m_foodTimer -= m_foodSpawnTime;
		spawnFood();
	}
	int num_ants = m_ants.size();
	if (num_ants <= 26) { m_foodSpawnTime = (-(num_ants*0.05f) + 1.5f); }
	else { m_foodSpawnTime = 0.2f; }
	updateFood();

	m_spider->update(deltaTime);
}

void AntDemoApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
		if (m_renderPathfinder)
	{
		m_pathfinder.debugRender(m_2dRenderer);
		if (m_selectedPathfindNode)
		{
			m_2dRenderer->setRenderColour(0.0f, 1.0f, 1.0f, 1.0f);
			m_2dRenderer->drawCircle(m_selectedPathfindNode->position.x,
				m_selectedPathfindNode->position.y, 13);
		}
	}
		if (!m_removeWeb) { m_2dRenderer->drawSprite(m_spiderWebTexture, 0, 0, 0, 0, 0, 0, 0, 0); }
		
	for (auto* nest : m_nests)
	{
		nest->render(m_2dRenderer);
	}
	for (auto* ant : m_ants)
	{
		Vector2 antpos = ant->getPosition();

		if (!(antpos.distance(greenNestPos) < 5 || antpos.distance(violNestPos) < 5))
		{
			ant->render(m_2dRenderer);
		}
	}

	for (auto* food : m_food)
	{
		food->render(m_2dRenderer);
	}
	if (m_renderPathfinder) { m_spider->debugrender(m_2dRenderer); }
	else					{ m_spider->render(m_2dRenderer); }


	m_2dRenderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);
	



	


	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press 1 for green ant, 2 for violet ant and ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}

Food* AntDemoApp::findClosestFoodTo(const Vector2& location) const
{
	float closestDist = 0.0f;
	Food* closestFood = nullptr;
		for (auto* food : m_food)
		{
			auto offset			= food->getPosition() - location;
			float distanceTo = offset.magnitude();
			if (!closestFood || distanceTo < closestDist)
			{
				closestFood = food;
				closestDist = distanceTo;
			}
		}
	return closestFood;
}

Nest* AntDemoApp::getNestOfTeam(Ant::Team team)
{
	for (auto* nest : m_nests)
	{
		if (nest->getTeam() == team)
		{
			return nest;
		}
	}

	return nullptr;
}

void AntDemoApp::spawnFood()
{
	int rand1 = rand();
	int rand2 = rand();
	auto food = new Food(Vector2(rand1 % getWindowWidth(), rand2 % getWindowHeight()), m_foodTexture);
	m_food.push_back(food);
}

void AntDemoApp::updateFood()
{
	for (auto* ant : m_ants)
	{
		for (auto it = std::begin(m_food); it != std::end(m_food);)
		{
			auto* food		= *it;
			auto offset		= food->getPosition() - ant->getPosition();
			float distTo	= offset.magnitude();
			if (distTo < 10)
			{
				delete food; //replace with timer?
				it = m_food.erase(it);
				ant->holdFood();
			}
			else
			{
				++it;
			}
		}
	}
}

spider* AntDemoApp::getSpider()
{
	return m_spider;
}