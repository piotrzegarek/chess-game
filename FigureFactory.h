#pragma once

#include "Memory.h"
#include "Figure.h"
#include "Knight.h"

class FigureFactory
{
public:
	std::unique_ptr<Figure> createFigure(std::string position, std::string color, std::string type);
};

