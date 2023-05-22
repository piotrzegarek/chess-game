#include "Rook.h"

Rook::Rook()
{

}

Rook::Rook(std::string color)
	: Figure(color)
{
	this->initTexture();
	this->type = "rook";
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

std::vector<std::string> Rook::availableMoves(std::string key)
{
	char col = key[0];
	int row = int(key[1] - '0');
	std::vector <std::string> moves;
	std::string move = "";

	for (int i = 1; i < 9; ++i) {
		move = col;
		move += std::to_string(i);
		moves.push_back(move);
	}

	std::vector<std::string> columns = { "a", "b", "c", "d", "e", "f", "g", "h" };
	for (size_t i = 0; i < columns.size(); i++) {
		move = columns[i];
		move += std::to_string(row);
		moves.push_back(move);
	}

	return moves;
}
