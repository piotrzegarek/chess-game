#pragma once
#include "Figure.h"

class Queen :
    public Figure
{
private:


public:
    Queen();
    Queen(std::string color);
    ~Queen();

    // Initializer functions
    void initTexture();

    // Functions
    void move();
    void remove();
    void availableMoves();
};

