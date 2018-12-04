#include "TelaJogo.h"



TelaJogo::TelaJogo()
{

}

TelaJogo::TelaJogo(Usuario *  usuario, int indexSave)
{
	this->mapa = new TileMap();
	this->usuario = usuario;
	this->pause = new Pause(usuario);
	this->indexSave = indexSave;
	
	this->inicializarTextos();
}


TelaJogo::~TelaJogo()
{
}

void TelaJogo::aoEntrar()
{
	if (!this->mapa->estaCarregado()) {
		this->mapa->carregar("assets/tilemaps/aula.json");
	}
	this->jogador = new Jogador(this->mapa);
	this->jogador->getPersonagem()->setPos(8, 10);
	this->inimigo->inicializar(1, 0.5, 1);

	this->loadDadosSalvos();
}

void TelaJogo::aoAtualizar(float dt)
{
	if (gTeclado.pressionou[TECLA_ESC] || this->estaComPause) {
		this->controlarPause();
	}
	else {

		if (this->jogador->getVida() <= 0) {
			this->ranking->escrever(this->usuario->getUsuario(), this->pontuacao);
			this->jogador->setVida(0);
			getMaquinaDeEstadosComPilha()->desempilharEstado();
		}

		this->aoDesenhar();
		this->jogador->atualizar();
		this->inimigo->atualizar();

		this->desenharTextos();

		this->pontuacaoAux++;
		this->pontuacao = this->pontuacaoAux / 10;

		if (this->pontuacao > 700) {
			this->inimigo->setVelocidade(float(this->pontuacao / 1400));
		}

		this->testarColisaoAtaqueInimigo();
		this->testarColisaoInimigoPersonagem();
		this->testarColisaoItemPersonagem();
	}
}

void TelaJogo::aoSair()
{

}

void TelaJogo::aoDesenhar()
{
	this->mapa->desenhar();
	this->inimigo->desenhar();
	for (int i = 0; i < this->itens.size(); i++) {
		//PocaoVida * pocaoVida = static_cast<PocaoVida *>(this->itens[i]);
		if (this->itens[i]->isDropado()) {
			this->itens[i]->desenhar();
			this->itens[i]->atualizar();
		}
		else {
			this->itens.erase(this->itens.begin() + i);
		}
		
	}
}

/*
*  Controla a tela de pause do jogo
*/
void TelaJogo::controlarPause()
{
	this->estaComPause = true;
	this->pause->atualizar();
	this->pause->desenhar();

	DadosSalvos * dadosSalvos = new DadosSalvos();
	dadosSalvos->posicaoX = (int) this->jogador->getPersonagem()->getXCentro();
	dadosSalvos->posicaoY = (int) this->jogador->getPersonagem()->getYCentro();
	dadosSalvos->tipoPersonagem = this->jogador->getPersonagem()->getCodigoPersonagem();
	dadosSalvos->vida = this->jogador->getVida();
	dadosSalvos->mana = this->jogador->getMana();
	dadosSalvos->pontuacao = this->pontuacao;
	dadosSalvos->inimigoPosicaoX = (int) this->inimigo->getX();
	dadosSalvos->inimigoPosicaoY = (int) this->inimigo->getY();

	for (int i = 0; i < MAX_ITENS; i++) {
		dadosSalvos->inventario[i] = this->jogador->getInventario()->possuiItemByIndex(i);
	}
	dadosSalvos->carregado = true;

	switch (this->pause->getOpcao()) {

	case 1:
		this->usuario->setDadosSalvosByIndex(0, dadosSalvos);
		this->usuario->salvar();
		break;
	case 2:
		this->usuario->setDadosSalvosByIndex(1, dadosSalvos);
		this->usuario->salvar();
		break;
	case 3:
		this->usuario->setDadosSalvosByIndex(2, dadosSalvos);
		this->usuario->salvar();
		break;
	case 4:
		this->estaComPause = false;
		break;
	case 5:
		getMaquinaDeEstadosComPilha()->desempilharEstado();
		break;
	default:
		break;
	}
}

/*
 * Testa a colisão entre o Inimigo e o Personagem.
 * Caso haja, decrementa a vida do jogador e reseta a posição do inimigo.
 */
void TelaJogo::testarColisaoInimigoPersonagem()
{
	if (!this->jogador->getPersonagem()->estaVisivel()) {
		return;
	}

	if (uniTestarColisao(this->inimigo->getSprite(), this->inimigo->getX(), this->inimigo->getY(), 0,
		this->jogador->getPersonagem()->getSprite(), this->jogador->getPersonagem()->getXCentro() * tamanhoTile, this->jogador->getPersonagem()->getYCentro() * tamanhoTile, 0)) {
		int danoSofrido = this->inimigo->getDano() - this->jogador->getPersonagem()->getDefesa();
		this->jogador->setVida(this->jogador->getVida() - danoSofrido);
		this->inimigo->resetar();
	}
}

