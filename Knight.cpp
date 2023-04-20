#include "Knight.h"

Knight::Knight()
{

}

Knight::Knight(std::string color)
	: Figure(color)
{
	this->initTexture();
}

Knight::~Knight()
{

}

void Knight::initTexture()
{
	// Load figure texture into sprite object variable.
	std::string image_path = (this->color == "white") ? "w_knight.png" : "b_knight.png";
	if (!this->figureTexture.loadFromFile("Resources/Figures/" + image_path))
	{
		throw"ERROR::MAINMENUSTATE::FAILED_TO_GET_BACKGROUND_TEXTURE";
	}
	this->figureTexture.setSmooth(true);
	this->figure.setTexture(this->figureTexture);
}

void Knight::move()
{
}

void Knight::remove()
{
}

void Knight::availableMoves()
{
}
