#include "OptionsState.h"

// Initializer functions
void OptionsState::initBackground()
{
	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	if (!this->bgTexture.loadFromFile("Resources/Images/background.png"))
	{
		throw"ERROR::MAINMENUSTATE::FAILED_TO_GET_BACKGROUND_TEXTURE";
	}

	this->background.setTexture(&this->bgTexture);
}

void OptionsState::initKeybinds()
{
	this->keybinds.emplace("PRINT", this->supportedKeys->at("A"));
}

void OptionsState::initTexts()
{
	this->titleText.setFont(this->font);
	this->titleText.setString("Options");
	this->titleText.setFillColor(sf::Color::White);
	this->titleText.setCharacterSize(86);

	this->titleText.setPosition(
		this->window->getSize().x / 2.f - this->titleText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 8.f
	);
}

void OptionsState::initButtons()
{
	this->buttons["BACK_BTN"] = new Button(
		this->window->getSize().x / 10.f , this->window->getSize().y - this->window->getSize().y / 6.f,
		120, 50,
		&this->font, "Back", 20,
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

	this->buttons["SAVE_BTN"] = new Button(
		this->window->getSize().x - (this->window->getSize().x / 10.f + 120), this->window->getSize().y - this->window->getSize().y / 6.f,
		120, 50,
		&this->font, "Save", 20,
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

}

// Constructors/Destructors
OptionsState::OptionsState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	this->initBackground();
	this->initFonts();
	this->initKeybinds();
	this->initTexts();
	this->initButtons();
}

OptionsState::~OptionsState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}

// Functions
void OptionsState::endState()
{
	std::cout << "Ending options state" << "\n";
}

void OptionsState::updateInput(const float& dt)
{
	// Update player input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("PRINT"))))
		std::cout << "A pressed in a Main menu" << "\n";

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		this->wantsEnd = true;

}

void OptionsState::updateButtons()
{
	/* Updates all the buttons and handle their functions. */
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}

	// Quit options menu
	if (this->buttons["BACK_BTN"]->isPressed())
	{
		this->wantsEnd = true;
	}
}

void OptionsState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);
	this->updateButtons();
}

void OptionsState::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void OptionsState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);
	target->draw(this->titleText);

	this->renderButtons(target);
}

