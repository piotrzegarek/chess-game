#include "Application.h"


// Initializer functions
void Application::initVariables()
{
	this->window = nullptr;
	this->fullscreen = false;
	this->dt = 0.f;
}

void Application::initWindow()
{
	/* Creates a SFML window using options from windows.init file. */

	std::ifstream cfg("Config/window.ini");

	std::string  title = "None";
	sf::VideoMode window_bounds(800, 600);
	bool fullscreen = false;
	unsigned framerate_limit = 60;
	bool vertical_sync_enabled = false;


	if (cfg.is_open())
	{
		std::getline(cfg, title);
		cfg >> window_bounds.width >> window_bounds.height;
		cfg >> fullscreen;
		cfg >> framerate_limit;
		cfg >> vertical_sync_enabled;
	}

	cfg.close();

	this->fullscreen = fullscreen;
	if (this->fullscreen)
		this->window = new sf::RenderWindow(window_bounds, title, sf::Style::Fullscreen);
	else
		this->window = new sf::RenderWindow(window_bounds, title, sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(framerate_limit);
	this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

void Application::initKeys()
{
	this->supportedKeys.emplace("Escape", sf::Keyboard::Key::Escape);
	this->supportedKeys.emplace("W", sf::Keyboard::Key::W);
	this->supportedKeys.emplace("S", sf::Keyboard::Key::S);
	this->supportedKeys.emplace("A", sf::Keyboard::Key::A);
	this->supportedKeys.emplace("D", sf::Keyboard::Key::D);
}

void Application::initStates()
{
	this->states.push(new MainMenuState(this->window, &this->supportedKeys, &this->states));
}


// Constructors/Destructors
Application::Application()
{
	this->initWindow();
	this->initKeys();
	this->initStates();
}

Application::~Application()
{
	delete this->window;

	while (!this->states.empty())
	{
		delete this->states.top();
		this->states.pop();
	}
}


// Functions
void Application::endApplication()
{
	std::cout << "Ending app" << "\n";
}

void Application::updateDt()
{
	/* Updates game datetime variable after every update and render execute */

	this->dt = this->dtClock.restart().asSeconds();
}

void Application::updateSFMLEvents()
{
	/* Handle SFML window events. */
	while (this->window->pollEvent(this->sfEvent))
	{
		if (this->sfEvent.type == sf::Event::Closed)
			this->window->close();
	}
}

void Application::update()
{
	/* Handle all appliaction events and update active app state. */
	this->updateSFMLEvents();
	if (!this->states.empty())
	{
		this->states.top()->update(this->dt);

		if (this->states.top()->getQuit())
		{
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}
	}
	// Application exit
	else
	{
		this->endApplication();
		this->window->close();
	}
}

void Application::render()
{
	/* Render the top (active) state data. */
	this->window->clear();

	// Render items
	if (!this->states.empty())
		this->states.top()->render(this->window);

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
