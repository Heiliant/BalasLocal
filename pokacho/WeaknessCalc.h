#include <vector>
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
	std::string path;

	float x[18] = {85.0f, 145.0f, 215.0f, 280.0f, 345.0f, 410.0f, 470.0f, 530.0f, 595.0f, 660.0f, 720.0f, 785.0f, 855.0f, 915.0f, 975.0f, 1040.0f, 1110.0f, 1175.0f};
	float y;

	poke();

	poke(types uno);

	poke(types uno, types dos);

	poke(std::string alias, types uno, types dos, std::string abs);
	//std::vector<float> resistances (18, 0). Esto da error porque el compilador empieza a leer el codigo y al ver el nombre de un tipo entiende que estoy creando un m�todo ya que estoy en una clase.
	//la sint�xis en la l�nea de arriba resulta inambigua para el compilador y no crea errores de compilaci�n.
	//otra opcion seria dejar el vector sin inicializar y que el compilador usara el constructor por defecto y que los constructores lo inicializaran, pero este caso es interesante, as� que lo dejo

	void poke::weaknessCalc(types nat, std::vector<float> &resistances);
};
