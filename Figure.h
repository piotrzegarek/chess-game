#pragma once

#include "Button.h"

class Figure
{
protected:
	int figure_size = 64;
	int square_size = 64;
	std::string color;
	std::string position; // poddana w¹tpliwoœci czy powinna tu byæ
	sf::Sprite figure;
	sf::Texture figureTexture;

public:
	Figure(std::string color="white", std::string position="a1");
	virtual ~Figure();

	// Initializer functions
	virtual void initTexture() = 0;

	// Functions
	virtual void render(sf::RenderTexture* target, sf::Vector2f indexPosition);
	virtual void update();

	virtual void move() = 0;
	virtual void remove() = 0;
	virtual void availableMoves() = 0;
};
