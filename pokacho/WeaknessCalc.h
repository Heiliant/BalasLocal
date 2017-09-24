#include <vector>
#include <iostream>
#include <string>

enum class types
{
	acero, agua, bicho, dragon, electrico, fantasma, fuego, hada, hielo, lucha, normal, planta, psiquico, roca, tierra, siniestro, veneno, volador, none
};

class poke {
public:
	std::string name;
	types one;
	types two;
	std::vector<float> resistances = std::vector<float>(18, 1.0);

	poke();

	poke(types uno);

	poke(types uno, types dos);

	poke(std::string alias, types uno, types dos);
	//std::vector<float> resistances (18, 0). Esto da error porque el compilador empieza a leer el codigo y al ver el nombre de un tipo entiende que estoy creando un m�todo ya que estoy en una clase.
	//la sint�xis en la l�nea de arriba resulta inambigua para el compilador y no crea errores de compilaci�n.
	//otra opcion seria dejar el vector sin inicializar y que el compilador usara el constructor por defecto y que los constructores lo inicializaran, pero este caso es interesante, as� que lo dejo

	void poke::weaknessCalc(types nat, std::vector<float> &resistances);
};
