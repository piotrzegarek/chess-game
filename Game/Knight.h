#pragma once
#include "Figure.h"

class Knight :
    public Figure
{
private:


public:
    Knight();
    Knight(std::string color);
    ~Knight();

    // Initializer functions
    void initTexture();

    // Functions
    void move();
    void remove();
    std::vector<std::string> availableMoves(std::string key);

    std::vector<int> getPositionIndexes(char col, int row);
    std::string calculatePosition(int col_pos, int col_move, int row_pos, int row_move);
};
