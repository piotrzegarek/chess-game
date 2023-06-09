#pragma once

#include "Button.h"

class Figure
{
protected:
	int figure_size = 48;
	int square_size = 64;
	std::string color;
	std::string type;
	bool moving = false;

	sf::Sprite figure;
	sf::Texture figureTexture;

public:
	Figure(std::string color="white");
	virtual ~Figure();

	// Accessors
	virtual void setMoving(bool isMoving);
	virtual std::string getColor();
	virtual std::string getType();

	// Initializer functions
	virtual void initTexture() = 0;

	// Functions
	virtual void render(sf::RenderTexture* target, sf::Vector2f indexPosition, sf::Vector2f mousePosBoard);
	virtual void renderRemoved(sf::RenderTarget* target, sf::Vector2f position);
	virtual void update();

	virtual void move(sf::Vector2f mousePosition);
	virtual std::vector<std::string> availableMoves(std::string key) = 0;
};
