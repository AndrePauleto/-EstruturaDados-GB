#pragma once
#include "libUnicornio.h"
#include "Usuario.h"
class Pause
{
public:
	Pause();
	Pause(Usuario * usuario);
	~Pause();

	void desenhar();
	void atualizar();
	int getOpcao();

protected:

	Sprite fundo;
	BotaoSprite bSair, bSalvar1, bSalvar2, bSalvar3, bVoltar;
	Usuario * usuario;
};