#include "SpiderController.h"
#include "Agent.h"
#include "AntDemoApp.h"

//overriding update function with updates for spiders controls
void SpiderController::update(float deltaTime)
{
	if (!m_path.empty())															//If the path isn't empty:
	{
		seek(m_path.front());															//seek to the first element of m_path, first stop on the path
		if ((m_path.front() - m_user->getPosition()).magnitude() < 20)					//If user is less than 20 pixels from the first stop
		{
			m_path.pop_front();																//Remove first element from path
		}																						//(This exposes subsequent stops to be visited)
	}
	else																			//Otherwise if the path is empty
	{
		Vector2 randLocation = Vector2(	rand() % m_OwningApp->getWindowWidth(),			//Choose a random location on the screen
									rand() % m_OwningApp->getWindowHeight());
		auto* pathfinder = ((AntDemoApp*)m_OwningApp)->getPathfinder();
		auto* randomNode = pathfinder->getClosestNode(randLocation);					//Find the node closest to that location
		if (randomNode != nullptr)
		{
			auto originNode = pathfinder->getClosestNode(m_user->getPosition());		//Set the origin node to the user's position
			auto destiNode	= pathfinder->getClosestNode(randomNode->position, 100);	//Set the destination to the random location
			m_path = pathfinder->getPath( originNode, destiNode);						//Set m_path to a list of nodes forming a path from the origin to the destination
		}
	}
}

Vector2 SpiderController::getTargetLocation()
{
	return (m_path.empty()) ? m_user->getPosition() : m_path.back();
}