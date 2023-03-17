#pragma once
#include<stdio.h>


typedef struct cliente {
	int nif;
	float saldo;
	char nome[50];
	char morada[50];
	struct cliente* seguinte; // endere�o de mem�ria para o pr�ximo elemento da lista
} Cliente;


typedef struct gestores {
	char nome[50];
	int pin;
	struct gestores* seguinte;
} Gestores;


                              //FUN��ES PARA CLIENTES

// Listar clientes
void listarClientes(Cliente* inicio);

// Verificar se j� existe o cliente
int existeCliente(Cliente* inicio, int nif);

// Registo de um novo cliente
Cliente* novoCliente(Cliente* inicio, int nif, float saldo, char nome[], char morada[]);

// Cria um ficheiro de texto para armazenar os clientes
int FicheiroClientes(Cliente* inicio);

// Cria um ficheiro bin�rio para armazenar os clientes
int ficheiroBinarioCl(Cliente* inicio);

// Ler os clientes no ficheiro para a lista ligada
Cliente* lerClientes();  

// Remover cliente
Cliente* RemoverCliente(Cliente* inicio, int nif);

Cliente* alterarDadosCl(Cliente* inicio);


                             //FUN��ES PARA GESTORES


Gestores* novoGestor(Gestores* inicio, char nome[], int pin); 

int existeGestor(Gestores* inicio, int pin);

int FicheiroGestores(Gestores* inicio);

int ficheiroBinarioGe(Gestores* inicio);

void listarGestores(Gestores* inicio);

Gestores* lerGestores();