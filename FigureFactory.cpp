#include "FigureFactory.h"


std::unique_ptr<Figure> FigureFactory::createFigure(std::string position, std::string color, std::string type)
{
	if (type == "rook")
	{
		return std::move(std::make_unique<Rook>(color, position));
	}
	else if (type == "knight")
	{
		return std::move(std::make_unique<Knight>(color, position));
	}
	else if (type == "bishop")
	{
		return std::move(std::make_unique<Bishop>(color, position));
	}
	else if (type == "queen")
	{
		return std::move(std::make_unique<Queen>(color, position));
	}
	else if (type == "king")
	{
		return std::move(std::make_unique<King>(color, position));
	}
	else
	{
		return std::move(std::make_unique<Knight>());
	}


	return std::unique_ptr<Figure>();
}
