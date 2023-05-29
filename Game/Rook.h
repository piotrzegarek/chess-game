#pragma once
#include "Figure.h"

class Rook :
    public Figure
{
private:


public:
    Rook();
    Rook(std::string color);
    ~Rook();

    // Initializer functions
    void initTexture();

    // Functions
    void move();
    void remove();
    std::vector<std::string> availableMoves(std::string key);
};

