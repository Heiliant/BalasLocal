#include <SFML\Graphics.hpp>
#include <iostream>
/*
using swindow = sf::RenderWindow;
using srect = sf::RectangleShape;
using stexture = sf::Texture;


class button {
private:
	stexture active;
	stexture unactive;
	sf::Text content;
	srect wireframe;

	float x;
	float y;

public:
	button(stexture &regular, stexture &used, sf::String whatSays, sf::Font &fuente, float width, float height, float posX, float posY){
		active = regular;
		unactive = used;

		x = posX;
		y = posY;

		wireframe.setSize(sf::Vector2f(width, height));
		wireframe.setOrigin(wireframe.getLocalBounds().width / 2, wireframe.getLocalBounds().height / 2);
		wireframe.setTexture(&active);
		wireframe.setPosition(x, y);

		content.setFont(fuente);
		content.setString(whatSays);
		content.setCharacterSize(wireframe.getSize().x / (whatSays.getSize()));
		content.setOrigin(content.getLocalBounds().width/2, content.getLocalBounds().height*2/3);
		content.setFillColor(sf::Color::Black);
		content.setPosition(posX, posY);	
		content.setStyle(sf::Text::Style::Regular);
		
	}

	void display(swindow &window) {
		window.draw(wireframe);
		window.draw(content);
	}
};


void button()
{
	swindow window(sf::VideoMode(960, 680), "Go!", sf::Style::Close | sf::Style::Titlebar);
	window.setFramerateLimit(60);

	stexture button1, button2;
	button1.loadFromFile("Assets/sprites/boton.png");
	button2.loadFromFile("Assets/sprites/boton2.png");

	sf::Font arial;
	arial.loadFromFile("Assets/fuentes/arial.ttf");
	
	sf::Text proba;
	proba.setFont(arial);
	proba.setString("probando");
	proba.setCharacterSize(20);
	proba.setFillColor(sf::Color::Blue);
	proba.setPosition(window.getPosition().x/2, window.getPosition().y/2);
	proba.setStyle(sf::Text::Style::Regular);

	button play(button1, button2, "play", arial, 100.0f, 35.0f, static_cast<float>(window.getSize().x/2), static_cast<float>(window.getSize().y/2));

	while(window.isOpen()) {
		sf::Event evnt;
		while (window.pollEvent(evnt)) {
			if (evnt.type == evnt.Closed)
				window.close();
		}

		//rect.setPosition(window.getSize().x/2, window.getSize().y/2);

		window.clear();
		window.draw(proba);
		play.display(window);
		//window.draw(play.getString());
		window.display();
	} 
}

*/