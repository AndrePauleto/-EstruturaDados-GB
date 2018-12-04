#include "Item.h"



Item::Item()
{
}


Item::~Item()
{
}

void Item::setNome(string nome)
{
	this->nome = nome;
}

void Item::setX(int x)
{
	this->x = x;
}

void Item::setY(int y)
{
	this->y = y;
}

void Item::atualizar()
{
	//Caso o item tenha sido dropado pelo inimigo, é aplicado uma regra de duração que o item deve aparecer na tela
	if (this->drop) {
		this->tempoDuracao--;
		int i = 0;
		i = this->sprite.getCorAlpha();
		if (this->tempoDuracao <= 130) {	
			this->sprite.setCorAlpha(this->sprite.getCorAlpha() - 1);
		}

		if (this->tempoDuracao <= 0) {
			this->tempoDuracao = 270;
			this->drop = false;
		}
	}
}

void Item::desenhar()
{
	this->sprite.desenhar(this->x, this->y);
}

string Item::getNome()
{
	return this->nome;
}

int Item::getX()
{
	return this->x;
}

int Item::getY()
{
	return this->y;
}

Sprite Item::getSprite()
{
	return this->sprite;
}

void Item::setDropou(bool dropou)
{
	this->drop = dropou;
}

bool Item::isDropado()
{
	return this->drop;
}

void Item::setCorAlpha(int corAlpha)
{
	this->sprite.setCorAlpha(corAlpha);
}

int Item::getTipo()
{
	return this->tipo;
}
