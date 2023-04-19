#pragma once

#include "Button.h"

class Figure
{
protected:
	std::string color;
	std::string position; // poddana w�tpliwo�ci czy powinna tu by�
	sf::Texture texture;

public:
	Figure(std::string color="white", std::string position="a1");
	virtual ~Figure();

	// Functions
	virtual void render();
	virtual void update();

	virtual void move() = 0;
	virtual void remove() = 0;
	virtual void availableMoves() = 0;
};
