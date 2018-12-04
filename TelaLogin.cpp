#include "TelaLogin.h"



TelaLogin::TelaLogin()
{
}


TelaLogin::~TelaLogin()
{
}

void TelaLogin::aoEntrar()
{
	this->usuario = new Usuario();
	this->desenharInput = true;
	this->usuario->setUsuario("");
	this->usuario->setSenha("");
	this->input.inicializar();
	
	this->tLabelLogin.setAncora(0, 0.5);
	this->tLabelLogin.setFonte("fonte");
	this->tLabelLogin.setCor(255, 215, 0);
	this->tLabelLogin.setString("USER: ");


	this->tMensagemErro.setAncora(0, 0.5);
	this->tMensagemErro.setFonte("fonte");
	this->tMensagemErro.setCor(217, 83, 79);
	this->tMensagemErro.setEscala(0.8, 0.8);
	this->tMensagemErro.setString("User or password is incorrect. \nPlease, try again.");

	bLogin.setSpriteSheet("bLogin");
	bLogin.getSprite()->setEscala(0.5, 0.5);
	bLogin.setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2 + 50);

	bRegistrar.setSpriteSheet("bRegister");
	bRegistrar.getSprite()->setEscala(0.5, 0.5);
	bRegistrar.setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2 + 100);

	bSair.setSpriteSheet("bSair");
	bSair.getSprite()->setEscala(0.5, 0.5);
	bSair.setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2 + 150);
}

void TelaLogin::aoAtualizar(float dt)
{
	if (bLogin.estaClicado()) {

		if (login->buscarUsuario(this->usuario)) {
			getMaquinaDeEstadosComPilha()->empilharEstado(new TelaMenu(this->usuario));
		}
		else {
			this->usuario->setUsuario("");
			this->usuario->setSenha("");
			this->tLabelLogin.setString("USER: ");
			this->erro = true;
			this->desenharInput = true;
		}
	}

	if (bRegistrar.estaClicado()) {
		getMaquinaDeEstadosComPilha()->empilharEstado(new TelaCadastro);
	}

	if (bSair.estaClicado()) {
		getMaquinaDeEstadosComPilha()->desempilharEstado();
	}

	if (gTeclado.pressionou[TECLA_ENTER2] || gTeclado.pressionou[TECLA_ENTER]) {
	
		if (empty(this->usuario->getUsuario())) {
			this->usuario->setUsuario(this->input.getTexto().getString());
			this->tLabelLogin.setString("PASS: ");
		} else if (empty(this->usuario->getSenha())) {
			this->usuario->setSenha(this->input.getTexto().getString());
			this->desenharInput = false;
			this->tLabelLogin.setString("PRESS THE LOGIN BUTTON");
		}

		this->input.limparTexto();
	}

	input.atualizar();

	bRegistrar.atualizar();
	bSair.atualizar();
	bLogin.atualizar();
	aoDesenhar();
}

void TelaLogin::aoSair()
{
}

void TelaLogin::aoDesenhar()
{
	desenharMensagemErro();
	
	if (this->desenharInput) {
		input.desenhar();
	}

	this->tLabelLogin.desenhar(gJanela.getLargura() / 2 - 150, gJanela.getAltura() / 2 - 100);
	bSair.desenhar();
	bLogin.desenhar();
	bRegistrar.desenhar();
}

void TelaLogin::desenharMensagemErro()
{
	if (this->erro) {
		tMensagemErro.desenhar(gJanela.getLargura() / 2 - 150, gJanela.getAltura() / 2 - 150);
		this->duracaoMensagemErro--;
		if (this->duracaoMensagemErro <= 0) {
			this->duracaoMensagemErro = 500;
			this->erro = false;
		}
	}
}
