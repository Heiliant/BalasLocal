#include "scrollbar.h"
#include <iostream>


scrollbar::scrollbar(type tipo, sf::RenderWindow &window) : myWindow{ window }
{
	this->tipo = tipo;

	limitBox.setFillColor(sf::Color(100, 100, 100, 255));
	box.setFillColor(sf::Color(230, 230, 230, 255));
	
	switch (tipo) {
	case type::horizontal:
		limitBox.setSize(sf::Vector2f(myWindow.getSize().x, 20));
		box.setSize(sf::Vector2f(100, 20));

		this->setPosition(sf::Vector2f(0, myWindow.getSize().y - 10));
		break;
	case type::vertical:
		limitBox.setSize(sf::Vector2f(20, myWindow.getSize().y));
		box.setSize(sf::Vector2f(20, 100));

		this->setPosition(sf::Vector2f(myWindow.getSize().x - 10, 0));
		break;
	}
}


scrollbar::~scrollbar()
{
}

void scrollbar::setPosition(sf::Vector2f newPos)
{
	limitBox.setPosition(newPos);
	switch (tipo) {
	case type::horizontal:
		box.setPosition(limitBox.getPosition().x + limitBox.getLocalBounds().width / 2 - box.getLocalBounds().width / 2, limitBox.getPosition().y);
		break;
	case type::vertical:
		box.setPosition(limitBox.getPosition().x, limitBox.getPosition().y + limitBox.getLocalBounds().height / 2 - box.getLocalBounds().height / 2);
		break;
	}
}

void scrollbar::update()
{
	if (isClicked()) {
		switch (tipo) {
		case type::horizontal:
			if (sf::Mouse::getPosition(myWindow).x - box.getLocalBounds().width / 2 > 0 && sf::Mouse::getPosition(myWindow).x + box.getLocalBounds().width / 2 < myWindow.getSize().x)
				box.setPosition(sf::Mouse::getPosition(myWindow).x - box.getLocalBounds().width / 2, box.getPosition().y);
			break;
		case type::vertical:
			if (sf::Mouse::getPosition(myWindow).y - box.getLocalBounds().height / 2 > 0 && sf::Mouse::getPosition(myWindow).y + box.getLocalBounds().height / 2 < myWindow.getSize().y)
				box.setPosition(limitBox.getPosition().x, sf::Mouse::getPosition(myWindow).y - box.getLocalBounds().height / 2);
			break;
		}		
	}
}

void scrollbar::draw() {
		myWindow.draw(limitBox);
		myWindow.draw(box);
}

bool scrollbar::isClicked() {
	
	if (mouseWithin() && !clickedIn) {
		clickedIn = true;
		return (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left));
	}
	else if (clickedIn && (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))) {
		return true;
	}
	else
		clickedIn = false;
	return false;
}

bool scrollbar::mouseWithin()
{
	sf::Vector2i mouse = sf::Mouse::getPosition(myWindow);
	return (mouse.x > box.getPosition().x && mouse.x < box.getPosition().x + box.getLocalBounds().width) && (mouse.y > box.getPosition().y && mouse.y < box.getPosition().y + box.getLocalBounds().height);
}
