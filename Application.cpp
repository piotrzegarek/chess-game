#include "Application.h"

// Static functions

// Initializer functions
void Application::initWindow()
{
	/* Creates a SFML  window using options from windows.init file. */

	std::ifstream cfg("Config/window.ini");

	std::string  title = "None";
	sf::VideoMode window_bounds(800, 600);
	unsigned framerate_limit = 60;
	bool vertical_sync_enabled = false;


	if (cfg.is_open())
	{
		std::getline(cfg, title);
		cfg >> window_bounds.width >> window_bounds.height;
		cfg >> framerate_limit;
		cfg >> vertical_sync_enabled;
	}

	cfg.close();

	this->window = new sf::RenderWindow(window_bounds, title);
	this->window->setFramerateLimit(framerate_limit);
	this->window->setVerticalSyncEnabled(vertical_sync_enabled);
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
