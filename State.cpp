#include "State.h"

State::State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys)
{
	this->window = window;
	this->wantsEnd = false;
	this->supportedKeys = supportedKeys;
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
