#include "FigureFactory.h"


std::unique_ptr<Figure> FigureFactory::createFigure(std::string color, std::string type)
{
	if (type == "rook")
	{
		return std::move(std::make_unique<Rook>(color));
	}
	else if (type == "knight")
	{
		return std::move(std::make_unique<Knight>(color));
	}
	else if (type == "bishop")
	{
		return std::move(std::make_unique<Bishop>(color));
	}
	else if (type == "queen")
	{
		return std::move(std::make_unique<Queen>(color));
	}
	else if (type == "king")
	{
		return std::move(std::make_unique<King>(color));
	}
	else
	{
		return std::move(std::make_unique<Pawn>(color));
	}


	return std::unique_ptr<Figure>();
}
