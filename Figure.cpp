#include "Figure.h"

// Constructors/Destructors

Figure::Figure(std::string color)
{
	this->color = color;
}

Figure::~Figure()
{
}

void Figure::setMoving(bool isMoving)
{
	this->moving = isMoving;
}

std::string Figure::getColor()
{
	return this->color;
}

std::string Figure::getType()
{
	return this->type;
}

void Figure::render(sf::RenderTexture* target, sf::Vector2f indexPosition, sf::Vector2f mousePosBoard)
{
	if (this->moving == false) {
		this->figure.setPosition(
			indexPosition.x + ((this->square_size - this->figure_size) / 2),
			indexPosition.y + ((this->square_size - this->figure_size) / 2)
		);
		this->figure.setScale(
			this->figure_size / this->figure.getLocalBounds().width,
			this->figure_size / this->figure.getLocalBounds().height
		);
	}
	else {
		sf::Vector2f prevPos = mousePosBoard;
		this->figure.setPosition(
			mousePosBoard.x - ((this->square_size - this->figure_size) * 1.5),
			mousePosBoard.y - ((this->square_size - this->figure_size) * 1.5)
		);
	}
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

void Figure::move(sf::Vector2f mousePosition)
{
	this->figure.move(mousePosition);
}
