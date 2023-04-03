#include "Application.h"

// Static functions

// Initializer functions
void Application::initWindow()
{
	/* Creates a SFML  window using options from windows.init file. */
	this->window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Chess Game");
}


// Constructors/Destructors
Application::Application()
{
	this->initWindow();
}

Application::~Application()
{
	delete this->window;
}


// Functions
void Application::updateSFMLEvents()
{
	/* Handle SFML window events. */
	while (this->window->pollEvent(this->sfEvent))
	{
		if (this->sfEvent.type == sf::Event::Closed)
			this->window->close();

		if (this->sfEvent.type == sf::Event::KeyPressed && this->sfEvent.key.code == sf::Keyboard::Escape)
			this->window->close();

	}
}

void Application::updateDt()
{
	/* Updates game datetime variable after every update and render execute */

	this->dt = this->dtClock.restart().asSeconds();
}

void Application::update()
{
	/* Handle all appliaction events and update app state. */
	this->updateSFMLEvents();
}

void Application::render()
{
	/* Render application window data. */
	this->window->clear();

	// Render items

	this->window->display();
}

void Application::run()
{
	/* Main application loop. */
	while (this->window->isOpen())
	{
		this->updateDt();
		this->update();
		this->render();
	}
}
