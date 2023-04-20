#include "Pawn.h"

Pawn::Pawn()
{

}

Pawn::Pawn(std::string color)
	: Figure(color)
{
	this->initTexture();
}

Pawn::~Pawn()
{

}

void Pawn::initTexture()
{
	// Load figure texture into sprite object variable.
	std::string image_path = (this->color == "white") ? "w_pawn.png" : "b_pawn.png";
	if (!this->figureTexture.loadFromFile("Resources/Figures/" + image_path))
	{
		throw"ERROR::MAINMENUSTATE::FAILED_TO_GET_BACKGROUND_TEXTURE";
	}
	this->figureTexture.setSmooth(true);
	this->figure.setTexture(this->figureTexture);
}

void Pawn::move()
{
}

void Pawn::remove()
{
}

void Pawn::availableMoves()
{
}
