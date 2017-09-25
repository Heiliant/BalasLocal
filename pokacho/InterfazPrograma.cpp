#include "UI_resources.h"
#include "WeaknessCalc.h"

void pokeRenderer(std::vector<poke> team, sf::Texture art[], sf::Sprite image[], sf::Text eff[]) {
	sf::Font arial;
	arial.loadFromFile("Assets/fuentes/arial.ttf");
	for (unsigned int i = 0; i < team.size(); ++i) {
		float localY = 80.0f + 55.0f*static_cast<float>(i);

		art[i].loadFromFile(team[i].path);
		image[i].setTexture(art[i]);
		image[i].scale(sf::Vector2f(50 / image[i].getLocalBounds().width, 50 / image[i].getLocalBounds().height));
		image[i].setOrigin(image[i].getLocalBounds().width / 2, image[i].getLocalBounds().height / 2);
		image[i].setPosition(60.0f, localY);
		for (int j = 0; j < 18; ++j) {
			eff[j].setFont(arial);
			eff[j].setCharacterSize(10);
			eff[j].setString(std::to_string(team[i].resistances[j]));
			eff[j].setPosition(team[0].x[j], localY);
		}
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

	sf::RenderWindow window(sf::VideoMode(1300, 800), "pokiman", sf::Style::Default);

	button some(window);
	some.setPosition((some.getSize().x/2)*1.5f, 736.0f);
	some.text.setString("+");
	some.text.setOrigin(some.text.getLocalBounds().width / 2, some.text.getLocalBounds().height);
	some.text.setPosition(some.getPosition().x, some.getPosition().y);
	some.bestFit();

	std::vector<poke> team;
	team.push_back(poke("M-Latias", types::dragon, types::psiquico, "Assets/sprites/latias.png"));
	team.push_back(poke("Blaziken", types::fuego, types::lucha, "Assets/sprites/blaziken.png"));
	team.push_back(poke("Starmie", types::agua, types::psiquico, "Assets/sprites/starmie.png"));
	team.push_back(poke("Lycanroc-D", types::roca, types::none, "Assets/sprites/lycanroc.png"));
	team.push_back(poke("Jolteon", types::electrico, types::none, "Assets/sprites/jolteon.png"));
	team.push_back(poke("Braviary", types::volador, types::normal, "Assets/sprites/braviary.png"));
	team.push_back(poke("Cobalion", types::acero, types::lucha, "Assets/sprites/cobalion.png"));

	sf::Texture *art=new sf::Texture[team.size()];
	sf::Sprite *images=new sf::Sprite[team.size()];
	sf::Text *eff = new sf::Text[18];

	pokeRenderer(team, art, images, eff);

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
		//std::cout << rand()%100 << "  " << sf::Mouse::getPosition(window).x << std::endl;

		for (int i = 0; i < team.size(); ++i)
			window.draw(images[i]);
		window.draw(tipos);
		//window.draw(toolbar);
		some.display();
		window.display();
	}

}