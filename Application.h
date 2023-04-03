#ifndef GAME_H
#define GAME_H

#include "GameState.h"


class Application
{
private:
	// Variables
	sf::RenderWindow *window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;

	// Initializer functions
	void initWindow();
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

