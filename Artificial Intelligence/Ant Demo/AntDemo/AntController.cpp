#include "AntController.h"
#include "AntDemoApp.h"
#include "CLDR.h"
#include "Food.h"
#include "Ant.h"
#include "Nest.h"
#include "Spider.h"

class spider;

//Finite State Machine
void AntController::update(float deltaTime)
{
	switch (m_state)
	{
	case SeekFood:
		run_foodSeeking();
		break;
	case SeekNest:
		run_nestSeeking();
		break;
	case FleeSpider:
		run_spiderFlee();
		break;
	default:
		break;
	}
}

//Boolean to determine if a spider is within a specified distance
bool AntController::spiderNearby(float distance)
{
	auto* app = static_cast<AntDemoApp*>(m_OwningApp);						
	auto ant = static_cast<Ant*>(m_user);
	auto* spider = app->getSpider();

	sphere* spider_collider = new sphere(spider->getPosition(), distance);			//Creates a sphere collider of "distance" size
	sphere* ant_collider = new sphere(ant->getPosition(), 5.0f);					//Creates an ant collider

	return CLDR::overlaps(spider_collider, ant_collider);							//Checks if there is a collision between these two spheres
}

//Sets AI behaviour to find food
void AntController::run_foodSeeking()
{
	auto* app = static_cast<AntDemoApp*>(m_OwningApp);
	auto ant = static_cast<Ant*>(m_user);

	Vector2 userLocate		= ant->getPosition();		
	sphere*	user_collide	= new sphere(userLocate, 10.0f);						//Creates a temp collider
	Food* food				= app->findClosestFoodTo(userLocate);					//Holds pointer to closest food
	
	if (food)																		//If there is a closest food (false if there is no food)
	{
		Vector2 food_locate		= food->getPosition();									//Get position of the food
		seek(food_locate);																//and seek to it
	}
	else																			//If there is no food
	{
		m_state = states::SeekNest;														//Return to nest
	}

	//Transition

	if (spiderNearby(100))															//If there's a spider nearby (within 100 pixels)
	{
		m_state = states::FleeSpider;													//Flee
	}
	else if (ant->hasFood())														//Otherwise, if it's picked up food
	{
		m_state = states::SeekNest;														//Retun to nest
	}
}

//Sets AI behaviour to return to nest (after food has been collected)
void AntController::run_nestSeeking()
{
	//Set up some casts, to make code more efficient
	auto* app				= static_cast<AntDemoApp*>(m_OwningApp);
	auto ant				= static_cast<Ant*>(m_user);

	//Get location of ant and their team's nest
	Vector2 userLocate = ant->getPosition();						
	Nest* nest				= app->getNestOfTeam(ant->getTeam());
	Vector2 nest_locate		= nest->getPosition();

	//Get a pointer to the nearest food
	Food* food = app->findClosestFoodTo(userLocate);
	if (nest)									 	//If we found the nest:
	{
		seek(nest_locate);						 		//Seek to it
		if (userLocate.distance(nest_locate) < 5)		//If the distance between the ant and the nest is less than 5 (ie a collision)
		{
			ant->dropFood();					 			//the ant drops the food
			nest->AddFoodtoStockpile();			 			//the food is added to the stockpile
		}
	}

	//Transition
	if (spiderNearby(100))							//If there's a spider nearby (within 100 pixels)		
	{
		m_state = states::FleeSpider;					//Flee
	}
	else if (!ant->hasFood() && food)				//Otherwise, if it doesn't have any food any more, and there is food available
	{
		m_state = states::SeekFood;						//Seek out food
	}
	
}

void AntController::run_spiderFlee()
{
	//Casting and defining for better code efficiency
	auto* app = static_cast<AntDemoApp*>(m_OwningApp);
	auto ant = static_cast<Ant*>(m_user);
	auto spider = app->getSpider();

	//Getting location of ant, spider; node for nearest food
	Vector2 userLocate = ant->getPosition();
	Vector2 spid_locate = spider->getPosition();
	Food* food = app->findClosestFoodTo(userLocate);

	flee(spid_locate);													//Flee spider

	//Transition: Designed to "revert" to previous state
	if (!spiderNearby(170))												//If the spider is not nearby (within 170 pixels distance):
	{
		if (!ant->hasFood() && food)										//and if the ant doesn't have food, when food is available:
			{
				m_state = states::SeekFood;										//Seek out food
			}
			else if (ant->hasFood()||(!ant->hasFood() && !food))			//Otherwise if it has food, or doesn't have food, but none is available to seek out:
			{
				m_state = states::SeekNest;										//Return to nest
			}
	}
	
}