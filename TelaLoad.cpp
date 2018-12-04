#include "TelaLoad.h"



TelaLoad::TelaLoad()
{
}

TelaLoad::TelaLoad(Usuario * usuario)
{
	this->usuario = usuario;
}


TelaLoad::~TelaLoad()
{
}

void TelaLoad::aoEntrar()
{
	bLoad1.setSpriteSheet("bLoadGame1");
	bLoad1.getSprite()->setEscala(0.5, 0.5);
	bLoad1.setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2 - 100);

	bLoad2.setSpriteSheet("bLoadGame2");
	bLoad2.getSprite()->setEscala(0.5, 0.5);
	bLoad2.setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2 - 50);

	bLoad3.setSpriteSheet("bLoadGame3");
	bLoad3.getSprite()->setEscala(0.5, 0.5);
	bLoad3.setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	bLoad1Desabilitado.setSpriteSheet("bLoadGame1Disabled");
	bLoad1Desabilitado.getSprite()->setEscala(0.5, 0.5);
	bLoad1Desabilitado.setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2 - 100);

	bLoad2Desabilitado.setSpriteSheet("bLoadGame2Disabled");
	bLoad2Desabilitado.getSprite()->setEscala(0.5, 0.5);
	bLoad2Desabilitado.setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2 - 50);

	bLoad3Desabilitado.setSpriteSheet("bLoadGame3Disabled");
	bLoad3Desabilitado.getSprite()->setEscala(0.5, 0.5);
	bLoad3Desabilitado.setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	bVoltar.setSpriteSheet("bBackToMenu");
	bVoltar.getSprite()->setEscala(0.5, 0.5);
	bVoltar.setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2 + 150);
}

void TelaLoad::aoSair()
{
	//Caso a posição do load tenha sido definida, carregamos os jogo com os dados do load
	if (this->load != 999) {
		getMaquinaDeEstadosComPilha()->empilharEstado(new TelaJogo(this->usuario, this->load));
	}
}

void TelaLoad::aoAtualizar(float dt)
{
	if (bLoad1.estaClicado()) {
		getMaquinaDeEstadosComPilha()->desempilharEstado();
		this->load = 0;
	}

	if (bLoad2.estaClicado()) {
		getMaquinaDeEstadosComPilha()->desempilharEstado();
		this->load = 1;
	}

	if (bLoad3.estaClicado()) {
		getMaquinaDeEstadosComPilha()->desempilharEstado();
		this->load = 2;
	}

	if (bVoltar.estaClicado()) {
		getMaquinaDeEstadosComPilha()->desempilharEstado();
	}

	if (this->usuario->getDadosSalvosByIndex(0)->carregado) {
		bLoad1.atualizar();
		bLoad1.desenhar();
	}
	else {
		bLoad1Desabilitado.desenhar();
	}

	if (this->usuario->getDadosSalvosByIndex(1)->carregado) {
		bLoad2.atualizar();
		bLoad2.desenhar();
	}
	else {
		bLoad2Desabilitado.desenhar();
	}

	if (this->usuario->getDadosSalvosByIndex(2)->carregado) {
		bLoad3.atualizar();
		bLoad3.desenhar();
	}
	else {
		bLoad3Desabilitado.desenhar();
	}

	bVoltar.atualizar();
	aoDesenhar();
}

void TelaLoad::aoDesenhar()
{
	bVoltar.desenhar();
}
