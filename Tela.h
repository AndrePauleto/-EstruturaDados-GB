#pragma once
#include "libUnicornio.h"

class Tela :
	public Estado
{
public:

	void entrar();
	void atualizar(float dt);
	void sair();
	//Metodos da filha	
	virtual void aoEntrar() = 0;
	virtual void aoSair() = 0;
	virtual void aoAtualizar(float dt) = 0;
	virtual void aoDesenhar() = 0;

	Tela();
	~Tela();
protected:
	Sprite sprFundo;
	int x, y;
};

