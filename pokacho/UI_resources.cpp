#include "UI_resources.h"

button::button(sf::RenderWindow &myWindow) : window{ myWindow } {
	sprite.loadFromFile("Assets/sprites/boton.png");
	idle = sf::Color(255, 255, 255, 255);
	pressed = sf::Color(128, 128, 128, 255);
	placeholder.setSize(sf::Vector2f(100.0f, 35.0f));
	placeholder.setFillColor(idle);
	placeholder.setTexture(&sprite);
	placeholder.setOrigin(placeholder.getLocalBounds().width / 2, placeholder.getLocalBounds().height / 2);
	font.loadFromFile("Assets/fuentes/arial.ttf");
	text.setFont(font);
	text.setString("");
	text.setFillColor(sf::Color::Black);
	text.setCharacterSize(100);
	bestFit();
	text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height * 2 / 3);
	text.setPosition(placeholder.getPosition());
}

button::button(std::string myString, sf::Texture myTexture, sf::Color myPressedColor, sf::Color myIdleColor, float posX, float posY,
	float width, float height, sf::RenderWindow &myWindow) : window{ myWindow } {
	sprite = myTexture;
	idle = myIdleColor;
	pressed = myPressedColor;
	placeholder.setSize(sf::Vector2f(width, height));
	placeholder.setFillColor(idle);
	placeholder.setTexture(&sprite);
	placeholder.setOrigin(placeholder.getLocalBounds().width / 2, placeholder.getLocalBounds().height / 2);
	font.loadFromFile("Assets/fuentes/arial.ttf");
	text.setFont(font);
	text.setString(myString);
	text.setFillColor(sf::Color::Black);
	text.setCharacterSize(100);
	bestFit();
	text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height * 2 / 3);
	setPosition(posX, posY);
}

button::button(std::string myString, float posX, float posY, sf::Texture myTexture, sf::RenderWindow &myWindow) : window{ myWindow } {
	sprite = myTexture;
	idle = sf::Color(255, 255, 255, 255);
	pressed = sf::Color(128, 128, 128, 255);
	placeholder.setSize(sf::Vector2f(100.0f, 35.0f));
	placeholder.setFillColor(idle);
	placeholder.setTexture(&sprite);
	placeholder.setOrigin(placeholder.getLocalBounds().width/ 2, placeholder.getLocalBounds().height/ 2);
	font.loadFromFile("Assets/fuentes/arial.ttf");
	text.setFont(font);
	text.setString(myString);
	text.setFillColor(sf::Color::Black);
	text.setCharacterSize(100);
	bestFit();
	text.setOrigin(text.getLocalBounds().width/2, text.getLocalBounds().height*7/8);
	setPosition(posX, posY);	
}


coord button::getPosition() { return pos; }

coord &button::setPosition() { return pos; }

void button::setPosition(sf::Vector2f newPos) { 
	pos.x = newPos.x; 
	pos.y = newPos.y; 

	placeholder.setPosition(pos.x, pos.y);
	text.setPosition(pos.x, pos.y);
}

void button::setPosition(std::pair<float, float> newPos){
	pos.x = newPos.first;
	pos.y = newPos.second;

	placeholder.setPosition(pos.x, pos.y);
	text.setPosition(pos.x, pos.y);
}

void button::setPosition(float x, float y){
	pos.x = x;
	pos.y = y;

	placeholder.setPosition(pos.x, pos.y);
	text.setPosition(pos.x, pos.y);
}


sf::Color button::getPressedColor() { return pressed; }

void button::setPressedColor(sf::Color newPressed){
	pressed = newPressed;
}


sf::Color button::getIdleColor() { return idle; }

void button::setIdleColor(sf::Color newIdle) {
	idle = newIdle;
}


void button::display(){
	window.draw(placeholder);
	window.draw(text);
}
void button::display(sf::RenderWindow &myWindow){
	myWindow.draw(placeholder);
	myWindow.draw(text);
}


void button::bestFit() {
	while ((text.getLocalBounds().height > (placeholder.getLocalBounds().height*0.95f)) || (text.getLocalBounds().width > (placeholder.getLocalBounds().width*0.95f))) {
		text.setCharacterSize(text.getCharacterSize() - 1);		
	} 
}

bool button::isPressed() {
	sf::Vector2i mouse= sf::Mouse::getPosition(window);

	if (mouse.x>placeholder.getGlobalBounds().left && mouse.x<(placeholder.getGlobalBounds().left+placeholder.getSize().x)) {
		if (mouse.y>placeholder.getGlobalBounds().top && mouse.y<(placeholder.getGlobalBounds().top + placeholder.getSize().y)) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				placeholder.setFillColor(pressed);
				return true;
			}
			else {
				placeholder.setFillColor(idle);
				return false;
			}
		}
	}
	
}


void button_test()
{
	sf::RenderWindow window(sf::VideoMode(960, 680), "WeaknessCalculator", sf::Style::Close | sf::Style::Titlebar);
	window.setFramerateLimit(60);

	sf::Texture boton;
	boton.loadFromFile("Assets/sprites/boton.png");

	button play("ALEX", window.getSize().x / 2, window.getSize().y / 2, boton, window);
	//play.setPosition(window.getSize().x/2, window.getSize().y/2);

	/*
	text.setString(myString);
	text.setFillColor(sf::Color::Blue);
	text.setCharacterSize(20);
	text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height * 2 / 3);
	text.setPosition(placeholder.getPosition());
	*/
	while (window.isOpen()) {
		sf::Event evnt;
		while (window.pollEvent(evnt)) {
			if (evnt.type == evnt.Closed)
				window.close();
		}

		play.isPressed();
		window.clear(sf::Color(255, 255, 255, 255));
		play.display();
		window.display();
	}
}

