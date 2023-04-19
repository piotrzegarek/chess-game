#pragma once
#include "Figure.h"
class Knight :
    public Figure
{
private:


public:
    Knight();
    Knight(std::string color, std::string position);
    ~Knight();

    void move();
    void remove();
    void availableMoves();
};

