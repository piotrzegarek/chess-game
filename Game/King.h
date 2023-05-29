#pragma once
#include "Figure.h"

class King :
    public Figure
{
private:


public:
    King();
    King(std::string color);
    ~King();

    // Initializer functions
    void initTexture();

    // Functions
    void move();
    void remove();
    std::vector<std::string> availableMoves(std::string key);

    std::vector<int> getPositionIndexes(char col, int row);
    std::string calculatePosition(int col_pos, int col_move, int row_pos, int row_move);
};

