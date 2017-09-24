#include<SFML/Graphics.hpp>
#include<iostream>

struct coord {
	float x, y;
};

class button {
private:
	sf::Texture sprite; //el sprite del boton
	sf::Color idle;		//color del bot�n cuando no est� siendo pulsado. Blanco por defecto.
	sf::Color pressed; //color al que cambiar� el sprite del boton cuando este sea pulsado. Gris por defecto.
	sf::RectangleShape placeholder; //la caja que rellenar� el sprite del bot�n
	sf::Font font;
	sf::RenderWindow& window;

	coord pos; //coordenadas donde situaremos el boton

	//M�TODOS

	

public:

	//CONSTRUCORES

	button(sf::RenderWindow &myWindow); //constructor por defecto. Se encarga de crear un boton de 100x35 con un sprite por defecto, con arial como fuente de texto y el texto pintado en negro.

	button(std::string myString, sf::Texture myTexture, sf::Color myPressedColor, sf::Color myIdleColor, float posX, float posY,
		float width, float height, sf::RenderWindow &myWindow); //el m�s completo

	button(std::string myString, float posX, float posY, sf::Texture myTexture, sf::RenderWindow &myWindow); //el m�s escueto. Idle color(255), pressed color(128), size(100*35)


	//DESTRUCTORES

	//No necesito un destructor

	//MIEMBROS

	sf::Text text; //lo que pone en el boton. Es publico porque la clase text ya est� gestionada internamente para proporcionar los accesos necesarios al usuario.
				   //de este modo, al usar la clase button, uno podr� tocar lo referente al texto haciendo button.text


	//M�TODOS

	coord getPosition();
	coord &setPosition(); 
	void setPosition(sf::Vector2f newPos); //X, Y
	void setPosition(std::pair<float, float> newPos); //X, Y
	void setPosition(float x, float y); //X, Y

	sf::Color getPressedColor();
	void setPressedColor(sf::Color newPressed);

	sf::Color getIdleColor();
	void setIdleColor(sf::Color newIdle);
		
	void display();
	void display(sf::RenderWindow &myWindow);

	bool isPressed();

	void bestFit();
};
