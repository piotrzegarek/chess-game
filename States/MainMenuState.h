#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "GameState.h"
#include "OptionsState.h"
#include "Button.h"

class MainMenuState :
    public State
{
private:
    // Variables
    sf::Text titleText;

    std::map<std::string, Button*> buttons;

    // Functions
    void initBackground();
    void initKeybinds();
    void initTexts();
    void initButtons();

public:
    // Constructors/Destructors
    MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~MainMenuState();

    //Functions
    void endState();

    void updateInput(const float& dt);
    void updateButtons();
    void update(const float& dt);
    void renderButtons(sf::RenderTarget* target = nullptr);
    void render(sf::RenderTarget* target = nullptr);
};

#endif // !MAINMENUSTATE_H