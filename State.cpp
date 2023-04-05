#include "State.h"

// Initializer functions
void State::initFonts()
{
	if (!this->font.loadFromFile("Fonts/main-2.ttf"))
	{
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

// Constructors/Destructors
State::State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
{
	this->window = window;
	this->wantsEnd = false;
	this->supportedKeys = supportedKeys;
	this->states = states;
}

State::~State()
{

}

// Functions
const bool& State::getQuit() const
{
	return this->wantsEnd;
}

void State::updateMousePositions()
{
	/* Update mouse position variables */
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}
