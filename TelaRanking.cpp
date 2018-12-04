#include "TelaRanking.h"



TelaRanking::TelaRanking()
{
}


TelaRanking::~TelaRanking()
{
}

void TelaRanking::aoEntrar()
{
	bVoltar.setSpriteSheet("bBack");
	bVoltar.getSprite()->setEscala(0.5, 0.5);
	bVoltar.setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2 + 150);
}

void TelaRanking::aoSair()
{
}

void TelaRanking::aoAtualizar(float dt)
{
	if (bVoltar.estaClicado()) {
		getMaquinaDeEstadosComPilha()->desempilharEstado();
	}

	bVoltar.atualizar();
	aoDesenhar();
}

void TelaRanking::aoDesenhar()
{
	bVoltar.desenhar();
	this->ranking->desenhar();
}
