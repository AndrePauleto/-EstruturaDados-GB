#pragma once
#include "Tela.h"
#include "TelaMenu.h"
#include "TelaCadastro.h"
#include "Login.h"
#include "Usuario.h"
#include "InputTexto.h"

class TelaLogin :
	public Tela
{
public:
	TelaLogin();
	~TelaLogin();

	void aoEntrar();
	void aoSair();
	void aoAtualizar(float dt);
	void aoDesenhar();

protected:
	BotaoSprite bLogin, bRegistrar, bSair;
	Usuario * usuario = new Usuario();
	Login * login = new Login();
	InputTexto input;
	Texto tLabelLogin, tMensagemErro;
	bool erro = false, desenharInput = true;
	int duracaoMensagemErro = 500;
	
	void desenharMensagemErro();
};

