#ifndef BOARD_H
#define BOARD_H

#include "Button.h"

class Board
{
private:
    // Variables
    sf::Sprite boardWindow;
    sf::RenderTexture boardTexture;
    sf::Vector2f mousePosBoard;

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

    sf::Color white_square_color = sf::Color(238, 238, 211);
    sf::Color black_square_color = sf::Color(118, 150, 86);

    //Functions
    void initBackground();

public:
    // Constructors/Destructors
    Board(float x, float y);
    ~Board();

    // Functions
    void update(const sf::Vector2f mousePos);
    void updateMousePos(const sf::Vector2f mousePos);
    void updateBoardSquare();
    void render(sf::RenderTarget* target, float window_x, float window_y);
};

#endif GAMESTATE_H