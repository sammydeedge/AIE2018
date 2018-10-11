#include "Spider.h"
#include <ctime>
#include "Pathfinder.h"
#include "AIController.h"


void spider::debugrender(aie::Renderer2D* renderer)
{
	SpiderController* controls = (SpiderController*)m_controller;
	renderer->setRenderColour(1.0f, 0.5f, 0.0f);
	renderer->drawCircle(controls->getTargetLocation().x, controls->getTargetLocation().y, 20);

	renderer->setRenderColour(1.0f, 1.0f, 1.0f);
	Agent::render(renderer);
}