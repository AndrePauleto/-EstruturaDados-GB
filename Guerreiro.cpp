#include "Guerreiro.h"

Guerreiro::Guerreiro(float x, float y)
{
	this->mapa = mapa;
	this->x = x;
	this->y = y;
	this->setSpriteSheet("Knight");

	this->setPos(this->x, this->y);
	this->codigoPersonagem = 30;
	this->defesa = 15;

	this->ataque.setSpriteSheet("SwordDown");
	this->ataque.setEscala(0.5, 0.5);
	this->ataque.setCorAlpha(0);
}


Guerreiro::~Guerreiro()
{
}

void Guerreiro::atacar()
{
	if (this->podeAtacar) {
		this->ataque.setCorAlpha(255);
		this->podeAtacar = false;
	}
}

void Guerreiro::atualizar()
{
	Personagem::atualizar();
	if (this->ataque.getCorAlpha() == 255) {
		this->duracaoAtaque -= 1;
		this->intervaloAtaque -= 1;
		this->desenharAtaque();
	}

	if (this->duracaoAtaque <= 0) {
		this->duracaoAtaque = 30;
		this->ataque.setCorAlpha(0);
	}

	if (!this->podeAtacar) {
		this->intervaloAtaque--;

		if (this->intervaloAtaque <= 0) {
			this->podeAtacar = true;
			this->intervaloAtaque = 100;
		}
	}
}

bool Guerreiro::colisaoAtaqueInimigo(Inimigo * inimigo)
{
	if (this->ataque.getCorAlpha() == 255) {
		if (uniTestarColisao(this->ataque, this->posicaoXAtaque, this->posicaoYAtaque, 0,
			inimigo->getSprite(), inimigo->getX(), inimigo->getY(), 0))
		{
			return true;
		}
	}
	return false;
}

void Guerreiro::desenharAtaque()
{
	int tamanhoTile = 32;
	this->posicaoXAtaque = this->getXCentro() * tamanhoTile;
	this->posicaoYAtaque = this->getYCentro() * tamanhoTile;

	switch (this->direcao)
	{
	case CIMA:
		this->posicaoYAtaque -= 40;
		this->ataque.setSpriteSheet("SwordUp");
		break;
	case BAIXO:
		this->posicaoYAtaque += 40;
		this->ataque.setSpriteSheet("SwordDown");
		break;
	case DIREITA:
		this->posicaoXAtaque += 40;
		this->ataque.setSpriteSheet("SwordRight");
		break;
	case ESQUERDA:
		this->posicaoXAtaque -= 40;
		this->ataque.setSpriteSheet("SwordLeft");
		break;
	}
	this->ataque.desenhar(this->posicaoXAtaque, this->posicaoYAtaque);
}
