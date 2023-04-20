#pragma once

#include "Button.h"

class Figure
{
protected:
	int figure_size = 48;
	int square_size = 64;
	std::string color;
	std::string type;

	sf::Sprite figure;
	sf::Texture figureTexture;

public:
	Figure(std::string color="white");
	virtual ~Figure();

	// Accessors
	virtual std::string getColor();

	// Initializer functions
	virtual void initTexture() = 0;

	// Functions
	virtual void render(sf::RenderTexture* target, sf::Vector2f indexPosition);
	virtual void renderRemoved(sf::RenderTarget* target, sf::Vector2f position);
	virtual void update();

	virtual void move() = 0;
	virtual void availableMoves() = 0;
};
