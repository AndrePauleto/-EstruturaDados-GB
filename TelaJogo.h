#pragma once
#include "Tela.h"
#include "Jogador.h"
#include "Inimigo.h"
#include "Item.h"
#include "PocaoVida.h"
#include "PocaoMana.h"
#include <vector>
#include "Ranking.h"
#include "Pause.h"
#include <ctime>
#include "Usuario.h"

class TelaJogo :
	public Tela
{
public:
	TelaJogo();
	TelaJogo(Usuario * usuario, int indexSave);
	~TelaJogo();
	void aoEntrar();
	void aoSair();
	void aoAtualizar(float dt);
	void aoDesenhar();

private:
	TileMap* mapa;
	Jogador* jogador;
	Inimigo * inimigo = new Inimigo();
	vector<Item *> itens;
	bool estaComPause = false;
	int tamanhoTile = 32, pontuacaoAux = 0, pontuacao = 0, indexSave = 999;
	Ranking * ranking = new Ranking();
	Usuario * usuario;
	Pause * pause;
	Texto tLabelPontuacao, tPontuacao, tLabelVida, tVida, tLabelMana, tMana;

	void controlarPause();
	void testarColisaoInimigoPersonagem();
	void testarColisaoAtaqueInimigo();
	void testarColisaoItemPersonagem();
	void addItem();
	void loadDadosSalvos();
	void inicializarTextos();
	void desenharTextos();
};

