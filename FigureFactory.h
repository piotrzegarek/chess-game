#pragma once

#include "Memory.h"
#include "Figure.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "King.h"
#include "Queen.h"
#include "Pawn.h"

class FigureFactory
{
public:
	std::unique_ptr<Figure> createFigure(std::string position, std::string color, std::string type);
};

