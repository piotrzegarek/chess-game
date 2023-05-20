#include "Board.h"

// Initializer functions

void Board::initKeyTime()
{
	// Initialize key timer for handling key inputs
	this->keyTimeMax = 0.3f;
	this->keyTimer.restart();
}

void Board::initBackground()
{
	// Render 8x8 squares board
	boardTexture.create(square_size*8, square_size*8);
	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 8; col++)
		{
			std::string key = this->boardKeys[row][col];
			sf::Vector2f centerOfSquare(
				(static_cast<float>(col) * square_size),
				(static_cast<float>(row) * square_size)
			);
			this->boardIndexes.insert(std::map<std::string, sf::Vector2f>::value_type(key, centerOfSquare));
		}
	}
	boardTexture.setSmooth(true);
}

void Board::initFigures()
{
	// Initialize all figures using Figure Factory
	std::map<std::string, std::pair<std::string, std::string>> start_placement = { 
		{"a1", {"white", "rook"}}, {"h1", {"white", "rook"}}, {"a8", {"black", "rook"}}, {"h8", {"black", "rook"}},
		{"b1", {"white", "knight"}}, {"g1", {"white", "knight"}}, {"b8", {"black", "knight"}}, {"g8", {"black", "knight"}},
		{"c1", {"white", "bishop"}}, {"f1", {"white", "bishop"}}, {"c8", {"black", "bishop"}}, {"f8", {"black", "bishop"}},
		{"e1", {"white", "king"}}, {"e8", {"black", "king"}}, {"d1", {"white", "queen"}}, {"d8", {"black", "queen"}},
	};
	FigureFactory factory;

	auto it = start_placement.begin();
	for (it = start_placement.begin(); it != start_placement.end(); ++it)	// Loop for initializing main figures
	{
		std::unique_ptr<Figure> figure = std::move(factory.createFigure(it->second.first, it->second.second));
		this->figures.emplace(std::make_pair(it->first, std::move(figure)));
	}
	for (char a = 'a'; a < 'a' + 8; ++a)	// Loop for initializing all pawns
	{
		std::string char_position(1, a);
		std::string white_position = char_position + "2";
		std::unique_ptr<Figure> white_pawn = std::move(factory.createFigure("white", "pawn"));
		this->figures.emplace(std::make_pair(white_position, std::move(white_pawn)));
		
		std::string black_position = char_position + "7";
		std::unique_ptr<Figure> black_pawn = std::move(factory.createFigure("black", "pawn"));
		this->figures.emplace(std::make_pair(black_position, std::move(black_pawn)));
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
	// Get true if key timer is above max key time
	if (this->keyTimer.getElapsedTime().asSeconds() >= this->keyTimeMax)
	{
		this->keyTimer.restart();
		return true;
	}

	return false;
}

// Update Functions

void Board::update(const sf::Vector2f mousePos)
{
	// Check for new inputs on the board
	this->updateMousePos(mousePos);
	this->updateBoardSquare();
	this->updateFigureMoving();
}

void Board::updateMousePos(const sf::Vector2f mousePos)
{
	// Update mouse position on the board
	sf::Vector2f sprite_position = this->boardWindow.getPosition();
	this->mousePosBoard.x = mousePos.x - sprite_position.x;
	this->mousePosBoard.y = mousePos.y - sprite_position.y;
}

void Board::updateBoardSquare()
{
	// Handle board mouse inputs
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

void Board::updateFigureMoving()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && 
		this->mousePosBoard.x >= 0 && this->mousePosBoard.x <= this->square_size * 8 &&
		this->mousePosBoard.y >= 0 && this->mousePosBoard.y <= this->square_size * 8)
	{
		int col = this->mousePosBoard.x / this->square_size;
		int row = this->mousePosBoard.y / this->square_size;
		std::string key = this->boardKeys[row][col];
		if (this->figures.find(key) != this->figures.end() && this->movingFigure != true) {
			this->movingFigure = true;
			std::cout << "moving figure" << "\n";
			this->figures.at(key)->setMoving(true);
		}
	}
	if (!(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) && this->movingFigure == true) {
		std::cout << "stopped figure" << "\n";
		this->movingFigure = false;
		std::string moved_to_key = this->getActiveSquare();
		std::cout << moved_to_key << "\n";
	}
}

