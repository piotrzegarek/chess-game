#include "MainMenuState.h"

// Initialize functions
void MainMenuState::initFonts()
{
	if (!this->font.loadFromFile("Fonts/main-2.ttf"))
	{
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void MainMenuState::initKeybinds()
{
	this->keybinds.emplace("PRINT", this->supportedKeys->at("A"));
}

void MainMenuState::initButtons()
{
	this->buttons["NEW_GAME_BTN"] = new Button(100, 100, 150, 50,
		&this->font, "New Game",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

	this->buttons["EXIT_BTN"] = new Button(200, 200, 150, 50,
		&this->font, "Exit",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
}

// Constructors/Destructors
MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window,  supportedKeys, states)
{
	std::cout << "Started main menu state" << "\n";
	this->initFonts();
	this->initKeybinds();
	this->initButtons();

	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(sf::Color::Magenta);
}

MainMenuState::~MainMenuState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
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

void MainMenuState::updateButtons()
{
	/* Updates all the buttons and handle their functions. */
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}

	// Start new game
	if (this->buttons["NEW_GAME_BTN"]->isPressed())
	{
		this->states->push(new GameState(this->window, this->supportedKeys, this->states));
	}

	// Quit the game
	if (this->buttons["EXIT_BTN"]->isPressed())
	{
		this->wantsEnd = true;
	}
}

void MainMenuState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);
	this->updateButtons();
}

void MainMenuState::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);

	this->renderButtons(target);
}
