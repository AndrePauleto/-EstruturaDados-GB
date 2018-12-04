#pragma once
#include "Tela.h"
class TelaPause :
	public Tela
{
public:
	TelaPause();
	~TelaPause();
	void aoEntrar();
	void aoSair();
	void aoAtualizar(float dt);
	void aoDesenhar();

private:
	BotaoSprite bSair, bSalvar, bVoltar;
};

