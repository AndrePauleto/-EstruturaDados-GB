#pragma once
#include "libUnicornio.h"

class Inimigo
{
public:
	Inimigo();
	~Inimigo();
	void inicializar(float escala, float velocidade, int sentido = 1);
	void desenhar();
	void atualizar();
	Sprite getSprite();
	float getX();
	float getY();
	void resetar();
	int getDano();
	void setVelocidade(float velocidade);
	float getVelocidade();
	void setX(int x);
	void setY(int y);

protected:
	float x, y, escala, velocidade;
	Sprite sprite;
	int randRespawnX(), dano = 25;
};

