#include "Inimigo.h"



Inimigo::Inimigo()
{
}


Inimigo::~Inimigo()
{
}

void Inimigo::inicializar(float escala, float velocidade, int sentido)
{
	this->sprite.setSpriteSheet("Slime");
	this->sprite.setEscala(escala, escala);
	this->x = this->randRespawnX();
	this->y = 0;
	this->escala = escala;
	this->velocidade = velocidade;
}

void Inimigo::desenhar()
{
	this->sprite.desenhar(this->x, this->y);
}

void Inimigo::atualizar()
{
	this->y += velocidade + 1;

	if (this->y > gJanela.getAltura() + this->sprite.getAltura() / 2) {
		this->y = 0;
		this->x = this->randRespawnX();
	}
}

int Inimigo::randRespawnX()
{
	return rand() % gJanela.getLargura();
}

Sprite Inimigo::getSprite()
{
	return this->sprite;
}

float Inimigo::getX()
{
	return this->x;
}

float Inimigo::getY()
{
	return this->y;
}

void Inimigo::resetar()
{
	this->y = 0;
	this->x = this->randRespawnX();
}

int Inimigo::getDano()
{
	return this->dano;
}

void Inimigo::setVelocidade(float velocidade)
{
	this->velocidade = velocidade;
}

float Inimigo::getVelocidade()
{
	return this->velocidade;
}

void Inimigo::setX(int x)
{
	this->x = x;
}

void Inimigo::setY(int y)
{
	this->y = y;
}
