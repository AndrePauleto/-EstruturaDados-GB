#include "TelaCadastro.h"



TelaCadastro::TelaCadastro()
{
}


TelaCadastro::~TelaCadastro()
{
}

void TelaCadastro::aoEntrar()
{
	this->desenharInput = true;
	this->cadastro->setUsuario("");
	this->cadastro->setSenha("");
	this->input.inicializar();

	this->tLabelLogin.setAncora(0, 0.5);
	this->tLabelLogin.setFonte("fonte");
	this->tLabelLogin.setCor(255, 215, 0);
	this->tLabelLogin.setString("USER: ");

	this->tMensagemErro.setAncora(0, 0.5);
	this->tMensagemErro.setFonte("fonte");
	this->tMensagemErro.setCor(217, 83, 79);
	this->tMensagemErro.setEscala(0.8, 0.8);
	this->tMensagemErro.setString("Error to register. \nUser already exists. \nPlease, try another user.");

	this->tMensagemSucesso.setAncora(0, 0.5);
	this->tMensagemSucesso.setFonte("fonte");
	this->tMensagemSucesso.setCor(92, 184, 92);
	this->tMensagemSucesso.setEscala(0.8, 0.8);
	this->tMensagemSucesso.setString("Registered successfully.\n Please, return to login menu.");

	this->bRegistrar.setSpriteSheet("bRegister");
	this->bRegistrar.getSprite()->setEscala(0.5, 0.5);
	this->bRegistrar.setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2 + 100);

	this->bVoltar.setSpriteSheet("bBack");
	this->bVoltar.getSprite()->setEscala(0.5, 0.5);
	this->bVoltar.setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2 + 150);
}

void TelaCadastro::aoSair()
{
}

void TelaCadastro::aoAtualizar(float dt)
{

	if (bVoltar.estaClicado()) {
		getMaquinaDeEstadosComPilha()->desempilharEstado();
	}

	//Caso pressione o botão Registrar e esteja com os campos de Usuario e Senha preenchidos, realizamos o registro
	if (bRegistrar.estaClicado() && !empty(this->cadastro->getUsuario()) && !empty(this->cadastro->getSenha())) {
		if (this->cadastro->registrar()) {
			this->mensagemSucesso = true;
			// GAMBIS PRA OCULTAR O BOTAO
			this->bRegistrar.setX(gJanela.getLargura() + this->bRegistrar.getSprite()->getLargura());
			this->bRegistrar.setY(gJanela.getAltura() + this->bRegistrar.getSprite()->getAltura());
		} else {
			this->erro = true;
			this->cadastro->setUsuario("");
			this->cadastro->setSenha("");
			this->tLabelLogin.setString("USER: ");
			this->desenharInput = true;
		}
	}

	// Controle para adicionar os textos do input nas propriedades do usuário e senha
	if (gTeclado.pressionou[TECLA_ENTER2] || gTeclado.pressionou[TECLA_ENTER]) {

		if (empty(this->cadastro->getUsuario())) {
			this->cadastro->setUsuario(this->input.getTexto().getString());
			this->tLabelLogin.setString("PASS: ");
		}
		else if (empty(this->cadastro->getSenha())) {
			this->cadastro->setSenha(this->input.getTexto().getString());
			this->desenharInput = false;
			this->tLabelLogin.setString("PRESS THE REGISTER BUTTON");
		}

		this->input.limparTexto();
	}

	input.atualizar();

	this->bRegistrar.atualizar();
	this->bVoltar.atualizar();
	this->aoDesenhar();
}

void TelaCadastro::aoDesenhar()
{
	if (this->desenharInput) {
		input.desenhar();
	}

	this->tLabelLogin.desenhar(gJanela.getLargura() / 2 - 150, gJanela.getAltura() / 2 - 100);
	this->bRegistrar.desenhar();
	this->bVoltar.desenhar();
	this->desenharMensagem();
}

/*
* Desenha a mensagem de erro ou sucesso ao realizar o cadastro
*/
void TelaCadastro::desenharMensagem()
{
	if (this->erro || this->mensagemSucesso) {
		if (this->erro) {
			tMensagemErro.desenhar(gJanela.getLargura() / 2 - 150, gJanela.getAltura() / 2 - 150);
		} else {
			tMensagemSucesso.desenhar(gJanela.getLargura() / 2 - 150, gJanela.getAltura() / 2 - 150);
		}
		
		this->duracaoMensagem--;
		if (this->duracaoMensagem <= 0) {
			this->duracaoMensagem = 500;
			this->erro = false;
		}
	}
}
