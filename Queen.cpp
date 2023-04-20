#include "Queen.h"

Queen::Queen()
{

}

Queen::Queen(std::string color, std::string position)
	: Figure(color, position)
{
	this->initTexture();
}

Queen::~Queen()
{

}

void Queen::initTexture()
{
	// Load figure texture into sprite object variable.
	std::string image_path = (this->color == "white") ? "w_queen.png" : "b_queen.png";
	if (!this->figureTexture.loadFromFile("Resources/Figures/" + image_path))
	{
		throw"ERROR::MAINMENUSTATE::FAILED_TO_GET_BACKGROUND_TEXTURE";
	}
	this->figureTexture.setSmooth(true);
	this->figure.setTexture(this->figureTexture);
}

void Queen::move()
{
}

void Queen::remove()
{
}

void Queen::availableMoves()
{
}
