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

std::vector<std::string> Pawn::availableMoves(std::string key)
{
	char col = key[0];
	int row = int(key[1] - '0');
	std::vector <std::string> moves;
	std::string move = "";

	if (this->color == "white") {
		if (row == 2) {
			move = col;
			move += std::to_string(row + 1);
			moves.push_back(move);
			move = col;
			move += std::to_string(row + 2);
			moves.push_back(move);
		}
		else {
			move = col;
			move += std::to_string(row + 1);
			moves.push_back(move);
		}
	}
	else {
		if (row == 7) {
			move = col;
			move += std::to_string(row - 1);
			moves.push_back(move);
			move = col;
			move += std::to_string(row - 2);
			moves.push_back(move);
		}
		else {
			move = col;
			move += std::to_string(row - 1);
			moves.push_back(move);
		}
	}

	return moves;
}
