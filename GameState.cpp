#include "GameState.h"

// Initialize functions
void GameState::initKeybinds()
{
	this->keybinds.emplace("PRINT", this->supportedKeys->at("A"));

}

// Constructors/Destructors
GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	std::cout << "Started game state" << "\n";
	this->initKeybinds();
}

GameState::~GameState()
{

}


// Functions
void GameState::endState()
{
	std::cout << "Ending game state" << "\n";
}

void GameState::updateInput(const float& dt)
{
	this->checkForQuit();

	// Update player input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("PRINT"))))
		std::cout << "A pressed in a Game State" << "\n";
}

void GameState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;
}
