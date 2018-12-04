#pragma once
#include "Tela.h"
#include "Ranking.h"

class TelaRanking :
	public Tela
{
public:
	TelaRanking();
	~TelaRanking();
	void aoEntrar();
	void aoSair();
	void aoAtualizar(float dt);
	void aoDesenhar();

protected:
	BotaoSprite bVoltar;
	Ranking * ranking = new Ranking();
};

