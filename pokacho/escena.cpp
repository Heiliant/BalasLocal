#include "escena.h"



escena::escena(sf::Vector2f center, sf::Vector2f size)
{
	myView = sf::View(center, size);
}


escena::~escena()
{
}
