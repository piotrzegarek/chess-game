#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <map>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class State
{
private:
	// Variables
	sf::RenderWindow* window;
	std::vector<sf::Texture> textures;
	bool wantsEnd;

	// Initializer functions

public:
	//Constructors/Destructors
	State(sf::RenderWindow* window);
	virtual ~State();

	//Functions
	const bool& getQuit() const;
	virtual void checkForQuit();

	virtual void endState() = 0;
	virtual void updateKeybinds(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

#endif