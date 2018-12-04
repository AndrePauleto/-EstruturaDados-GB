#include "Ranking.h"



Ranking::Ranking()
{	
	if (!gRecursos.carregouFonte("fonte")) {
		gRecursos.carregarFonte("fonte", "fontes/Racer.TTF", 15);
	}
	this->ler();
}


Ranking::~Ranking()
{
}
/*
* Percorre o arquivo de ranking e o adiciona em uma estrutura
*/
void Ranking::ler()
{
	this->arquivoRanking.open(this->caminhoArquivoRanking);
	string usuario;
	int pontuacao;
	int posicao = 0;
	while (!this->arquivoRanking.eof())
	{
		this->arquivoRanking >> usuario >> pontuacao;
		if (!this->arquivoRanking.fail() && !empty(usuario) && pontuacao != 0) {

			this->mapRanking[posicao] = make_pair(usuario, pontuacao);
			posicao++;
		}
	}
	this->arquivoRanking.close();
}

/*
* Adiciona a pontuação atual do jogador em uma sexta posição;
* Cria um comparador que ordena a estrutura de ranking;
* Remove a última posição dessa estrutura, pois só os 5 devem ser gravados;
* Grava os dados da estrutura no arquivo.
*/
void Ranking::escrever(string usuario, int pontuacao)
{
	this->mapRanking[5] = make_pair(usuario, pontuacao);

	typedef function<bool(pair<int, pair<string, int>>, pair<int, pair<string, int>>)> Comparator;

	Comparator compFunctor = [](pair<int, pair<string, int>> elem1, pair<int, pair<string, int>> elem2) {
		return elem1.second.second > elem2.second.second;
	};

	set<pair<int, pair<string, int>>, Comparator> mapRankingAux(
		this->mapRanking.begin(), this->mapRanking.end(), compFunctor);

	mapRankingAux.erase(--mapRankingAux.end());
	
	this->arquivoRanking.open(this->caminhoArquivoRanking);

	for (pair<int, pair<string, int>> element : mapRankingAux) {
		if (!empty(element.second.first) && element.second.second != 0) {
			this->arquivoRanking << element.second.first << " " << element.second.second << endl;
		}
	}
	this->arquivoRanking.close();

}

/*
* Retorna o estrutura de ranking
*/
map<int, pair<string, int>> Ranking::getMapRanking()
{
	return this->mapRanking;
}

void Ranking::desenhar()
{
	int yInicio = 50;
	for (pair<int, pair<string, int>> element : this->mapRanking) {
		Texto tUsuario, tPontuacao;
		tUsuario.setAncora(0, 0.5);
		tUsuario.setFonte("fonte");
		tUsuario.setCor(255, 215, 0);

		tPontuacao.setAncora(0, 0.5);
		tPontuacao.setFonte("fonte");
		tPontuacao.setCor(255, 215, 0);

		tUsuario.setString(element.second.first);
		tPontuacao.setString(" - " + to_string(element.second.second));
		int posicaoX = gJanela.getLargura() / 2;
		tUsuario.desenhar(posicaoX - 150 , yInicio);
		tPontuacao.desenhar(posicaoX - 10, yInicio);
		yInicio += 50;
	}
}
