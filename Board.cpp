#include "Board.h"

// Initializer functions

void Board::initBackground()
{
	// Render 8x8 squares
	boardWindow.create(square_size*8, square_size*8);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)
		{
			sf::RectangleShape square;
			square.setSize(sf::Vector2f(square_size, square_size));
			square.setFillColor((i + j) % 2 == 0 ? white_square_color : black_square_color);
			square.setPosition(
				static_cast<float>(j) * square_size,
				static_cast<float>(i) * square_size
			);

			this->boardWindow.draw(square);
			this->boardWindow.display();
		}
	}
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

}

void Board::render(sf::RenderTarget* target, float window_x, float window_y)
{
	sf::Sprite board;
	board.setPosition(window_x / 2.f, 200);
	board.setTexture(this->boardWindow.getTexture());
	target->draw(board);
}
