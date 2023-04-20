#pragma once
#include "Figure.h"

class Rook :
    public Figure
{
private:


public:
    Rook();
    Rook(std::string color, std::string position);
    ~Rook();

    // Initializer functions
    void initTexture();

    // Functions
    void move();
    void remove();
    void availableMoves();
};

