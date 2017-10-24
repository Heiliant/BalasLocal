#include "escena.h"
#include "scrollbar.h"
#include <iostream>

const int WIDTH = 640;
const int HEIGHT = 480;

const int VIEW_SIZE = 1000;

void resizeWindow(sf::RenderWindow &window, sf::View &view) {
	view.setSize(window.getSize().x, window.getSize().y);
}

void main() {
	sf::RenderWindow myWindow(sf::VideoMode(WIDTH, HEIGHT), "PROBANDO", sf::Style::Resize | sf::Style::Default);
	sf::Texture mySampleTexture;
	mySampleTexture.loadFromFile("Assets/sprites/witcher.jpg");
	sf::Sprite mySampleSprite;
	mySampleSprite.setTexture(mySampleTexture);

	sf::View myView(sf::Vector2f(0, 0), sf::Vector2f(myWindow.getSize().x, myWindow.getSize().y));
	myView.setCenter(WIDTH / 2, HEIGHT / 2);

	scrollbar myScrollbar(scrollbar::type::vertical, myWindow);
	//myScrollbar.setPosition(sf::Vector2f(WIDTH-10, 0));



	while (myWindow.isOpen()) {
		sf::Event evnt;
		while (myWindow.pollEvent(evnt)) {
			switch (evnt.type) {
			case sf::Event::EventType::Closed:
				myWindow.close();
				break;
			case sf::Event::EventType::Resized:
				resizeWindow(myWindow, myView);
				break;
			}
		}

		myScrollbar.update();

		myWindow.clear();
		myWindow.setView(myView);
		myWindow.draw(mySampleSprite);
		myScrollbar.draw();
		myWindow.display();
	}
}