#include "TelaCreditos.h"



TelaCreditos::TelaCreditos()
{
}


TelaCreditos::~TelaCreditos()
{
}

void TelaCreditos::aoEntrar()
{
	if (!gRecursos.carregouFonte("fonte")) {
		gRecursos.carregarFonte("fonte", "fontes/Racer.TTF", 15);
	}

	this->bVoltarMenu.setSpriteSheet("bBackToMenu");
	this->bVoltarMenu.getSprite()->setEscala(0.5, 0.5);
	this->bVoltarMenu.setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2 + 150);

	this->tObrigado.setAncora(0, 0.5);
	this->tObrigado.setFonte("fonte");
	this->tObrigado.setCor(255, 255, 255);
	this->tObrigado.setEscala(2, 2);
	this->tObrigado.setString("Obrigado :)");

}

void TelaCreditos::aoSair()
{
}

void TelaCreditos::aoAtualizar(float dt)
{
	if (this->bVoltarMenu.estaClicado()) {
		getMaquinaDeEstadosComPilha()->desempilharEstado();
	}

	this->tObrigado.setCorVermelho(this->tObrigado.getCorVermelho() - 1);
	this->tObrigado.setCorVerde(this->tObrigado.getCorVerde() - 10);
	this->tObrigado.setCorAzul(this->tObrigado.getCorAzul() - 30);

	this->bVoltarMenu.atualizar();
	this->aoDesenhar();
}

void TelaCreditos::aoDesenhar()
{
	this->tObrigado.desenhar(gJanela.getLargura() / 2 - 100, gJanela.getAltura() / 2);
	this->bVoltarMenu.desenhar();
}
