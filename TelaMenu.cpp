#include "TelaMenu.h"

TelaMenu::TelaMenu()
{
}

TelaMenu::TelaMenu(Usuario * usuario)
{
	this->usuario = usuario;
}


TelaMenu::~TelaMenu()
{
}

void TelaMenu::aoEntrar()
{
	bJogar.setSpriteSheet("bNewGame");
	bJogar.getSprite()->setEscala(0.5, 0.5);
	bJogar.setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2 - 100);

	bLoad.setSpriteSheet("bLoad");
	bLoad.getSprite()->setEscala(0.5, 0.5);
	bLoad.setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2 - 50);

	bRanking.setSpriteSheet("bRanking");
	bRanking.getSprite()->setEscala(0.5, 0.5);
	bRanking.setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	bCreditos.setSpriteSheet("bCredits");
	bCreditos.getSprite()->setEscala(0.5, 0.5);
	bCreditos.setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2 + 50);

	bSair.setSpriteSheet("bLogout");
	bSair.getSprite()->setEscala(0.5, 0.5);
	bSair.setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2 + 150);
}

void TelaMenu::aoAtualizar(float dt)
{
	if (bJogar.estaClicado()) {
		getMaquinaDeEstadosComPilha()->empilharEstado(new TelaJogo(this->usuario, 999));
	}

	if (bLoad.estaClicado()) {
		getMaquinaDeEstadosComPilha()->empilharEstado(new TelaLoad(this->usuario));
	}

	if (bSair.estaClicado()) {
		getMaquinaDeEstadosComPilha()->desempilharEstado();
	}

	if (bRanking.estaClicado()) {
		getMaquinaDeEstadosComPilha()->empilharEstado(new TelaRanking);
	}

	if (bCreditos.estaClicado()) {
		getMaquinaDeEstadosComPilha()->empilharEstado(new TelaCreditos);
	}

	bJogar.atualizar();
	bLoad.atualizar();
	bRanking.atualizar();
	bCreditos.atualizar();
	bSair.atualizar();
	aoDesenhar();
}

void TelaMenu::aoSair()
{
}

void TelaMenu::aoDesenhar()
{
	bJogar.desenhar();
	bLoad.desenhar();
	bRanking.desenhar();
	bCreditos.desenhar();
	bSair.desenhar();
}
