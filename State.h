#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class State
{
private:
	// Variables
	std::vector<sf::Texture> textures;

	// Initializer functions

public:
	//Constructors/Destructors
	State();
	virtual ~State();

	//Functions
	virtual void update() = 0;
	virtual void render() = 0;
};

#endif