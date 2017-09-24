#include "WeaknessCalc.h"

//existen 18 tipos sin contar el tipo nulo o inexistene
//meteré el multiplicador de resistencia correspondiente a cada tipo en un vector, de modo que se inicialice el vector en 1 en todas sus posiciones, y después se vayan multiplicando 
//las posiciones correspondientes
	
	poke::poke() {
		one = two = types::none;
		name = "";
	}

	poke::poke(types uno) {
		one = uno;
		two = types::none;
		name = "";
	}

	poke::poke(types uno, types dos) {
		one = uno;
		two = dos;
		name = "";
	}

	poke::poke(std::string alias, types uno, types dos, std::string abs) : name{ alias }, one{ uno }, two{ dos }, path{ abs } {} //lista de inicializacion para ir practicando


	void poke::weaknessCalc(types nat, std::vector<float> &resistances) {
	if (resistances.size() != 18) {
		resistances.clear();
		resistances.shrink_to_fit();
		for (int i = 0; i < 18; ++i)
			resistances.push_back(1);
	}
	//aqui pondré los tipos que el pokemon RESISTE
	switch (nat) {
	case types::acero: {
		//RES acero bicho dragon hada hielo normal planta psiquico roca volador
		//DEB fuego lucha tierra
		//INM veneno
		resistances.at(static_cast<int>(types::acero)) *= 0.5f;
		resistances.at(static_cast<int>(types::bicho)) *= 0.5f;
		resistances.at(static_cast<int>(types::dragon)) *= 0.5f;
		resistances.at(static_cast<int>(types::hada)) *= 0.5f;
		resistances.at(static_cast<int>(types::hielo)) *= 0.5f;
		resistances.at(static_cast<int>(types::normal)) *= 0.5f;
		resistances.at(static_cast<int>(types::planta)) *= 0.5f;
		resistances.at(static_cast<int>(types::psiquico)) *= 0.5f;
		resistances.at(static_cast<int>(types::roca)) *= 0.5f;
		resistances.at(static_cast<int>(types::volador)) *= 0.5f;

		resistances.at(static_cast<int>(types::fuego)) *= 2.0f;
		resistances.at(static_cast<int>(types::lucha)) *= 2.0f;
		resistances.at(static_cast<int>(types::tierra)) *= 2.0f;

		resistances.at(static_cast<int>(types::veneno)) *= 0.0f;
		}
		break;
	case types::agua: {
		//RES acero agua fuego hielo 
		//DEB electrico planta
		resistances.at(static_cast<int>(types::acero)) *= 0.5f;
		resistances.at(static_cast<int>(types::agua)) *= 0.5f;
		resistances.at(static_cast<int>(types::fuego)) *= 0.5f;
		resistances.at(static_cast<int>(types::hielo)) *= 0.5f;

		resistances.at(static_cast<int>(types::electrico)) *= 2.0f;
		resistances.at(static_cast<int>(types::planta)) *= 2.0f;
	}
		break;
	case types::bicho: {
		//RES lucha planta tierra
 		//DEB fuego roca volador
		resistances.at(static_cast<int>(types::lucha)) *= 0.5f;
		resistances.at(static_cast<int>(types::planta)) *= 0.5f;
		resistances.at(static_cast<int>(types::tierra)) *= 0.5f;

		resistances.at(static_cast<int>(types::fuego)) *= 2.0f;
		resistances.at(static_cast<int>(types::roca)) *= 2.0f;
		resistances.at(static_cast<int>(types::volador)) *= 2.0f;
	}
		break;
	case types::dragon: {
		//RES afua electrico fuego planta
		//DEB dragon hada hielo
		resistances.at(static_cast<int>(types::agua)) *= 0.5f;
		resistances.at(static_cast<int>(types::electrico)) *= 0.5f;
		resistances.at(static_cast<int>(types::fuego)) *= 0.5f;
		resistances.at(static_cast<int>(types::planta)) *= 0.5f;

		resistances.at(static_cast<int>(types::dragon)) *= 2.0f;
		resistances.at(static_cast<int>(types::hada)) *= 2.0f;
		resistances.at(static_cast<int>(types::hielo)) *= 2.0f;
	}
		break;
	case types::electrico: {
		//RES aceri electrico volador
		//DEB tierra
		resistances.at(static_cast<int>(types::acero)) *= 0.5f;
		resistances.at(static_cast<int>(types::electrico)) *= 0.5f;
		resistances.at(static_cast<int>(types::volador)) *= 0.5f;

		resistances.at(static_cast<int>(types::tierra)) *= 2.0f;
	}
		break;
	case types::fantasma: {
		//RES bicho veneno 
		//DEB fantasma siniestro
		//INM lucha normal
		resistances.at(static_cast<int>(types::bicho)) *= 0.5f;
		resistances.at(static_cast<int>(types::veneno)) *= 0.5f;

		resistances.at(static_cast<int>(types::fantasma)) *= 2.0f;
		resistances.at(static_cast<int>(types::siniestro)) *= 2.0f;

		resistances.at(static_cast<int>(types::lucha)) *= 0.0f;
		resistances.at(static_cast<int>(types::normal)) *= 0.0f;
	}
		break;
	case types::fuego: {
		//RES acero bicho fuego hada hielo planta
		//DEB agua roca tierra
		resistances.at(static_cast<int>(types::acero)) *= 0.5f;
		resistances.at(static_cast<int>(types::bicho)) *= 0.5f;
		resistances.at(static_cast<int>(types::fuego)) *= 0.5f;
		resistances.at(static_cast<int>(types::hada)) *= 0.5f;
		resistances.at(static_cast<int>(types::hielo)) *= 0.5f;
		resistances.at(static_cast<int>(types::planta)) *= 0.5f;

		resistances.at(static_cast<int>(types::agua)) *= 2.0f;
		resistances.at(static_cast<int>(types::roca)) *= 2.0f;
		resistances.at(static_cast<int>(types::tierra)) *= 2.0f;
	}
		break;
	case types::hada: {
		//RES bicho lucha siniestro
		//DEB acero veneno
		//INM dragon
		resistances.at(static_cast<int>(types::bicho)) *= 0.5f;
		resistances.at(static_cast<int>(types::lucha)) *= 0.5f;
		resistances.at(static_cast<int>(types::siniestro)) *= 0.5f;

		resistances.at(static_cast<int>(types::acero)) *= 2.0f;
		resistances.at(static_cast<int>(types::veneno)) *= 2.0f;

		resistances.at(static_cast<int>(types::dragon)) *= 0.0f;
	}
		break;
	case types::hielo: {
		//RES hielo
		//DEB acero fuego lucha roca
		resistances.at(static_cast<int>(types::hielo)) *= 0.5f;

		resistances.at(static_cast<int>(types::acero)) *= 2.0f;
		resistances.at(static_cast<int>(types::fuego)) *= 2.0f;
		resistances.at(static_cast<int>(types::lucha)) *= 2.0f;
		resistances.at(static_cast<int>(types::roca)) *= 2.0f;
	}
		break;
	case types::lucha: {
		//RES bicho roca siniestro
		//DEB hada psiquico volador
		resistances.at(static_cast<int>(types::bicho)) *= 0.5f;
		resistances.at(static_cast<int>(types::roca)) *= 0.5f;
		resistances.at(static_cast<int>(types::siniestro)) *= 0.5f;

		resistances.at(static_cast<int>(types::hada)) *= 2.0f;
		resistances.at(static_cast<int>(types::psiquico)) *= 2.0f;
		resistances.at(static_cast<int>(types::volador)) *= 2.0f;
	}
		break;
	case types::normal: {
		//RES 
		//DEB lucha
		//INM fantasma
		resistances.at(static_cast<int>(types::lucha)) *= 0.5f;

		resistances.at(static_cast<int>(types::fantasma)) *= 2.0f;
	}
		break;
	case types::planta: {
		//RES agua electrico planta tierra
 		//DEB bicho fuego hielo veneno volador
		resistances.at(static_cast<int>(types::agua)) *= 0.5f;
		resistances.at(static_cast<int>(types::electrico)) *= 0.5f;
		resistances.at(static_cast<int>(types::planta)) *= 0.5f;
		resistances.at(static_cast<int>(types::tierra)) *= 0.5f;

		resistances.at(static_cast<int>(types::bicho)) *= 2.0f;
		resistances.at(static_cast<int>(types::fuego)) *= 2.0f;
		resistances.at(static_cast<int>(types::hielo)) *= 2.0f;
		resistances.at(static_cast<int>(types::veneno)) *= 2.0f;
		resistances.at(static_cast<int>(types::volador)) *= 2.0f;
	}
		break;
	case types::psiquico: {
		//RES lucha psiquico
		//DEB bicho fantasma siniestro
		resistances.at(static_cast<int>(types::lucha)) *= 0.5f;
		resistances.at(static_cast<int>(types::psiquico)) *= 0.5f;

		resistances.at(static_cast<int>(types::bicho)) *= 2.0f;
		resistances.at(static_cast<int>(types::fantasma)) *= 2.0f;
		resistances.at(static_cast<int>(types::siniestro)) *= 2.0f;
	}
		break;
	case types::roca: {
		//RES fuego normal veneno volador
		//DEB acero agua lucha planta tierra
		resistances.at(static_cast<int>(types::fuego)) *= 0.5f;
		resistances.at(static_cast<int>(types::normal)) *= 0.5f;
		resistances.at(static_cast<int>(types::veneno)) *= 0.5f;
		resistances.at(static_cast<int>(types::volador)) *= 0.5f;

		resistances.at(static_cast<int>(types::acero)) *= 2.0f;
		resistances.at(static_cast<int>(types::agua)) *= 2.0f;
		resistances.at(static_cast<int>(types::lucha)) *= 2.0f;
		resistances.at(static_cast<int>(types::planta)) *= 2.0f;
		resistances.at(static_cast<int>(types::tierra)) *= 2.0f;
	}
		break;
	case types::tierra: {
		//RES roca veneno
		//DEB agua hielo planta
		//INM electrico
		resistances.at(static_cast<int>(types::roca)) *= 0.5f;
		resistances.at(static_cast<int>(types::veneno)) *= 0.5f;

		resistances.at(static_cast<int>(types::agua)) *= 2.0f;
		resistances.at(static_cast<int>(types::hielo)) *= 2.0f;
		resistances.at(static_cast<int>(types::planta)) *= 2.0f;

		resistances.at(static_cast<int>(types::electrico)) *= 0.0f;
	}
		break;
	case types::siniestro: {
		//RES fantasma siniestro
		//DEB bicho hada lucha
		//INM psiquico
		resistances.at(static_cast<int>(types::fantasma)) *= 0.5f;
		resistances.at(static_cast<int>(types::siniestro)) *= 0.5f;

		resistances.at(static_cast<int>(types::bicho)) *= 2.0f;
		resistances.at(static_cast<int>(types::hada)) *= 2.0f;
		resistances.at(static_cast<int>(types::lucha)) *= 2.0f;

		resistances.at(static_cast<int>(types::psiquico)) *= 0.0f;
	}
		break;
	case types::veneno: {
		//RES bicho hada lucha planta veneno
		//DEB psiquico tierra
		resistances.at(static_cast<int>(types::bicho)) *= 0.5f;
		resistances.at(static_cast<int>(types::hada)) *= 0.5f;
		resistances.at(static_cast<int>(types::lucha)) *= 0.5f;
		resistances.at(static_cast<int>(types::planta)) *= 0.5f;
		resistances.at(static_cast<int>(types::veneno)) *= 0.5f;

		resistances.at(static_cast<int>(types::psiquico)) *= 2.0f;
		resistances.at(static_cast<int>(types::tierra)) *= 2.0f;
	}
		break;
	case types::volador: {
		//RES bicho lucha planta 
		//DEB electrico hielo roca
		//INM tierra
		resistances.at(static_cast<int>(types::bicho)) *= 0.5f;
		resistances.at(static_cast<int>(types::lucha)) *= 0.5f;
		resistances.at(static_cast<int>(types::planta)) *= 0.5f;

		resistances.at(static_cast<int>(types::electrico)) *= 2.0f;
		resistances.at(static_cast<int>(types::hielo)) *= 2.0f;
		resistances.at(static_cast<int>(types::roca)) *= 2.0f;

		resistances.at(static_cast<int>(types::tierra)) *= 0.0f;

	}
		break;
	default:
		break;
	}
}


