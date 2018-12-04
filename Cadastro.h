#pragma once
#include "libUnicornio.h"

class Cadastro
{
public:
	Cadastro();
	~Cadastro();
	void setUsuario(string usuario);
	void setSenha(string senha);
	string getUsuario();
	string getSenha();
	bool registrar();


private:
	fstream arquivoUsuarios;
	string usuario, senha, caminhoArquivoUsusarios = "usuarios/usuarios.txt";
	map<string, string> mapUsuarios;

	void ler();
};

