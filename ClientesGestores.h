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

/**
*  Listar os clientes
*/
void listarClientes(Cliente* inicio);

/**
*  Verificar se já existe o cliente
*/
int existeCliente(Cliente* inicio, int nif);

/**
*  Registo de um novo cliente
*/
Cliente* novoCliente(Cliente* inicio, int nif, float saldo, char nome[], char morada[]);

/**
*  Cria um ficheiro de texto para armazenar os clientes
*/
int FicheiroClientes(Cliente* inicio);

/**
*  Cria um ficheiro binário para armazenar os clientes
*/
int ficheiroBinarioCl(Cliente* inicio);

/**
*  Ler os clientes no ficheiro para a lista ligada
*/
Cliente* lerClientes();  

/**
*  Remover algum dos clientes
*/
Cliente* RemoverCliente(Cliente* inicio, int nif);

/**
*  Alterar determinados dados do cliente
*/
Cliente* alterarDadosCl(Cliente* inicio, int nif); 


                             //FUNÇÕES PARA GESTORES

/**
*  Adicionar novo gestor
*/
Gestores* novoGestor(Gestores* inicio, char nome[], int pin); 

/**
*  Verificar se existe o gestor
*/
int existeGestor(Gestores* inicio, int pin);

/**
*  Cria ficheiro de texto dos gestores
*/
int FicheiroGestores(Gestores* inicio);

/**
*  Cria ficheiro binário dos gestores
*/
int ficheiroBinarioGe(Gestores* inicio);

/**
*  Listar os gestores existentes
*/
void listarGestores(Gestores* inicio);

/**
*  Ler os gestores registados no ficheiro de texto para a lista 
*/
Gestores* lerGestores();