// Render functions

void Board::render(sf::RenderTarget* target, float window_x, float window_y)
{
	// Render board texture and figures to the board
	this->boardWindow.setPosition((window_x / 2.f) - 4 * square_size, window_y / 6.f);
	// clear board texture
	this->boardTexture.clear(sf::Color::Red);
	// render elements in the texture
	this->renderBoard();
	this->renderFigures();
	this->renderRemovedFigures(target, window_x, window_y);

	// Render texture to the window
	this->boardWindow.setTexture(this->boardTexture.getTexture());
	target->draw(this->boardWindow);
}

void Board::renderBoard() {
	// Render 8x8 squares on board
	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 8; col++)
		{
			this->renderSquare(row, col, false);
		}
	}
}

void Board::renderSquare(int row, int col, bool highlight)
{
	// Render single square for board creation
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

void Board::renderFigures()
{
	// Render all active figures in current positions
	auto it = this->figures.begin();
	for (it = this->figures.begin(); it != this->figures.end(); ++it)
	{
		std::string alphPosition = it->first;
		sf::Vector2f indexPosition = this->boardIndexes[alphPosition];
		it->second->render(&this->boardTexture, this->boardIndexes[alphPosition], mousePosBoard);
	}
}

void Board::renderRemovedFigures(sf::RenderTarget* target, float window_x, float window_y)
{
	// Render all removed figures next to the board
	for (auto it = this->removedBlackFigures.begin(); it != this->removedBlackFigures.end(); it++)
	{
		int index = std::distance(this->removedBlackFigures.begin(), it);
		sf::Vector2f position;
		if (index < 7) {
			position.x = (window_x / 2.f) + 5 * square_size + (index * 0.25 * square_size);
			position.y = (window_y / 6.f) + 0.5 * square_size;
		}
		else {
			position.x = (window_x / 2.f) + 5 * square_size + ((index - 7) * 0.25 * square_size);
			position.y = (window_y / 6.f) + square_size;
		}
		it->get()->renderRemoved(target, position);
	}
	for (auto it = this->removedWhiteFigures.begin(); it != this->removedWhiteFigures.end(); it++)
	{
		int index = std::distance(this->removedWhiteFigures.begin(), it);
		sf::Vector2f position;
		if (index < 7) {
			position.x = (window_x / 2.f) + 5 * square_size + (index * 0.25 * square_size);
			position.y = (window_y / 6.f) + 6.5 * square_size;
		}
		else {
			position.x = (window_x / 2.f) + 5 * square_size + ((index - 7) * 0.25 * square_size);
			position.y = (window_y / 6.f) + 7 * square_size;
		}
		it->get()->renderRemoved(target, position);
	}
}

// Functions

void Board::removeFigure(std::string key)
{
	// Delete figure from board map and stop rendering it on the board
	if (this->figures.at(key)->getColor() == "white")
	{
		this->removedWhiteFigures.push_back(std::move(this->figures.at(key)));
	}
	else {
		this->removedBlackFigures.push_back(std::move(this->figures.at(key)));
	}
	this->figures.erase(key);
}

std::string Board::getActiveSquare()
{
	// Get currently clicked square key
	int col = this->mousePosBoard.x / this->square_size;
	int row = this->mousePosBoard.y / this->square_size;

	std::string key = this->boardKeys[row][col];
	this->highlightSquare(row, col);

	return key;
}

void Board::highlightSquare(int row, int col)
{
	// Change square color to highlighted indicated by row and column
	if (this->activeSquare["x"] != 9)
	{
		this->renderSquare(this->activeSquare["y"], this->activeSquare["x"], false);
	}
	this->activeSquare["x"] = col;
	this->activeSquare["y"] = row;

	this->renderSquare(row, col, true);
}
