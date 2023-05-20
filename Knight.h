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
    void availableMoves();
};