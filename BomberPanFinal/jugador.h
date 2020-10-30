#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;

class jugador
{
public:
	jugador();
	void cargarjugador();
	/*Sprite getspritechef();*/
protected:
	Texture* texturachef;
	Sprite* spritechef;
};

