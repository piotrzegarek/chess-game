#include "Board.h"

// Initializer functions

void Board::initBackground()
{
	// Render 8x8 squares
	boardTexture.create(square_size*8, square_size*8);
	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 8; col++)
		{
			sf::RectangleShape square;
			square.setSize(sf::Vector2f(square_size, square_size));
			square.setFillColor((row + col) % 2 == 0 ? white_square_color : black_square_color);
			square.setPosition(
				static_cast<float>(col) * square_size,
				static_cast<float>(row) * square_size
			);

			std::string key = this->boardKeys[row][col];
			sf::Vector2f centerOfSquare(
				(static_cast<float>(col) * square_size) + (square_size / 2),
				(static_cast<float>(row) * square_size) + (square_size / 2)
			);
			this->boardIndexes.insert(std::map<std::string, sf::Vector2f>::value_type(key, centerOfSquare));
			this->boardTexture.draw(square);
			this->boardTexture.display();
		}
	}
	boardTexture.setSmooth(true);
}

// Constructors/Destructors

Board::Board(float x, float y)
{
	std::cout << "Creating board object" << "\n";
	initBackground();
}

Board::~Board()
{

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
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && 
		this->mousePosBoard.x >= 0 && this->mousePosBoard.x <= this->square_size * 8 &&
		this->mousePosBoard.y >= 0 && this->mousePosBoard.y <= this->square_size * 8)
	{
		std::cout << "Clicked mouse" << "\n";
	}
}

void Board::render(sf::RenderTarget* target, float window_x, float window_y)
{
	this->boardWindow.setPosition((window_x / 2.f) - 4 * square_size, window_y / 6.f);
	this->boardWindow.setTexture(this->boardTexture.getTexture());
	target->draw(this->boardWindow);
}
