#pragma once
#include "libUnicornio.h"
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
using namespace std;
#include "libUnicornio.h"

class Ranking
{
public:
	Ranking();
	~Ranking();
	void ler();
	void escrever(string usuario, int pontuacao);
	map<int, pair<string, int>> getMapRanking();
	void desenhar();

private:
	map<int, pair<string, int>> mapRanking;
	string caminhoArquivoRanking = "ranking/ranking.txt";
	fstream arquivoRanking;
};

