#include "Pause.h"

Pause::Pause()
{
}

Pause::Pause(Usuario * usuario)
{
	this->usuario = usuario;
	bSalvar1.setSpriteSheet("bSaveGame1");
	bSalvar1.getSprite()->setEscala(0.5, 0.5);
	bSalvar1.setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2 - 100);

	bSalvar2.setSpriteSheet("bSaveGame2");
	bSalvar2.getSprite()->setEscala(0.5, 0.5);
	bSalvar2.setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2 - 50);

	bSalvar3.setSpriteSheet("bSaveGame3");
	bSalvar3.getSprite()->setEscala(0.5, 0.5);
	bSalvar3.setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	bVoltar.setSpriteSheet("bBack");
	bVoltar.getSprite()->setEscala(0.5, 0.5);
	bVoltar.setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2 + 50);

	bSair.setSpriteSheet("bBackToMenu");
	bSair.getSprite()->setEscala(0.5, 0.5);
	bSair.setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2 + 150);

	fundo.setSpriteSheet("fundoPause");
}


Pause::~Pause()
{
}

void Pause::desenhar()
{
	fundo.desenhar(0, 0);
	bSalvar1.desenhar();
	bSalvar2.desenhar();
	bSalvar3.desenhar();
	bVoltar.desenhar();
	bSair.desenhar();
}

void Pause::atualizar()
{
	bSalvar1.atualizar();
	bSalvar2.atualizar();
	bSalvar3.atualizar();
	bVoltar.atualizar();
	bSair.atualizar();
}
/*
* Retorna qual dos botoes foi pressionado pelo usuário
*/
int Pause::getOpcao()
{
	if (bSalvar1.estaClicado()) {
		return 1;
	}

	if (bSalvar2.estaClicado()) {
		return 2;
	}

	if (bSalvar3.estaClicado()) {
		return 3;
	}

	if (bVoltar.estaClicado()) {
		return 4;
	}

	if (bSair.estaClicado()) {
		return 5;
	}

	return 0;
}