#include "Jogador.h"

Jogador::Jogador(TileMap* mapa)
{	
	this->mapa = mapa;
	ObjetoTileMap* objPos = this->mapa->getCamadaDeObjetos("Objetos")->getObjeto("Pos1");
	this->personagem = new Guerreiro(objPos->getXCentro(), objPos->getYCentro());
	this->mapa->getCamadaDeObjetos("Objetos")->adicionarObjeto(this->personagem);
}

Jogador::~Jogador()
{
}

void Jogador::atualizar()
{	
	this->inventario->atualizar();
	this->validarTrocaDePersonagem();
	this->validarAtaquePersonagem();
	this->personagem->atualizar();
}

TileMap * Jogador::getMapa()
{
	return this->mapa;
}

void Jogador::setMapa(TileMap *mapa)
{
	this->mapa = mapa;
}

Personagem * Jogador::getPersonagem()
{
	return this->personagem;
}

int Jogador::getVida()
{
	return this->vida;
}

int Jogador::getMana()
{
	return this->mana;
}

void Jogador::setVida(int vida)
{
	this->vida = vida;
}

void Jogador::setMana(int mana)
{
	this->mana = mana;
}

Inventario * Jogador::getInventario()
{
	return this->inventario;
}

void Jogador::validarTrocaDePersonagem()
{	
	if (gTeclado.pressionou[TECLA_1]) {
		this->alterarPersonagem(TECLA_1);
	}
	else if (gTeclado.pressionou[TECLA_2]) {
		this->alterarPersonagem(TECLA_2);
	}
	else if (gTeclado.pressionou[TECLA_3]) {
		this->alterarPersonagem(TECLA_3);
	}
	else if (gTeclado.pressionou[TECLA_F1]) {
		this->inventario->utilizarItem(0, this->vida, this->mana);
	}
	else if (gTeclado.pressionou[TECLA_F2]) {
		this->inventario->utilizarItem(1, this->vida, this->mana);
	}
	else if (gTeclado.pressionou[TECLA_F3]) {
		this->inventario->utilizarItem(2, this->vida, this->mana);
	}
}

/*
* Valida se o jogador possui mana suficiente para realizar o ataque
*/
void Jogador::validarAtaquePersonagem()
{
	if (gTeclado.pressionou[TECLA_ESPACO]) {

		if ((this->mana - this->personagem->getConsumoManaAtaque()) >= 0) {
			this->mana -= this->personagem->getConsumoManaAtaque();
			this->personagem->atacar();
		}
	}
}
/*
* Valida qual personagem deve ser instanciado a partir da tecla pressionada
*/
void Jogador::alterarPersonagem(int codigoTecla)
{
	float x = this->personagem->getX();
	float y = this->personagem->getY();
	delete this->personagem;

	switch (codigoTecla){
		case TECLA_1:
			//30
			this->personagem = new Guerreiro(x, y);
			break;
		case TECLA_2:
			//31
			this->personagem = new Mago(x, y);
			break;
		case TECLA_3:
			//32
			this->personagem = new Ladino(x, y);
			break;
		default:
			this->personagem = new Guerreiro(x, y);
			break;
	}

	this->mapa->getCamadaDeObjetos("Objetos")->adicionarObjeto(this->personagem);
}
