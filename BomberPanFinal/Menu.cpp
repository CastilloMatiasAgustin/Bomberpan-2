#include "Menu.h"
#include <ctime>
#include <cstdlib>
Controladora::Controladora(int ancho, int alto, std::string titulo)
{
	matriz = new int* [filas];

	Initiempo();

	generarMatriz();

	cargargraficos();

	VentanaInicial = new RenderWindow(VideoMode(ancho, alto), titulo);

	VentanaInicial->setFramerateLimit(fps);
	 
	gameloop();
}

void Controladora::dibujarventana()
{
	VentanaInicial->clear();
	dibujarBase();
    dibujarMatriz();
	/*VentanaInicial->draw(jugadorcito->getspritechef());*/
	VentanaInicial->display();
}

void Controladora::gameloop () 
{
	while (VentanaInicial->isOpen())
	{
		ConfigTiempo();
		if (tiempo->asSeconds() > 1 / fps)
		{
		dibujarventana();
		ConfigTiempo();
		reloj->restart();
		}
	}
}


void Controladora::cargargraficos()
{
	texturapasto = new Texture;
	spritepasto = new Sprite;
	texturapasto->loadFromFile("pasto.png");
	spritepasto->setTexture(*texturapasto);
	spritepasto->setScale(50.f / spritepasto->getTexture()->getSize().x, 50.f / spritepasto->getTexture()->getSize().y);

	texturadestruible = new Texture;
	spritedestruible = new Sprite;
	texturadestruible->loadFromFile("destruible.png");
	spritedestruible->setTexture(*texturadestruible);
	spritedestruible->setScale(50.f / spritedestruible->getTexture()->getSize().x, 50.f / spritedestruible->getTexture()->getSize().y);

	texturasolido = new Texture;
	spritesolido = new Sprite;
	texturasolido->loadFromFile("solido.png");
	spritesolido->setTexture(*texturasolido);
	spritesolido->setScale(50.f / spritesolido->getTexture()->getSize().x, 50.f / spritesolido->getTexture()->getSize().y);

}

sf::Sprite Controladora::getspritepasto()
{
	return *spritepasto;
}

void Controladora::generarMatriz()
{
	srand(time(NULL()));  /// Generador de semilla nueva
	for (int f = 0; f < filas; f++)
	{
		matriz[f] = new int[columnas];
	}
	for (int f = 0; f < filas; f++)
	{
		for (int c = 0; c < columnas; c++)
		{
			if (f == 0 || c == 0 || f == filas - 1 || c == columnas - 1)    /// Bloques Fijos exterior (solidos)=1
			{
				matriz[f][c] = 1;
			}
			else if (f % 2 == 0 && c % 2 == 0)                             /// Bloques Fijos interior (solidos)=1
			{
				matriz[f][c] = 1;
			}
			else if (f == 1 && (c == 1 || c == 2) || (c == 1 && f == 2)) /// Bloque de spawn (pasto) =0    
			{
				matriz[f][c] = 0;
			}
			else
			{
				matriz[f][c] = rand() % 2 + 2;           ///generacion aleatoria de bloques 2 (caminables) o 3 (destruible)
			}
		}
	}
}

void Controladora::dibujarBase()
{
	float X = 0, Y = 0;
	for (int f = 0; f < filas; f++)
	{
		for (int c = 0; c < columnas; c++)
		{
			if (matriz[f][c] == 0 || matriz[f][c] == 2)
			{
				spritepasto->setPosition(X, Y);
				VentanaInicial->draw(*spritepasto);
			}
			X += 50.f;
		}
	    Y += 50.f;
		X = 0.f;
	}
}

void Controladora::dibujarMatriz()
{
	float X = 0, Y = 0;
	for (int f = 0; f < filas; f++)
	{
		for (int c = 0; c < columnas; c++)
		{
			if (matriz[f][c] == 1)
			{
				spritesolido->setPosition(X, Y);
				VentanaInicial->draw(*spritesolido);
			}
			else if (matriz[f][c] == 3)
			{
				spritedestruible->setPosition(X, Y);
				VentanaInicial->draw(*spritedestruible);
			}
			X += 50.f;
		}
		Y += 50.f;
		X = 0.f;
	}
}

void Controladora::Initiempo()
{

	reloj = new Clock();

	tiempo = new Time();

}

void Controladora::ConfigTiempo()
{
	*tiempo = reloj->getElapsedTime();
	  
}
