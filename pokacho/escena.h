#pragma once
#include <SFML\Graphics.hpp>
class escena
{
public:
	escena(sf::Vector2f center, sf::Vector2f size);
	~escena();

private:
	sf::View myView;
};

