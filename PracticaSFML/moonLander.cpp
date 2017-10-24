#include "moonLander.h"

const sf::Color fondo = sf::Color::Black;
const sf::Color chasis = sf::Color::White;
const int _WIDTH = 980;
const int _HEIGHT = 460;

ship::ship(float weight, float size) : mass{ weight } {
	x = y = deg = 0;

	thrust = -15;

	body = sf::RectangleShape(sf::Vector2f(size, size));
	body.setFillColor(fondo);
	body.setOutlineThickness(1.0f);
	body.setOutlineColor(chasis);
	body.setOrigin(body.getLocalBounds().width / 2, body.getLocalBounds().height / 2);
	
	body.setPosition(_WIDTH / 2, _HEIGHT / 2);

	sf::Vector2f corr(1.f, 0);

	gas.setPointCount(3);
	gas.setOrigin(0, 0);
	gas.setPoint(2, body.getPoint(3)+corr - body.getOrigin());
	gas.setPoint(1, body.getPoint(2)+corr - body.getOrigin());
	gas.setPoint(0, sf::Vector2f((gas.getPoint(1).x+gas.getPoint(2).x )/2, gas.getPoint(2).y-thrust));
	gas.setFillColor(fondo);
	gas.setOutlineThickness(1.0f);
	gas.setOutlineColor(chasis);
	
	gas.setPosition(_WIDTH / 2, _HEIGHT / 2);
}

void ship::incThrust() {
	if (thrust > -60)
		thrust-=2;
	reGas();
}

void ship::decThrust() {
	if (thrust < -15)
		thrust+=2;
	reGas();
}

void ship::reGas() {
	gas.setPoint(0, sf::Vector2f((gas.getPoint(1).x + gas.getPoint(2).x) / 2, gas.getPoint(2).y - thrust));
}

void accelerate() {

}

void main() {
	ship nave(100.f, 50);

	sf::RenderWindow window(sf::VideoMode(_WIDTH, _HEIGHT), "To the moon", sf::Style::Default);

	while (window.isOpen()) {
		sf::Event evnt;
		while (window.pollEvent(evnt)) {
			switch (evnt.type) {
			case sf::Event::EventType::Closed:
				window.close();
				break;
			case sf::Event::EventType::KeyPressed:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
					nave.incThrust();
				}
				else
					nave.decThrust();
				break;
			}
		}

		window.clear(fondo);
		
		window.draw(nave.body);	
		window.draw(nave.gas);

		window.display();
	}
}