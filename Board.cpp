#include "Board.h"

// Initializer functions

void Board::initKeyTime()
{
	this->keyTimeMax = 0.3f;
	this->keyTimer.restart();
}

void Board::initBackground()
{
	// Render 8x8 squares
	boardTexture.create(square_size*8, square_size*8);
	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 8; col++)
		{
			this->renderSquare(row, col, false);
			std::string key = this->boardKeys[row][col];
			sf::Vector2f centerOfSquare(
				(static_cast<float>(col) * square_size) + (square_size / 2),
				(static_cast<float>(row) * square_size) + (square_size / 2)
			);
			this->boardIndexes.insert(std::map<std::string, sf::Vector2f>::value_type(key, centerOfSquare));
		}
	}
	boardTexture.setSmooth(true);
}

void Board::initFigures()
{
	std::map<std::string, std::pair<std::string, std::string>> start_placement = {
		{"a1", {"white", "rook"}}, {"b1", {"white", "knight"}}, {"c1", {"white", "bishop"}}, {"d1", {"white", "queen"}},
	    //{"e1", "white_king"}, {"f1", "white_bishop"}, {"g1", "white_knight"}, {"h1", "white_rook"},
	};
	FigureFactory factory;

	auto it = start_placement.begin();
	for (it = start_placement.begin(); it != start_placement.end(); ++it)
	{
		std::unique_ptr<Figure> figure = std::move(factory.createFigure(it->first, it->second.first, it->second.second));
		this->figures.emplace(std::make_pair(it->first, std::move(figure)));
	}
}

// Constructors/Destructors

Board::Board()
{
	std::cout << "Creating board object" << "\n";
	this->initKeyTime();
	this->initBackground();
	this->initFigures();
}

Board::~Board()
{

}

const bool Board::getKeyTime()
{
	if (this->keyTimer.getElapsedTime().asSeconds() >= this->keyTimeMax)
	{
		this->keyTimer.restart();
		return true;
	}

	return false;
}

// Functions

void Board::update(const sf::Vector2f mousePos)
{
	this->updateMousePos(mousePos);
	this->updateBoardSquare();
}

void Board::updateMousePos(const sf::Vector2f mousePos)
{
	sf::Vector2f sprite_position = this->boardWindow.getPosition();
	this->mousePosBoard.x = mousePos.x - sprite_position.x;
	this->mousePosBoard.y = mousePos.y - sprite_position.y;
}

void Board::updateBoardSquare()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && this->getKeyTime() &&
		this->mousePosBoard.x >= 0 && this->mousePosBoard.x <= this->square_size * 8 &&
		this->mousePosBoard.y >= 0 && this->mousePosBoard.y <= this->square_size * 8)
	{
		std::string key = this->getActiveSquare();

	}
	else if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) &&
		!(this->mousePosBoard.x >= 0 && this->mousePosBoard.x <= this->square_size * 8 &&
			this->mousePosBoard.y >= 0 && this->mousePosBoard.y <= this->square_size * 8))
	{		
		this->renderSquare(this->activeSquare["y"], this->activeSquare["x"], false);
	}
}

void Board::render(sf::RenderTarget* target, float window_x, float window_y)
{
	this->boardWindow.setPosition((window_x / 2.f) - 4 * square_size, window_y / 6.f);
	this->boardWindow.setTexture(this->boardTexture.getTexture());
	target->draw(this->boardWindow);
}

void Board::renderSquare(int row, int col, bool highlight)
{
	sf::RectangleShape square;
	square.setSize(sf::Vector2f(square_size, square_size));
	if (highlight == true)
	{
		square.setFillColor((row + col) % 2 == 0 ? white_highlight_square_color : black_highlight_square_color);
	}
	else {
		square.setFillColor((row + col) % 2 == 0 ? white_square_color : black_square_color);
	}
	square.setPosition(
		static_cast<float>(col) * square_size,
		static_cast<float>(row) * square_size
	);

	this->boardTexture.draw(square);
	this->boardTexture.display();
}

std::string Board::getActiveSquare()
{
	int col = this->mousePosBoard.x / this->square_size;
	int row = this->mousePosBoard.y / this->square_size;

	std::string key = this->boardKeys[row][col];
	std::cout << key << "\n";
	this->highlightSquare(row, col);

	return key;
}

void Board::highlightSquare(int row, int col)
{
	if (this->activeSquare["x"] != 9)
	{
		this->renderSquare(this->activeSquare["y"], this->activeSquare["x"], false);
	}
	this->activeSquare["x"] = col;
	this->activeSquare["y"] = row;

	this->renderSquare(row, col, true);
}
