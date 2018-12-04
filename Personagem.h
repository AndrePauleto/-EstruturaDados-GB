#pragma once
#include "libUnicornio.h"
#include "Inimigo.h"

enum
{
	BAIXO,
	ESQUERDA,
	DIREITA,
	CIMA
};

class Personagem: public ObjetoTileMap
{
public:
	Personagem();
	~Personagem();

	void setSpriteSheet(string spritesheet);
	virtual bool colisaoAtaqueInimigo(Inimigo * inimigo);
	virtual void atualizar();
	virtual void atacar() = 0;
	Sprite getSprite();
	int getCodigoPersonagem();
	int getConsumoManaAtaque();
	int getDefesa();

protected:
	Sprite spr;
	Vetor2D dir;
	float x, y, vel;
	TileMap mapa;
	void animar(int animacao);
	int direcao, codigoPersonagem = 30, consumoManaAtaque = 0, defesa = 0;
};

