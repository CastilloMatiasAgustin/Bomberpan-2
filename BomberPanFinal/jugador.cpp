#include "jugador.h"

   jugador::jugador()
 {
	   cargarjugador();
}

/* Sprite jugador::getspritechef()
{
	return *spritechef; /// ?????? puntero nullptr
}*/

 void jugador::cargarjugador()
 {
	 texturachef = new Texture;
	 spritechef = new Sprite;
	 texturachef->loadFromFile("Chefsprite.png");
	 spritechef->setTexture(*texturachef);
 }