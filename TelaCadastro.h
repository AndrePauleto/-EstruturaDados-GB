#pragma once
#include "Tela.h"
#include "InputTexto.h"
#include "Cadastro.h"

class TelaCadastro :
	public Tela
{
public:
	TelaCadastro();
	~TelaCadastro();
	void aoEntrar();
	void aoSair();
	void aoAtualizar(float dt);
	void aoDesenhar();
private:
	BotaoSprite bRegistrar, bVoltar;
	InputTexto input;
	Cadastro * cadastro = new Cadastro();
	Texto tLabelLogin, tMensagemErro, tMensagemSucesso;
	bool desenharInput = true, erro = false, mensagemSucesso = false;
	void desenharMensagem();
	int duracaoMensagem = 500;
};

