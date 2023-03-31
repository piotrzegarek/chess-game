#pragma once

#include <SFML/Graphics.hpp>
#include "Application.h"

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

	void initWindow();
	void handleEvents();

	void renderBackground();

public:
	Application();
	~Application();

	void update();
	void render();


	bool isRunning() const;
};

