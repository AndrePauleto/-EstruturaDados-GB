#include "Inventario.h"



Inventario::Inventario()
{
	this->fundo.setSpriteSheet("fundoInventario");
	//Inicializa os itens
	for (int i = 0; i < MAX_ITENS; i++) {
		this->arrayItens[i] = new Item();
	}
}


Inventario::~Inventario()
{
}

void Inventario::atualizar()
{
	this->desenhar();
}

void Inventario::desenhar()
{
	this->fundo.desenhar((gJanela.getLargura() / 2) , (gJanela.getAltura() - 30));

	for (int i = 0; i < MAX_ITENS; i++) {
		if (this->arrayItens[i]->getNome() != "") {
			this->arrayItens[i]->desenhar();
		}
	}
}
/*
* Retorna o total de itens
*/
int Inventario::getTotalItens()
{
	return this->totalItens;
}

/*
* Verifica se há espaço no inventário
*/
bool Inventario::possuiEspaco()
{
	if (this->totalItens < MAX_ITENS) {
		return true;
	}
	return false;
}

/*
* Adiciona um item no inventário caso haja alguma posição vaga
*/
void Inventario::addItem(Item * item)
{
	for (int i = 0; i < MAX_ITENS; i++) {
		if (this->arrayItens[i]->getNome() == ""){
			this->addItemByIndex(i, item);
			break;
		}
	}
}

/*
* Adiciona um item na posicao informada
*/
void Inventario::addItemByIndex(int index, Item * item)
{
	int x = (gJanela.getLargura() / 2 - 30) + (30 * index);
	item->setX(x);
	item->setY(gJanela.getAltura() - 30);
	this->arrayItens[index] = item;
	totalItens++;

}

/*
Utiliza o item do inventário de acordo com a posição informada
*/
void Inventario::utilizarItem(int i, int &vida, int &mana)
{
	if (this->arrayItens[i]->getNome() != "") {

		if (this->arrayItens[i]->getTipo() == 1) {
			vida += 10;
			if (vida > 100) {
				vida = 100;
			}
		}

		if (this->arrayItens[i]->getTipo() == 2) {
			mana += 20;
			if (mana > 100) {
				mana = 100;
			}
		}


		this->arrayItens[i] = new Item();
		this->totalItens--;
	}
}

/*
Valida se há algum item na posição informada
*/
int Inventario::possuiItemByIndex(int index)
{
	return this->arrayItens[index]->getTipo();
}
