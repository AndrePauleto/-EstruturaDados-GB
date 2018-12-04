#pragma once
#include "Personagem.h"
class Guerreiro :
	public Personagem
{
public:
	Guerreiro(float x, float y);
	~Guerreiro();
	void atacar();
	void atualizar() override;
	bool colisaoAtaqueInimigo(Inimigo * inimigo) override;

private:
	Sprite ataque;
	int duracaoAtaque = 30, posicaoXAtaque = 0, posicaoYAtaque = 0, intervaloAtaque = 100;
	bool podeAtacar = true;
	void desenharAtaque();
};

