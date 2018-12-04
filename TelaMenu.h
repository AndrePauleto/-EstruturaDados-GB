#pragma once
#include "Tela.h"
#include "TelaJogo.h"
#include "TelaRanking.h"
#include "TelaLoad.h"
#include "TelaCreditos.h"
#include "Usuario.h"

class TelaMenu :
	public Tela
{
public:
	TelaMenu();
	TelaMenu(Usuario * usuario);
	~TelaMenu();

	void aoEntrar();
	void aoSair();
	void aoAtualizar(float dt);
	void aoDesenhar();

protected:
	BotaoSprite bJogar, bLoad, bSair, bRanking, bCreditos;
	Usuario * usuario;
};

