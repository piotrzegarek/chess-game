#ifndef BOARD_H
#define BOARD_H

#include "Memory.h"
#include "Button.h"
#include "Figure.h"
#include "FigureFactory.h"
#include "vector"

class Board
{
private:
    // Variables
    sf::Sprite boardWindow;
    sf::RenderTexture boardTexture;
    sf::Vector2f mousePosBoard;
    std::map<std::string, int> activeSquare = { { "x", 9}, {"y", 9}};

    int square_size = 64;
    std::string boardKeys[8][8] = {
        {"a8", "b8", "c8", "d8", "e8", "f8", "g8", "h8"},
        {"a7", "b7", "c7", "d7", "e7", "f7", "g7", "h7"},
        {"a6", "b6", "c6", "d6", "e6", "f6", "g6", "h6"},
        {"a5", "b5", "c5", "d5", "e5", "f5", "g5", "h5"},
        {"a4", "b4", "c4", "d4", "e4", "f4", "g4", "h4"},
        {"a3", "b3", "c3", "d3", "e3", "f3", "g3", "h3"},
        {"a2", "b2", "c2", "d2", "e2", "f2", "g2", "h2"},
        {"a1", "b1", "c1", "d1", "e1", "f1", "g1", "h1"}
    };
    std::map<std::string, sf::Vector2f> boardIndexes;
    std::map<std::string, std::unique_ptr<Figure>> figures;

    std::vector<std::unique_ptr<Figure>> removedBlackFigures;
    std::vector<std::unique_ptr<Figure>> removedWhiteFigures;

    sf::Color white_square_color = sf::Color(238, 238, 211);
    sf::Color black_square_color = sf::Color(118, 150, 86);
    sf::Color white_highlight_square_color = sf::Color(232, 232, 151);
    sf::Color black_highlight_square_color = sf::Color(142, 212, 72);

    bool movingFigure = false;
    sf::Clock keyTimer;
    float keyTimeMax;

    //Functions
    void initKeyTime();
    void initBackground();
    void initFigures();

public:
    // Constructors/Destructors
    Board();
    ~Board();

    //Accessors
    const bool getKeyTime();

    // Functions
    void update(const sf::Vector2f mousePos);
    void updateMousePos(const sf::Vector2f mousePos);
    void updateBoardSquare();
    void updateFigureMoving();

    void render(sf::RenderTarget* target, float window_x, float window_y);
    void renderSquare(int row, int col, bool highlight);

    std::string getActiveSquare();
    void highlightSquare(int row, int col);

    // Handling figures functions
    void renderBoard();
    void renderFigures();
    void renderRemovedFigures(sf::RenderTarget* target, float window_x, float window_y);
    void removeFigure(std::string key);
};

#endif GAMESTATE_H