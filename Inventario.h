#pragma once
#include "Item.h"
#include <vector>

#define MAX_ITENS 3
class Inventario
{
public:
	Inventario();
	~Inventario();
	void atualizar();
	void desenhar();
	int getTotalItens();
	bool possuiEspaco();
	void addItem(Item * item);
	void addItemByIndex(int index, Item * item);
	void utilizarItem(int i, int &vida, int &mana);
	int possuiItemByIndex(int index);

private:
	Item * arrayItens[MAX_ITENS];
	int totalItens = 0;
	Sprite fundo;
};

