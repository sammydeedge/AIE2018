#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include <Windows.h>
#include <vector>

//Struct containing all infor for sprites
struct Entity {
	float x = 0, y = 0;
	float rotation = 0;
	float speed = 0;
	float r = 0, g = 0, b = 0;
	float size = 1;
};

class EntityDisplayApp : public aie::Application {
public:

	EntityDisplayApp();
	virtual ~EntityDisplayApp();

	virtual bool startup();					//Contains all procedures run when the program intialises
	virtual void shutdown();				//Contains all procedures for delete information when the program ends

	virtual void update(float deltaTime);	//Updates the information used by the application
	virtual void draw();					//Renders sprites using information from update

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;

	// an array of an unknown number of entities
	std::vector<Entity> m_entities;
	//The following three are intialised in startup, deleted in shutdown
	HANDLE m_EntityFileHandle;				//File handle for entity information file
	HANDLE m_numEntitiesHandle;				//File handle for number of entities file
	Entity* m_EntityFilePtr;				//Points to the file holding information about entities, is checked repeatedly in update
	int* m_numEntityPtr;					//Points to file holding the number of entities
	
};