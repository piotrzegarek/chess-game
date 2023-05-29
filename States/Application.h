#ifndef GAME_H
#define GAME_H

#include "MainMenuState.h"

class Application
{
private:
	// Variables
	sf::RenderWindow *window;
	sf::Event sfEvent;
	bool fullscreen;

	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;

	std::map<std::string, int> supportedKeys;

	// Initializer functions
	void initVariables();
	void initWindow();
	void initKeys();
	void initStates();
	
public:
	//Constructors/Destructors
	Application();
	virtual ~Application();

	// Functions

	//Regular
	void endApplication();

	//Update
	void updateDt();
	void updateSFMLEvents();
	void update();

	//Render
	void render();

	//Core
	void run();

};

#endif

