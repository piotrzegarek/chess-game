#pragma once
#include "Figure.h"

class Pawn :
    public Figure
{
private:


public:
    Pawn();
    Pawn(std::string color);
    ~Pawn();

    // Initializer functions
    void initTexture();

    // Functions
    void move();
    void remove();
    std::vector<std::string> availableMoves(std::string key);
};

