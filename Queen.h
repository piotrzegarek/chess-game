#pragma once
#include "Figure.h"

class Queen :
    public Figure
{
private:


public:
    Queen();
    Queen(std::string color, std::string position);
    ~Queen();

    // Initializer functions
    void initTexture();

    // Functions
    void move();
    void remove();
    void availableMoves();
};

