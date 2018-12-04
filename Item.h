#pragma once
#include "libUnicornio.h"
class Item
{
public:
	Item();
	~Item();
	void setNome(string nome);
	void setX(int x);
	void setY(int y);
	void atualizar();
	virtual void desenhar();

	string getNome();
	int getX();
	int getY();
	Sprite getSprite();
	void setDropou(bool dropou);
	bool isDropado();
	void setCorAlpha(int corAlpha);
	int getTipo();

protected:
	Sprite sprite;
	string nome;
	int x, y;
	bool drop = false, piscar = false;
	int tempoDuracao = 270, tipo = 0;
};

