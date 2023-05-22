#pragma once
#include "Figure.h"

class Bishop :
    public Figure
{
private:


public:
    Bishop();
    Bishop(std::string color);
    ~Bishop();

    // Initializer functions
    void initTexture();

    // Functions
    void move();
    void remove();
    std::vector<std::string> availableMoves(std::string key);
    std::vector<int> getPositionIndexes(char col, int row);
    std::string getPositionKey(int col_pos, int row_pos);
};
