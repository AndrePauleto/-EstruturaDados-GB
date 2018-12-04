#pragma once
#include "libUnicornio.h"
#include "Recurso.h"
#include "TelaLogin.h"
#include <ctime>

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();

	void executar();

private:
	MaquinaDeEstadosComPilha menuPilha;
	bool sair = false;
};

