#include "Board.h"

// Initializer functions

void Board::initBackground()
{
	// Render 8x8 squares
	boardTexture.create(square_size*8, square_size*8);
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
}

void Board::updateMousePos(const sf::Vector2f mousePos)
{
	sf::Vector2f sprite_position = this->boardWindow.getPosition();
	this->mousePosBoard.x = mousePos.x - sprite_position.x;
	this->mousePosBoard.y = mousePos.y - sprite_position.y;
}

void Board::render(sf::RenderTarget* target, float window_x, float window_y)
{
	this->boardWindow.setPosition((window_x / 2.f) - 4 * square_size, window_y / 6.f);
	this->boardWindow.setTexture(this->boardTexture.getTexture());
	target->draw(this->boardWindow);
}
