#include "GameState.h"

// Initialize functions
void GameState::initKeybinds()
{
	this->keybinds.emplace("PRINT", this->supportedKeys->at("A"));

}

void GameState::initBackground()
{
	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	if (!this->bgTexture.loadFromFile("Resources/Images/background.png"))
	{
		throw"ERROR::MAINMENUSTATE::FAILED_TO_GET_BACKGROUND_TEXTURE";
	}

	this->background.setTexture(&this->bgTexture);
}

// Constructors/Destructors
GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	this->initBackground();
	this->initFonts();
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
	// Update player input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("PRINT"))))
		std::cout << "A pressed in a Game State" << "\n";

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		this->wantsEnd = true;
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
