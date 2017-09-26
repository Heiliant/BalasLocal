#include <iostream>
#include <SFML\Graphics.hpp>



class piece {
public:
	enum class type{peon, torre, alfil, caballo, reina, rey, max};

	struct coor {
		int x;
		int y;
	};

	type status;
	coor pos;
	bool white;

private:

};






