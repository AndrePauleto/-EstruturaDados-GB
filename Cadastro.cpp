#include "Cadastro.h"



Cadastro::Cadastro()
{
	this->ler();
}


Cadastro::~Cadastro()
{
}

void Cadastro::setUsuario(string usuario)
{
	this->usuario = usuario;
}

void Cadastro::setSenha(string senha)
{
	this->senha = senha;
}

string Cadastro::getUsuario()
{
	return this->usuario;
}

string Cadastro::getSenha()
{
	return this->senha;
}

/*
* Registra o usuário no arquivo de usuários.
*/
bool Cadastro::registrar()
{
	//Valida se o usuario ja esta cadastrado
	std::map<string, string>::iterator iter = mapUsuarios.find(this->usuario);
	if (iter != mapUsuarios.end()) {
		return false;
	}

	this->mapUsuarios[this->usuario] = this->senha;

	//Adiciona o usuario na ultima posição do arquivo
	this->arquivoUsuarios.open(this->caminhoArquivoUsusarios);
	if (this->arquivoUsuarios.is_open()) {
	
		std::ofstream log(this->caminhoArquivoUsusarios, std::ios_base::app | std::ios_base::out);
		log << "\n" + this->usuario + " " + this->senha;
	}

	this->arquivoUsuarios.close();

	return true;
}

/*
* Le o arquivo de usuarios e os adiciona na estrutura
*/
void Cadastro::ler()
{
	this->arquivoUsuarios.open(this->caminhoArquivoUsusarios);
	string usuarioArquivo, senhaArquivo;
	if (this->arquivoUsuarios.is_open()) {
		while (!this->arquivoUsuarios.eof())
		{
			this->arquivoUsuarios >> usuarioArquivo >> senhaArquivo;
			if (!this->arquivoUsuarios.fail()) {
				this->mapUsuarios[usuarioArquivo] = senhaArquivo;
			}
		}
	}
	this->arquivoUsuarios.close();
}
