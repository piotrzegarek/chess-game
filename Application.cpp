#include "Application.h"

/* Public app funcs */

Application::Application() {
	this->initWindow();
}

Application::~Application() {

}

bool Application::isRunning() const {
	return this->window.isOpen();
}

void Application::render() {
	this->window.clear();

	this->window.display();
}

void Application::update() {
	this->handleEvents();

}


/* Private app funcs */

void Application::initWindow() {
	sf::ContextSettings context_settings;

	this->video_mode.width = 1280;
	this->video_mode.height = 720;

	this->window.create(this->video_mode, "Chees game", sf::Style::Close, context_settings);
}

void Application::handleEvents() {
	while (this->window.pollEvent(this->event)) 
	{
		if (event.type == sf::Event::Closed)
			window.close();

		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			window.close();

	}
}