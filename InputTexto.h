#pragma once

#include "libUnicornio.h"

class InputTexto
{
public:
	InputTexto();
	~InputTexto();

	void inicializar();
	void finalizar();

	void atualizar();
	void desenhar();
	void limparTexto();
	Texto getTexto();

private:
	Texto txt;
};

