#pragma once
#include "Tela.h"
#include "TelaJogo.h"
#include "Usuario.h"

class TelaLoad :
	public Tela
{
public:
	TelaLoad();
	TelaLoad(Usuario * usuario);
	~TelaLoad();

	void aoEntrar();
	void aoSair();
	void aoAtualizar(float dt);
	void aoDesenhar();

protected:
	BotaoSprite bLoad1, bLoad2, bLoad3, bLoad1Desabilitado, bLoad2Desabilitado, bLoad3Desabilitado, bVoltar;
	Usuario * usuario;
	int load = 999;
};

