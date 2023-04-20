#include "Bishop.h"

Bishop::Bishop()
{

}

Bishop::Bishop(std::string color, std::string position)
	: Figure(color, position)
{
	this->initTexture();
}

Bishop::~Bishop()
{

}

void Bishop::initTexture()
{
	// Load figure texture into sprite object variable.
	std::string image_path = (this->color == "white") ? "w_bishop.png" : "b_bishop.png";
	if (!this->figureTexture.loadFromFile("Resources/Figures/" + image_path))
	{
		throw"ERROR::MAINMENUSTATE::FAILED_TO_GET_BACKGROUND_TEXTURE";
	}
	this->figureTexture.setSmooth(true);
	this->figure.setTexture(this->figureTexture);
}

void Bishop::move()
{
}

void Bishop::remove()
{
}

void Bishop::availableMoves()
{
}
