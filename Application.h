#pragma once

#include <SFML/Graphics.hpp>
#include "Application.h"
#include "Button.h"

class Application {
private:
	sf::RenderWindow window;
	sf::Event event;
	sf::VideoMode video_mode;

	sf::Texture BackgroundTexture;
	sf::Sprite background;
	sf::Vector2u TextureSize;
	sf::Vector2u WindowSize;

	sf::Font font;
	sf::Vector2f mouse_position;

	std::map<const std::string, Button> Buttons;

	void initWindow();
	void initFont();
	void handleEvents();

	void renderBackground();

public:
	Application();
	~Application();

	void update();
	void render();


	bool isRunning() const;
};

