#include "Tela.h"


Tela::Tela()
{
}


Tela::~Tela()
{
}

void Tela::entrar()
{
	aoEntrar();
}

void Tela::atualizar(float dt)
{
	aoAtualizar(dt);
}

void Tela::sair()
{
	aoSair();
}
