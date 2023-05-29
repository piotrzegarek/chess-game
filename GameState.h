#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"
#include "Board.h"

class GameState :
    public State
{
private:
    Board* board;
    sf::Text titleText;
    std::map<std::string, Button*> buttons;

    sf::Clock keyTimer;
    float keyTimeMax;

    //Functions
    void initBackground();
    void initButtons();
    void initKeybinds();
    void initBoard();
    void initTexts();
    void initKeyTime();

public:
    // Constructors/Destructors
    GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~GameState();

    //Accessors
    const bool getKeyTime();

    //Functions
    void endState();

    void updateInput(const float& dt);
    void updateButtons();
    void updateBoard();
    void updateText();
    void update(const float& dt);
    void renderButtons(sf::RenderTarget* target = nullptr);
    void renderBoard(sf::RenderTarget* target = nullptr);
    void render(sf::RenderTarget* target = nullptr);
};

#endif GAMESTATE_H