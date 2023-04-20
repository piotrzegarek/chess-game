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
    void availableMoves();
};
