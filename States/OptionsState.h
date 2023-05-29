#pragma once
#include "State.h"
#include "Button.h"


class OptionsState :
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
    OptionsState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
    virtual ~OptionsState();

    //Functions
    void endState();

    void updateInput(const float& dt);
    void updateButtons();
    void update(const float& dt);
    void renderButtons(sf::RenderTarget* target = nullptr);
    void render(sf::RenderTarget* target = nullptr);
};

