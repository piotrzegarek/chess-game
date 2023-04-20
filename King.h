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
    void availableMoves();
};

