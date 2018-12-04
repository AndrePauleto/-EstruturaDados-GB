#include "Login.h"



Login::Login()
{
}


Login::~Login()
{
}

int Login::buscarUsuario(Usuario * & usuario)
{
	this->usuario = usuario;
	
	if (this->autenticar()) {

		this->buscarSaves();
		return 1;
	}
	return 0;
}

bool Login::autenticar()
{
	string userAndPass = this->usuario->getUsuario() + " " + this->usuario->getSenha();
	int offset;
	string line;
	ifstream arquivoUsuarios;
	arquivoUsuarios.open(this->caminhoArquivoUsuarios);
	bool encontrou = false;
	if (arquivoUsuarios.is_open()) {	
		while (getline(arquivoUsuarios, line) && !encontrou) {
			if (line.compare(userAndPass) == 0) {
				encontrou = true;
			}
		}	
		arquivoUsuarios.close();
	}

	return encontrou;
}

void Login::buscarSaves()
{
	fstream arquivoSave;
	string caminhoArquivoSave = "usuarios/" + this->usuario->getUsuario() + ".txt";
	arquivoSave.open(caminhoArquivoSave);

	int index;
	
	if (arquivoSave.is_open()) {
		while (!arquivoSave.eof())
		{
			DadosSalvos * dadosSalvos = new DadosSalvos();
			arquivoSave >>
				index >>
				dadosSalvos->posicaoX >>
				dadosSalvos->posicaoY >>
				dadosSalvos->tipoPersonagem >>
				dadosSalvos->vida >>
				dadosSalvos->mana >>
				dadosSalvos->pontuacao >>
				dadosSalvos->inimigoPosicaoX >>
				dadosSalvos->inimigoPosicaoY >>
				dadosSalvos->inventario[0] >>
				dadosSalvos->inventario[1] >>
				dadosSalvos->inventario[2];
			if (!arquivoSave.fail()) {
				dadosSalvos->carregado = true;
				this->usuario->setDadosSalvosByIndex(index, dadosSalvos);
			}
			index++;
		}
	} else {
		arquivoSave.clear();
		arquivoSave.open(caminhoArquivoSave, ios_base::out);
	}

	arquivoSave.close();
}
