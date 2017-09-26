#include "UI_resources.h"
#include "WeaknessCalc.h"

const float yncreas=40.0f;
const float ynitial = 70.0f;
const int imgSz=40;
const sf::Color x2(230, 92, 0, 255);
const sf::Color x4(255, 0, 255, 255);
const sf::Color x05(0, 102, 193, 255);
const sf::Color x025(0, 204, 0, 255);
const sf::Color x0(250, 250, 250, 255);

void pokeRenderer(std::vector<poke> team, sf::Texture art[], sf::Sprite image[], std::string **eff, sf::RenderWindow &window) {
	sf::Font arial;
	arial.loadFromFile("Assets/fuentes/arial.ttf");
	for (unsigned int i = 0; i < team.size(); ++i) {
		float localY = ynitial + yncreas*static_cast<float>(i);

		art[i].loadFromFile(team[i].path);
		image[i].setTexture(art[i]);
		image[i].scale(sf::Vector2f(imgSz / image[i].getLocalBounds().width, imgSz / image[i].getLocalBounds().height));
		image[i].setOrigin(image[i].getLocalBounds().width / 2, image[i].getLocalBounds().height / 2);
		image[i].setPosition(60.0f, localY);
		for (int j = 0; j < 18; ++j) {
			eff[i][j]=(std::to_string(team[i].resistances[j]));		
			eff[i][j].resize(4);
		}
	}
}

void main() {

	sf::Font arial;
	arial.loadFromFile("Assets/fuentes/arial.ttf");

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
	//team.push_back(poke("Zoroark", types::siniestro, types::none, "Assets/sprites/zoroark.png"));
	//team.push_back(poke("Whimsicott", types::planta, types::hada, "Assets/sprites/whimsicott.png"));
	//team.push_back(poke("Dusknoir", types::fantasma, types::none, "Assets/sprites/dusknoir.png"));

	sf::Texture *art=new sf::Texture[team.size()];
	sf::Sprite *images=new sf::Sprite[team.size()];
	std::string **eff = new std::string*[team.size()];
	for (int i = 0; i < team.size(); ++i)
		eff[i] = new std::string[18];

	for (int i = 0; i < team.size(); ++i) {
		team.at(i).weaknessCalc(team[i].one, team[i].resistances);
		team.at(i).weaknessCalc(team[i].two, team[i].resistances);
	}

	pokeRenderer(team, art, images, eff, window);

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


		float localY;
		for (int i = 0; i < team.size(); ++i) {
			localY = ynitial + yncreas*static_cast<float>(i);
			window.draw(images[i]);
			sf::Text num;
			num.setFont(arial);
			num.setCharacterSize(15);
				for (int j = 0; j < 18; ++j) {
					num.setString(eff[i][j]);
					if (eff[i][j] == "1.00")
						num.setFillColor(sf::Color::Black);
					else if(eff[i][j] == "2.00")
						num.setFillColor(x2);
					else if (eff[i][j] == "4.00")
						num.setFillColor(x4);
					else if (eff[i][j] == "0.50")
						num.setFillColor(x05);
					else if (eff[i][j] == "0.25")
						num.setFillColor(x025);
					else if (eff[i][j] == "0.00")
					{
						num.setFillColor(x0); 
						num.setOutlineColor(sf::Color::Black);
						num.setOutlineThickness(1);
					}
					else
						num.setFillColor(sf::Color::Black);
					num.setPosition(team[0].x[j]+60.0f, localY);
					window.draw(num);
					num.setOutlineThickness(0);
				}
			}

		for (int i = 0; i < 4; ++i) {
			localY = ynitial + yncreas*static_cast<float>(i+team.size());
			int ans=0;
			sf::Text num;
			num.setFont(arial);
			num.setCharacterSize(15);
			for (int j = -1; j < 18; ++j) {
				for (int k = 0; k < team.size(); ++k) {
					switch (i) {
					case 0: num.setFillColor(x2);
						if (j < 0) { num.setString("x2");  }
						else if (eff[k][j] == "2.00") ans++;
						break;
					case 1: num.setFillColor(x4);
						if (j < 0) { num.setString("x4");  }
						else if (eff[k][j] == "4.00") ans++;
						break;
					case 2: num.setFillColor(x05);
						if (j < 0) { num.setString("x0.5");  }
						else if (eff[k][j] == "0.50") ans++;
						break;
					case 3: num.setFillColor(x025);
						if (j < 0) { num.setString("x0.25");  }
						else if (eff[k][j] == "0.25") ans++;
						break;	
					}
					if (j >= 0) {
						num.setString(std::to_string(ans));
						num.setPosition(team[0].x[j] + 60.0f, localY);
					}
					else
						num.setPosition(team[0].x[j]+60.0f, localY);
				}
				window.draw(num);
				ans = 0;
			}
		}

		window.draw(tipos);
		//window.draw(toolbar);
		some.display();
		window.display();
	}
}