#pragma once

#include "Memory.h"
#include "Knight.h"
#include "Figure.h"

class FigureFactory
{
public:
	std::unique_ptr<Figure> createFigure(std::string position, std::string color, std::string type);
};