/*
* Testa a colisão entre  o ataque do Jogador e o inimigo
* Caso haja, verificamos se o inimigo deve dropar um item, resetamos a posição do mesmo e adicionamos pontuação
*/
void TelaJogo::testarColisaoAtaqueInimigo()
{
	if (this->jogador->getPersonagem()->colisaoAtaqueInimigo(this->inimigo)) {
		
		if (rand() % 100 + 1 <= 100) {
			this->addItem();
		}
		
		this->inimigo->resetar();
		this->pontuacaoAux += 500;
	}
}

/*
* Testa a colisão entre o Jogador e os itens que estão na tela
* Caso haja, verificamos se há espaço no inventário do jogador e adicionamos o item
*/
void TelaJogo::testarColisaoItemPersonagem()
{
	for (int i = 0; i < this->itens.size(); i++) {
		
		//PocaoVida * pocaoVida = static_cast<PocaoVida *>(this->itens[i]);
		if (uniTestarColisao(this->itens[i]->getSprite(), (float) this->itens[i]->getX(), (float) this->itens[i]->getY(), 0,
			this->jogador->getPersonagem()->getSprite(), (float) this->jogador->getPersonagem()->getXCentro() * tamanhoTile, (float) this->jogador->getPersonagem()->getYCentro() * tamanhoTile, 0)) {
			
			if (this->jogador->getInventario()->possuiEspaco()) {
				this->itens[i]->setDropou(false);
				this->itens[i]->setCorAlpha(255);
				this->jogador->getInventario()->addItem(this->itens[i]);
				this->itens.erase(this->itens.begin() + i);
			}
		}
	}
}

/*
* Adiciona um item na tela na posição onde o Inimigo foi morto.
*/
void TelaJogo::addItem()
{
	if (rand() % 2) {
		PocaoVida * pocao = new PocaoVida();
		pocao->setX((int) this->inimigo->getX());
		pocao->setY((int) this->inimigo->getY());
		pocao->setDropou(true);
		this->itens.push_back(pocao);
	} else {
		PocaoMana * pocao = new PocaoMana();
		pocao->setX((int) this->inimigo->getX());
		pocao->setY((int) this->inimigo->getY());
		pocao->setDropou(true);
		this->itens.push_back(pocao);
	}

}

/*
* Carregamos os dados do load selecionado pelo usuário e setamos os atributos
*/
void TelaJogo::loadDadosSalvos()
{
	if (this->indexSave != 999) {

		DadosSalvos * dadosSalvos = this->usuario->getDadosSalvosByIndex(indexSave);
		this->jogador->getPersonagem()->setPos((float)dadosSalvos->posicaoX, (float)dadosSalvos->posicaoY);
		this->jogador->alterarPersonagem(dadosSalvos->tipoPersonagem);
		this->jogador->setVida(dadosSalvos->vida);
		this->jogador->setMana(dadosSalvos->mana);
		this->pontuacaoAux = dadosSalvos->pontuacao * 10;
		this->inimigo->setX(dadosSalvos->inimigoPosicaoX);
		this->inimigo->setY(dadosSalvos->inimigoPosicaoY);

		for (int i = 0; i < MAX_ITENS; i++) {
			if (dadosSalvos->inventario[i] == 1) {
				this->jogador->getInventario()->addItemByIndex(i, new PocaoVida());
			}
			else if (dadosSalvos->inventario[i] == 2) {
				this->jogador->getInventario()->addItemByIndex(i, new PocaoMana());
			}
		}
	}
}

/*
* Inicializamos os textos que são apresentados na tela
*/
void TelaJogo::inicializarTextos()
{
	this->tLabelPontuacao.setAncora(0, 0.5);
	this->tLabelPontuacao.setFonte("fonte");
	this->tLabelPontuacao.setCor(0, 0, 0);

	this->tPontuacao.setAncora(0, 0.5);
	this->tPontuacao.setFonte("fonte");
	this->tPontuacao.setCor(255, 255, 255);

	this->tLabelVida.setAncora(0, 0.5);
	this->tLabelVida.setFonte("fonte");
	this->tLabelVida.setCor(0, 0, 0);

	this->tVida.setAncora(0, 0.5);
	this->tVida.setFonte("fonte");
	this->tVida.setCor(255, 255, 255);

	this->tLabelMana.setAncora(0, 0.5);
	this->tLabelMana.setFonte("fonte");
	this->tLabelMana.setCor(0, 0, 0);

	this->tMana.setAncora(0, 0.5);
	this->tMana.setFonte("fonte");
	this->tMana.setCor(255, 255, 255);
}

/*
* Desenha a vida, mana e pontuação do Jogador
*/
void TelaJogo::desenharTextos()
{
	tLabelPontuacao.setString("Pontuacao: ");
	tLabelPontuacao.desenhar(10, 10);
	tPontuacao.setString(to_string(this->pontuacao));
	tPontuacao.desenhar(135, 10);

	tLabelVida.setString("Vida: ");
	tLabelVida.desenhar(10, 30);
	tVida.setString(to_string(this->jogador->getVida()));
	tVida.desenhar(60, 30);

	tLabelMana.setString("Mana: ");
	tLabelMana.desenhar(10, 50);
	tMana.setString(to_string(this->jogador->getMana()));
	tMana.desenhar(75, 50);
}
