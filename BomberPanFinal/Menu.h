#pragma once
#include "SFML/Graphics.hpp"
#include "jugador.h"
#define filas 15
#define columnas 17
using namespace std;
using namespace sf;
class Controladora
{
public:

	Controladora(int ancho, int alto, std::string titulo);
	void gameloop();
	sf::Sprite getspritepasto();
	void dibujarventana();
	void cargargraficos();
	void generarMatriz();
	void dibujarBase();
	void dibujarMatriz();
	void Initiempo();
	void ConfigTiempo();
	 ~Controladora();
	
protected:
	int** matriz;
	RenderWindow* VentanaInicial;
	int fps=60;
	Texture* texturapasto;
	Sprite* spritepasto;
	Texture* texturasolido;
	Sprite* spritesolido;
	Texture* texturadestruible;
	Sprite* spritedestruible;
	Clock* reloj;
	Time* tiempo;
	jugador* jugadorcito;
};


