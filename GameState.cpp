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

void GameState::initButtons()
{
	// TO-DO: zmieniæ na nullptr
	this->buttons["BACK_BTN"] = new Button(
		this->window->getSize().x / 10.f, this->window->getSize().y - this->window->getSize().y / 6.f,
		120, 50,
		&this->font, "Back", 20,
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
}

void GameState::initKeybinds()
{
	this->keybinds.emplace("PRINT", this->supportedKeys->at("A"));

}

void GameState::initBoard()
{
	this->board = new Board();
}

void GameState::initTexts()
{
	this->titleText.setFont(this->font);
	this->titleText.setString("White's turn");
	this->titleText.setFillColor(sf::Color::White);
	this->titleText.setCharacterSize(26);

	this->titleText.setPosition(
		this->window->getSize().x / 2.f - this->titleText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 12.f
	);
}

void GameState::initKeyTime()
{
	this->keyTimeMax = 0.3f;
	this->keyTimer.restart();
}

// Constructors/Destructors
GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	this->initBackground();
	this->initFonts();
	this->initKeybinds();
	this->initBoard();
	this->initTexts();
	this->initKeyTime();
	this->initButtons();
}

GameState::~GameState()
{
	std::cout << "Deleting board object" << "\n";
	delete this->board;
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
}

const bool GameState::getKeyTime()
{
	if (this->keyTimer.getElapsedTime().asSeconds() >= this->keyTimeMax)
	{
		this->keyTimer.restart();
		return true;
	}

	return false;
}


// Functions
void GameState::endState()
{
	std::cout << "Ending game state" << "\n";
}

void GameState::updateInput(const float& dt)
{
	// Update player input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && this->getKeytime() || this->buttons["BACK_BTN"]->isPressed())
		this->wantsEnd = true;
}

void GameState::updateButtons()
{
	/* Updates all the buttons and handle their functions. */
	for (auto& it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}
}

void GameState::updateBoard()
{
	this->board->update(this->mousePosView);
}

void GameState::updateText() {
	std::string text = this->board->getTurn() + "'s turn";
	this->titleText.setString(text);
}

void GameState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateKeytime(dt);
	this->updateInput(dt);
	this->updateButtons();
	this->updateBoard();
	this->updateText();
}

void GameState::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
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
	this->renderButtons(target);
	target->draw(this->titleText);
}
