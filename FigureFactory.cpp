#include "FigureFactory.h"


std::unique_ptr<Figure> FigureFactory::createFigure(std::string position, std::string color, std::string type)
{
	if (type == "rook")
	{
		return std::move(std::make_unique<Knight>());
	}
	else if (type == "knight")
	{
		return std::move(std::make_unique<Knight>(position, color));
	}
	else if (type == "bishop")
	{
		return std::move(std::make_unique<Knight>());
	}
	else if (type == "queen")
	{
		return std::move(std::make_unique<Knight>());
	}
	else if (type == "king")
	{
		return std::move(std::make_unique<Knight>());
	}
	else
	{
		return std::move(std::make_unique<Knight>());
	}


	return std::unique_ptr<Figure>();
}
