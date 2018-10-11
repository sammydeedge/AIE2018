#include "EntityDisplayApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <Windows.h>
#include <cassert>

EntityDisplayApp::EntityDisplayApp() {

}

EntityDisplayApp::~EntityDisplayApp() {

}

bool EntityDisplayApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();
	m_font = new aie::Font("./font/consolas.ttf", 32);

	setBackgroundColour(1, 1, 1);

	//Open the file that holds the number of entities
	m_numEntitiesHandle = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, L"EntityCountMemory");
	assert(m_numEntitiesHandle != nullptr);	//Make sure the file is present and has been read

	//And create a pointer that can be manipulated in other functions
	m_numEntityPtr = (int*)MapViewOfFile(m_numEntitiesHandle, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(int));

	//Resize the array to match the number of entities
	m_entities.resize(*m_numEntityPtr);

	//Open the file that holds the entity data
	m_EntityFileHandle = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, L"EntityFileMemory");
	assert(m_EntityFileHandle != nullptr); //Make sure the file is present and has been read

	//And create a pointer that can be manipulated in other functions
	m_EntityFilePtr = (Entity*)MapViewOfFile(m_EntityFileHandle, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(Entity) * *m_numEntityPtr);
	
	

	return true;
}


void EntityDisplayApp::shutdown() {

	UnmapViewOfFile(m_numEntityPtr);
	CloseHandle(m_numEntitiesHandle);
	delete m_font;
	delete m_2dRenderer;
}

void EntityDisplayApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	//Copies information of size of entity multiplied by number of entities, from file to m_entities array
	memcpy(m_entities.data(), m_EntityFilePtr, sizeof(Entity) * m_entities.size());

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void EntityDisplayApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw entities
	for (auto& entity : m_entities) {
		m_2dRenderer->setRenderColour(entity.r, entity.g, entity.b);
		m_2dRenderer->drawBox(entity.x, entity.y, entity.size, entity.size, entity.rotation);
	}
	
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}