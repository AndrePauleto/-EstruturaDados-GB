#pragma once
#include "libUnicornio.h"

#define MAX_SAVES 3

struct DadosSalvos
{
	int posicaoX = 1, 
		posicaoY = 1, 
		tipoPersonagem = 30,
		vida = 100,
		mana = 100,
		pontuacao = 0,
		inimigoPosicaoX = 5,
		inimigoPosicaoY = 5,
		inventario[3];
		
	bool carregado = false;
};

class Usuario
{
public:
	Usuario();
	~Usuario();
	string getUsuario();
	string getSenha();
	void setUsuario(string usuario);
	void setSenha(string senha);
	DadosSalvos * getDadosSalvosByIndex(int i);
	void setDadosSalvosByIndex(int index, DadosSalvos * dadosSalvos);
	void salvar();

private:
	string usuario, senha;
	DadosSalvos * dadosSalvos[MAX_SAVES];
	TileMap* mapa;
};

