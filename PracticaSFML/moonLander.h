#pragma once
#include <SFML/Graphics.hpp>

class ship {
public:
	float mass;
	float x;
	float y;
	float deg;
	float thrust;

	sf::RectangleShape body;
	sf::ConvexShape gas;

	void incThrust();
	void decThrust();
	void reGas();

public:
	ship(float weight, float size);
};

