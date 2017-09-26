#include <iostream>

//funciones sobrecargadas tiene formas distintas. Orden de los argumentos, tipo de los argumentos y cantidad de los mismos

template<typename T>
T abs(T a) {
	return (a < 0) ?  -a:  a;
}


void main() {
	std::cout << abs<int>(-1);
	int a = 0;
}