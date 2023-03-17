#pragma once
#include<stdio.h>


typedef struct cliente {
	int nif;
	float saldo;
	char nome[50];
	char morada[50];
	struct cliente* seguinte; // endereço de memória para o próximo elemento da lista
} Cliente;


typedef struct gestores {
	char nome[50];
	int pin;
	struct gestores* seguinte;
} Gestores;


                              //FUNÇÕES PARA CLIENTES

// Listar clientes
void listarClientes(Cliente* inicio);

// Verificar se já existe o cliente
int existeCliente(Cliente* inicio, int nif);

// Registo de um novo cliente
Cliente* novoCliente(Cliente* inicio, int nif, float saldo, char nome[], char morada[]);

// Cria um ficheiro de texto para armazenar os clientes
int FicheiroClientes(Cliente* inicio);

// Cria um ficheiro binário para armazenar os clientes
int ficheiroBinarioCl(Cliente* inicio);

// Ler os clientes no ficheiro para a lista ligada
Cliente* lerClientes();  

// Remover cliente
Cliente* RemoverCliente(Cliente* inicio, int nif);

Cliente* alterarDadosCl(Cliente* inicio);


                             //FUNÇÕES PARA GESTORES


Gestores* novoGestor(Gestores* inicio, char nome[], int pin); 

int existeGestor(Gestores* inicio, int pin);

int FicheiroGestores(Gestores* inicio);

int ficheiroBinarioGe(Gestores* inicio);

void listarGestores(Gestores* inicio);

Gestores* lerGestores();