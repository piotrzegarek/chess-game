#ifndef BOARD_H
#define BOARD_H

#include "Button.h"

class Board
{
private:
    // Variables
    sf::RenderTexture boardWindow;
    int square_size = 64;

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
    void render(sf::RenderTarget* target, float window_x, float window_y);
};

#endif GAMESTATE_H