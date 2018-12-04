#include "Mago.h"

Mago::Mago(float x, float y)
{
	this->x = x;
	this->y = y;
	this->setSpriteSheet("Mage");
	this->setPos(this->x, this->y);
	this->codigoPersonagem = 31;
	this->consumoManaAtaque = 5;
	this->defesa = 5;
}


Mago::~Mago()
{
}

void Mago::atacar()
{
	BolaFogo bolaFogo  = BolaFogo();
	int tamanhoTile = 32;
	bolaFogo.inicializar(this->getXCentro() * tamanhoTile, this->getYCentro() * tamanhoTile, 3, "Mage", this->direcao);
	this->bolaFogoRepository.add(bolaFogo);
	this->bolaFogoRepository.atualizar();
	this->bolaFogoRepository.desenhar();
}

void Mago::atualizar()
{
	Personagem::atualizar();
	this->bolaFogoRepository.atualizar();
	this->bolaFogoRepository.desenhar();
}

bool Mago::colisaoAtaqueInimigo(Inimigo * inimigo)
{
	bool acertou = false;
	for (int i = (this->bolaFogoRepository.getTotalBolasFogo() - 1); i >= 0; i--)
	{
		if (uniTestarColisao(this->bolaFogoRepository.getBolaFogoByIndex(i).getSprite(), this->bolaFogoRepository.getBolaFogoByIndex(i).getX(), this->bolaFogoRepository.getBolaFogoByIndex(i).getY(), 0,
			inimigo->getSprite(), inimigo->getX(), inimigo->getY(), 0))
		{
			acertou = true;	
			this->bolaFogoRepository.removerBolaFogoByIndex(i);
		}
	}

	return acertou;
}
