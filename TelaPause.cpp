#include "TelaPause.h"



TelaPause::TelaPause()
{
}


TelaPause::~TelaPause()
{
}

void TelaPause::aoEntrar()
{
	bVoltar.setSpriteSheet("bBack");
	bVoltar.getSprite()->setEscala(0.5, 0.5);
	bVoltar.setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2 + 150);
}

void TelaPause::aoSair()
{
}

void TelaPause::aoAtualizar(float dt)
{
	bVoltar.atualizar();
	this->aoDesenhar();
}

void TelaPause::aoDesenhar()
{
	bVoltar.desenhar();
}
