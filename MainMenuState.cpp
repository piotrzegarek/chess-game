#include "MainMenuState.h"

// Initialize functions
void MainMenuState::initKeybinds()
{
	this->keybinds.emplace("PRINT", this->supportedKeys->at("A"));
}

// Constructors/Destructors
MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys)
	: State(window,  supportedKeys)
{
	this->initKeybinds();

	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(sf::Color::Magenta);
}

MainMenuState::~MainMenuState()
{

}

// Functions
void MainMenuState::endState()
{
	std::cout << "Ending main menu state" << "\n";
}

void MainMenuState::updateInput(const float& dt)
{
	this->checkForQuit();

	// Update player input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("PRINT"))))
		std::cout << "A pressed in a Main menu" << "\n";

}

void MainMenuState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);

	system("cls");
	std::cout << this->mousePosView.x << " " << this->mousePosView.y << "\n";
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);
}
