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

	this->renderBackground();

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

void Application::renderBackground() {

	if (!this->BackgroundTexture.loadFromFile("images/background.jpg"))
	{
		return;
	}
	else
	{
		this->TextureSize = this->BackgroundTexture.getSize(); //Get size of texture.
		this->WindowSize = this->window.getSize();             //Get size of window.

		float ScaleX = (float)WindowSize.x / TextureSize.x;
		float ScaleY = (float)WindowSize.y / TextureSize.y;     //Calculate scale.

		this->background.setTexture(this->BackgroundTexture);
		this->background.setScale(ScaleX, ScaleY);      //Set scale.  
	}
	this->window.draw(this->background);
}