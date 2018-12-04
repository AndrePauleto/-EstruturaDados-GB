#include "Jogo.h"

Jogo::Jogo()
{

}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	uniInicializar(512, 384, false);
	srand(time(NULL));
	
	Recurso * r = new Recurso();
	delete r;

	menuPilha.inicializar(new TelaLogin);
	menuPilha.aoInicializar();

}

void Jogo::finalizar()
{
	gRecursos.descarregarTudo();
	uniFinalizar();
}

void Jogo::executar()
{
	while (menuPilha.temEstados() && !gEventos.sair)
	{
		uniIniciarFrame();
		menuPilha.atualizar();
		uniTerminarFrame();
	}
}