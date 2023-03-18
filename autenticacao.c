#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#include "autenticacao.h"
#include "ClientesGestores.h"

// AUTENICA��O PARA CLIENTES

int loginCliente(Cliente* inicio, int nif) {

	int boolean;

	boolean = existeCliente(inicio, nif);
	
	return boolean;

}



// AUTENTICA��O PARA GESTORES

int loginGestores(Gestores* inicio) {
	int pin, boolean; 

	printf("Introduza o seu pin de gestor: ");
	scanf("%d", &pin);

	boolean = existeGestor(inicio, pin); 

	return boolean; 
}