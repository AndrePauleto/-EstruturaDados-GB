#pragma once
#include "Tela.h"
class TelaCreditos :
	public Tela
{
public:
	TelaCreditos();
	~TelaCreditos();

	void aoEntrar();
	void aoSair();
	void aoAtualizar(float dt);
	void aoDesenhar();

protected:
	Texto tObrigado;
	BotaoSprite bVoltarMenu;
};

