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
	/* Check if escape button is pressed. */
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		this->wantsEnd = true;
	}
}

void State::updateMousePositions()
{
	/* Update mouse position variables */
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}
