#include "GameState.h"

// Initialize functions
void GameState::initBackground()
{
	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	if (!this->bgTexture.loadFromFile("Resources/Images/background.png"))
	{
		std::cout << "Erroer" << "\n";
		throw"ERROR::MAINMENUSTATE::FAILED_TO_GET_BACKGROUND_TEXTURE";
	}
	std::cout << "Setting background" << "\n";
	this->background.setTexture(&this->bgTexture);
}

void GameState::initKeybinds()
{
	this->keybinds.emplace("PRINT", this->supportedKeys->at("A"));

}

void GameState::initBoard()
{
	this->board = new Board(
		this->window->getSize().x, this->window->getSize().y
	);
}

// Constructors/Destructors
GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	this->initBackground();
	this->initFonts();
	this->initKeybinds();
	this->initBoard();
}

GameState::~GameState()
{
	std::cout << "Deleting board object" << "\n";
	delete this->board;
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

void GameState::updateBoard()
{
	this->board->update(this->mousePosView);
}

void GameState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);
}

void GameState::renderBoard(sf::RenderTarget* target)
{
	this->board->render(target,
		this->window->getSize().x, this->window->getSize().y
		);
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);

	this->renderBoard(target);
}
