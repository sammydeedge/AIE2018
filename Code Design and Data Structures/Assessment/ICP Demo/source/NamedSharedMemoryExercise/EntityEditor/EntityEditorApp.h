#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include <Windows.h>
#include <vector>

//Data for sprites
struct Entity {
	float x = 0, y = 0;
	float rotation = 0;
	float speed = 0;
	float r = 0, g = 0, b = 0;
	float size = 1;
};

class EntityEditorApp : public aie::Application {
public:

	EntityEditorApp();
	virtual ~EntityEditorApp();

	virtual bool startup();					//Contains all procedures run when the program intialises
	virtual void shutdown();				//Contains all procedures run when the program ends

	virtual void update(float deltaTime);	//Updates the information used by the application
	virtual void draw();					//Renders sprites using information from update

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;

	// define a block of entities that should be shared
	enum { ENTITY_COUNT = 10 };
	//creates an array of entities
	Entity m_entities[ENTITY_COUNT];

	HANDLE m_numEntitiesHandle;		//File handle for number of entities information file
	HANDLE m_entityFileHandle;		//File handle for entity information file

	int* m_numEntityPtr;			//Pointer to file containing the number of entities
	Entity* m_EntityFilePtr;		//Pointer to file containing data about entities
};