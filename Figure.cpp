#include "Figure.h"

// Constructors/Destructors

Figure::Figure(std::string color, std::string position)
{
	this->color = color;
	this->position = position;
}

Figure::~Figure()
{
}

void Figure::render(sf::RenderTexture* target, sf::Vector2f indexPosition)
{
	this->figure.setScale(
		this->figure_size / this->figure.getLocalBounds().width,
		this->figure_size / this->figure.getLocalBounds().height
	);
	std::cout << indexPosition.x << " " << indexPosition.y << "\n";
	this->figure.setPosition(indexPosition);
	target->draw(this->figure);
}

void Figure::update()
{

}
