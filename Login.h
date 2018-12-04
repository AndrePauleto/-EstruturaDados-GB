#pragma once
#include "libUnicornio.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include "Usuario.h"

using namespace std;

class Login
{
public:
	Login();
	~Login();
	int buscarUsuario(Usuario *& usuario);
private:
	bool autenticar();
	void buscarSaves();
	string caminhoArquivoUsuarios = "usuarios/usuarios.txt";
	Usuario * usuario;
};

