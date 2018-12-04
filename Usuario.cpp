#include "Usuario.h"



Usuario::Usuario()
{
	//Inicializamos os dados salvos
	for (int i = 0; i < MAX_SAVES; i++) {
		this->dadosSalvos[i] = new DadosSalvos();
	}
}


Usuario::~Usuario()
{
}

/*
* Define o usuario
*/
string Usuario::getUsuario()
{
	return this->usuario;
}

/*
* Retorna senha
*/
string Usuario::getSenha()
{
	return this->senha;
}

/*
* Define o usuario
*/
void Usuario::setUsuario(string usuario)
{
	this->usuario = usuario;
}
/*
* Define a senha
*/
void Usuario::setSenha(string senha)
{
	this->senha = senha;
}

/*
* Retorna os dados salvos na posição informada
*/
DadosSalvos * Usuario::getDadosSalvosByIndex(int i)
{
	return this->dadosSalvos[i];
}

/*
* Define os dados salvos na posição informada
*/
void Usuario::setDadosSalvosByIndex(int index, DadosSalvos * dadosSalvos)
{
	this->dadosSalvos[index] = dadosSalvos;
}
/*
* Salva os dados do Usuario no seu arquivo de save
*/
void Usuario::salvar()
{
	fstream arquivoSave;
	string caminhoArquivoSave = "usuarios/" + this->getUsuario() + ".txt";
	arquivoSave.open(caminhoArquivoSave);

	for (int i = 0; i < MAX_SAVES; i++) {
		if (!this->dadosSalvos[i]->carregado) {
			continue;
		}

		arquivoSave << i
			<< " " << this->dadosSalvos[i]->posicaoX
			<< " " << this->dadosSalvos[i]->posicaoY
			<< " " << this->dadosSalvos[i]->tipoPersonagem
			<< " " << this->dadosSalvos[i]->vida
			<< " " << this->dadosSalvos[i]->mana
			<< " " << this->dadosSalvos[i]->pontuacao
			<< " " << this->dadosSalvos[i]->inimigoPosicaoX
			<< " " << this->dadosSalvos[i]->inimigoPosicaoY
			<< " " << this->dadosSalvos[i]->inventario[0]
			<< " " << this->dadosSalvos[i]->inventario[1]
			<< " " << this->dadosSalvos[i]->inventario[2]
			<< endl;
	}
	arquivoSave.close();

}

