#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
#include "Board.h"

class GameState :
    public State
{
private:
    Board* board;

    //Functions
    void initBackground();
    void initKeybinds();
    void initBoard();

public:
    // Constructors/Destructors
    GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~GameState();

    //Functions
    void endState();

    void updateInput(const float& dt);
    void updateBoard();
    void update(const float& dt);
    void renderBoard(sf::RenderTarget* target = nullptr);
    void render(sf::RenderTarget* target = nullptr);
};

#endif GAMESTATE_H