#include "MainMenuState.h"

// Initializer functions
void MainMenuState::initBackground()
{
	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	if (!this->bgTexture.loadFromFile("Resources/Images/background.png"))
	{
		throw"ERROR::MAINMENUSTATE::FAILED_TO_GET_BACKGROUND_TEXTURE";
	}

	this->background.setTexture(&this->bgTexture);
}

void MainMenuState::initKeybinds()
{
	this->keybinds.emplace("PRINT", this->supportedKeys->at("A"));
}

void MainMenuState::initTexts()
{
	this->titleText.setFont(this->font);
	this->titleText.setString("Play Chess");
	this->titleText.setFillColor(sf::Color::White);
	this->titleText.setCharacterSize(86);

	this->titleText.setPosition(
		this->window->getSize().x / 2.f - this->titleText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 8.f
	);
}

void MainMenuState::initButtons()
{
	this->buttons["NEW_GAME_BTN"] = new Button(
		this->window->getSize().x / 2.f - 260 / 2.f, this->window->getSize().y / 3.f,
		260, 80,
		&this->font, "New Game", 24,
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

	this->buttons["OPTIONS_BTN"] = new Button(
		this->window->getSize().x / 2.f - 260 / 2.f, this->window->getSize().y / 3.f + (80 + 20),
		260, 80,
		&this->font, "Options", 24,
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

	this->buttons["EXIT_BTN"] = new Button(
		this->window->getSize().x / 2.f - 260 / 2.f, this->window->getSize().y / 3.f + (2*80 + 40),
		260, 80,
		&this->font, "Exit", 24,
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
}

// Constructors/Destructors
MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window,  supportedKeys, states)
{
	std::cout << "Started main menu state" << "\n";
	this->initBackground();
	this->initFonts();
	this->initKeybinds();
	this->initTexts();
	this->initButtons();
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
		std::cout << "Creating game state" << "\n";
		this->states->push(new GameState(this->window, this->supportedKeys, this->states));
	}

	// Quit the game
	if (this->buttons["OPTIONS_BTN"]->isPressed())
	{
		std::cout << "Creating options state" << "\n";
		this->states->push(new OptionsState(this->window, this->supportedKeys, this->states));
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
	target->draw(this->titleText);

	this->renderButtons(target);
}
