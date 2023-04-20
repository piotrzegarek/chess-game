#include "Rook.h"

Rook::Rook()
{

}

Rook::Rook(std::string color)
	: Figure(color)
{
	this->initTexture();
}

Rook::~Rook()
{

}

void Rook::initTexture()
{
	// Load figure texture into sprite object variable.
	std::string image_path = (this->color == "white") ? "w_rook.png" : "b_rook.png";
	if (!this->figureTexture.loadFromFile("Resources/Figures/" + image_path))
	{
		throw"ERROR::MAINMENUSTATE::FAILED_TO_GET_BACKGROUND_TEXTURE";
	}
	this->figureTexture.setSmooth(true);
	this->figure.setTexture(this->figureTexture);
}

void Rook::move()
{
}

void Rook::remove()
{
}

void Rook::availableMoves()
{
}
