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

std::vector<std::string> Knight::availableMoves(std::string key)
{
	std::vector <std::string> moves;
	char col = key[0];
	int row = int(key[1] - '0');

	std::vector<int> currentIndexes = this->getPositionIndexes(col, row);
	int col_index = currentIndexes[0];
	int row_index = currentIndexes[1];

	if (row_index - 2 >= 0) {
		if (col_index - 2 >= 0) {
			moves.push_back(this->calculatePosition(col_index, -2, row_index, -1));
			moves.push_back(this->calculatePosition(col_index, -1, row_index, -2));
		}
		else if (col_index - 1 >= 0) {
			moves.push_back(this->calculatePosition(col_index, -1, row_index, -2));
		}

		if (col_index + 2 <= 7) {
			moves.push_back(this->calculatePosition(col_index, 2, row_index, -1));
			moves.push_back(this->calculatePosition(col_index, 1, row_index, -2));
		}
		else if (col_index + 1 <= 7) {
			moves.push_back(this->calculatePosition(col_index, 1, row_index, -2));
		}
	}
	else if (row_index - 1 >= 0) {
		if (col_index - 2 >= 0) {
			moves.push_back(this->calculatePosition(col_index, -2, row_index, -1));
		}
		if (col_index + 2 <= 7) {
			moves.push_back(this->calculatePosition(col_index, 2, row_index, -1));
		}
	}

	if (row_index + 2 <= 7) {
		if (col_index - 2 >= 0) {
			moves.push_back(this->calculatePosition(col_index, -2, row_index, 1));
			moves.push_back(this->calculatePosition(col_index, -1, row_index, 2));
		}
		else if (col_index - 1 >= 0) {
			moves.push_back(this->calculatePosition(col_index, -1, row_index, 2));
		}

		if (col_index + 2 <= 7) {
			moves.push_back(this->calculatePosition(col_index, 2, row_index, 1));
			moves.push_back(this->calculatePosition(col_index, 1, row_index, 2));
		}
		else if (col_index + 1 <= 7) {
			moves.push_back(this->calculatePosition(col_index, 1, row_index, 2));
		}
	}
	else if (row_index + 1 <= 7) {
		if (col_index - 2 >= 0) {
			moves.push_back(this->calculatePosition(col_index, -2, row_index, 1));
		}
		if (col_index + 2 <= 7) {
			moves.push_back(this->calculatePosition(col_index, 2, row_index, 1));
		}
	}

	return moves;
}

std::vector<int> Knight::getPositionIndexes(char col, int row) {
	std::vector <int> rows = { 1, 2, 3, 4, 5, 6, 7, 8 };
	std::vector <char> cols = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
	std::vector <int> indexes;
	int row_index = -1;
	int col_index = -1;

	auto col_it = find(cols.begin(), cols.end(), col);
	if (col_it != cols.end())
	{
		col_index = col_it - cols.begin();
	}
	indexes.push_back(col_index);

	auto row_it = find(rows.begin(), rows.end(), row);
	if (row_it != rows.end())
	{
		row_index = row_it - rows.begin();
	}
	indexes.push_back(row_index);

	return indexes;
}

std::string Knight::calculatePosition(int col_pos, int col_move, int row_pos, int row_move) {
	std::vector <int> rows = { 1, 2, 3, 4, 5, 6, 7, 8 };
	std::vector <char> cols = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
	std::string move = "";
	char calculated_col = cols[col_pos + col_move];
	int calculated_row = rows[row_pos + row_move];

	move = calculated_col;
	move += std::to_string(calculated_row);

	return move;
}