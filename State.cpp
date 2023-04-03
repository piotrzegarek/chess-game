#include "State.h"

State::State(sf::RenderWindow* window)
{
	this->window = window;
	this->wantsEnd = false;
}

State::~State()
{

}

const bool& State::getQuit() const
{
	return this->wantsEnd;
}

void State::checkForQuit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		this->wantsEnd = true;
	}
}
