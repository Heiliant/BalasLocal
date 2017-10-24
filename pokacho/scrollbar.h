#pragma once
#include <SFML\Graphics.hpp>



class scrollbar
{
public:

	enum class type {
		vertical, horizontal
	};

	scrollbar(scrollbar::type tipo, sf::RenderWindow &window);
	~scrollbar();
	
private:
	sf::RectangleShape limitBox;
	sf::RectangleShape box;

	sf::RenderWindow &myWindow;

	type tipo;

	bool clickedIn = false;

public:
	void setPosition(sf::Vector2f newPos);
	bool isClicked(); //return wether the dropdown has been clicked or not. It'll return true even if the mouse is not on the button but the mouse has not released the button yet
	bool mouseWithin();

	void update();
	void draw();
};

