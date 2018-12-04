#pragma once
#include "Personagem.h"
#include "BolaFogo.h"
#include "BolaFogoRepository.h"
class Mago :
	public Personagem
{
public:
	Mago(float x, float y);
	~Mago();
	void atacar();
	void atualizar() override;
	bool colisaoAtaqueInimigo(Inimigo * inimigo) override;
private:
	BolaFogoRepository bolaFogoRepository;
};

