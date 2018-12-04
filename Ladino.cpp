#include "Ladino.h"

Ladino::Ladino(float x, float y)
{
	this->x = x;
	this->y = y;
	this->setSpriteSheet("Thief");
	this->setPos(this->x, this->y);
	this->consumoManaAtaque = 10;
	this->codigoPersonagem = 32;
	this->vel = 3.0f;
}


Ladino::~Ladino()
{
}

void Ladino::atacar()
{
	this->visivel = false;
}

void Ladino::atualizar()
{
	Personagem::atualizar();

	if (!this->estaVisivel()) {
		this->duracaoAtaque -= 1;
	}

	if (this->duracaoAtaque <= 0) {
		this->visivel = true;
		this->duracaoAtaque = 90;
	}
}


