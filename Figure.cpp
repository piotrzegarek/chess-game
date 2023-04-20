#include "Figure.h"

// Constructors/Destructors

Figure::Figure(std::string color)
{
	this->color = color;
}

Figure::~Figure()
{
}

std::string Figure::getColor()
{
	return this->color;
}

void Figure::render(sf::RenderTexture* target, sf::Vector2f indexPosition)
{
	this->figure.setScale(
		this->figure_size / this->figure.getLocalBounds().width,
		this->figure_size / this->figure.getLocalBounds().height
	);
	this->figure.setPosition(
		indexPosition.x + ((this->square_size - this->figure_size) / 2),
		indexPosition.y + ((this->square_size - this->figure_size) / 2)
	);
	target->draw(this->figure);
}

void Figure::renderRemoved(sf::RenderTarget* target, sf::Vector2f position)
{
	this->figure.setScale(
		this->figure_size / (this->figure.getLocalBounds().width * 1.5),
		this->figure_size / (this->figure.getLocalBounds().height * 1.5)
	);
	this->figure.setPosition(position);
	target->draw(this->figure);
}

void Figure::update()
{

}
