#include "UI_resources.h"
#include "WeaknessCalc.h"

void pokeRenderer(sf::Texture art[18], sf::Sprite image[18], std::vector<poke> team) {
	for (int i = 0; i < team.size(); ++i) {
		art[i].loadFromFile(team[i].path);
		image[i].setTexture(art[i]);
		image->scale(sf::Vector2f(110 / image->getLocalBounds().width, 110 / image->getLocalBounds().height));
		image->setOrigin(image->getLocalBounds().width/2, image->getLocalBounds().height/2);
		//image->setPosition();
	}
}

void main() {

	sf::Texture graella;
	graella.loadFromFile("Assets/sprites/tabla_tipos.png");

	sf::Sprite tipos;
	tipos.setTexture(graella);
	tipos.setPosition(70.0f, 0.0f);

	sf::RectangleShape toolbar(sf::Vector2f(1300.0f, 144.0f));
	toolbar.setPosition(0.0f, 666.0f);
	toolbar.setFillColor(sf::Color(200, 200, 200, 255));

	sf::RenderWindow window(sf::VideoMode(1300.0f, 800.0f), "pokiman", sf::Style::Default);

	button some(window);
	some.setPosition((some.getSize().x/2)*1.5f, 736.0f);
	some.text.setString("+");
	some.text.setOrigin(some.text.getLocalBounds().width / 2, some.text.getLocalBounds().height);
	some.text.setPosition(some.getPosition().x, some.getPosition().y);
	some.bestFit();

	std::vector<poke> team;
	team.push_back(poke("M-Latias", types::dragon, types::psiquico, "Assets/sprites/latias"));
	team.push_back(poke("Blaziken", types::fuego, types::lucha, "Assets/sprites/blaziken"));
	team.push_back(poke("Starmie", types::agua, types::psiquico, "Assets/sprites/starmie"));
	team.push_back(poke("Lycanroc-D", types::roca, types::none, "Assets/sprites/lycanroc"));
	team.push_back(poke("Jolteon", types::electrico, types::none, "Assets/sprites/jolteon"));
	team.push_back(poke("Braviary", types::volador, types::normal, "Assets/sprites/braviary"));
	team.push_back(poke("Cobalion", types::acero, types::lucha, "Assets/sprites/cobalion"));

	while (window.isOpen()) {


		sf::Event evnt;
		while (window.pollEvent(evnt)) {
			switch (evnt.type) {
			case (sf::Event::EventType::Closed):
					window.close();
					break;
			}
		}
		window.clear(sf::Color(255, 255, 255, 255));
		std::cout << rand()%100 << "  " << sf::Mouse::getPosition(window).x << std::endl;
		window.draw(tipos);
		window.draw(toolbar);
		some.display();
		window.display();
	}

}