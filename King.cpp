#include "King.h"

King::King()
{

}

King::King(std::string color)
	: Figure(color)
{
	this->initTexture();
}

King::~King()
{

}

void King::initTexture()
{
	// Load figure texture into sprite object variable.
	std::string image_path = (this->color == "white") ? "w_king.png" : "b_king.png";
	if (!this->figureTexture.loadFromFile("Resources/Figures/" + image_path))
	{
		throw"ERROR::MAINMENUSTATE::FAILED_TO_GET_BACKGROUND_TEXTURE";
	}
	this->figureTexture.setSmooth(true);
	this->figure.setTexture(this->figureTexture);
}

void King::move()
{
}

void King::remove()
{
}

void King::availableMoves()
{
}
