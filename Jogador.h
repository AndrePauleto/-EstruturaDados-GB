#pragma once
#include "libUnicornio.h"
#include "Personagem.h"
#include "Guerreiro.h"
#include "Mago.h"
#include "Ladino.h"
#include "Inventario.h"

class Jogador
{
public:
	Jogador(TileMap * mapa);
	~Jogador();
	void atualizar();
	TileMap * getMapa();
	void setMapa(TileMap *mapa);
	Personagem * getPersonagem();
	int getVida();
	int getMana();
	void setVida(int vida);
	void setMana(int mana);
	Inventario * getInventario();
	void alterarPersonagem(int codigoTecla);

protected:
	Personagem* personagem;
	TileMap* mapa;
	CamadaDeObjetosTileMap* camadaDeObjetosTileMap;
	void validarTrocaDePersonagem();
	void validarAtaquePersonagem();
	int vida = 100, mana = 100;
	Inventario * inventario = new Inventario();
};

