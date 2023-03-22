#pragma once
#include<stdio.h>
#include"ClientesGestores.h"

typedef struct registo
{
	int codigo; // código do meio de mobilidade elétrica
	char tipo[50], estado[20];
	float bateria;
	float autonomia, custo;
	char localizacao[50];
	struct registo* seguinte; // endereço de memória para o próximo elemento da lista
} Meio;


/**
*  Listar todos meios existentes na lista
*/
void listarMeios(Meio* inicio);

/**
*  Verifica se já existe um determinado meio na lista
* a partir do código introduzido pelo utilizador
*/ 
int existeMeio(Meio* inicio, int codigo);

/**
*  Insere novos meios na lista recebendo dados inseridos pelo gestor
*/
Meio* novoMeio(Meio* inicio, int cod, char tipo[], float bat, float aut, char est[], char loc[], float custo);

/**
*  Recebe o código do meio e remove-o da lista
*/
Meio* RemoverMeio(Meio* inicio, int cod);

/**
*  Função para alterar os dados de algum dos meios existentes
*/
Meio* alterarDados(Meio* inicio);

/**
*  Cria ficheiro de texto dos meios
*/ 
int FicheiroMeios(Meio* inicio);

/**
*  Ler ficheiro de texto para a lista
*/ 
Meio* lerMeios();

/**
*  Ordem decrescente dos meios segundo a sua autonomia
*/ 
void ordemDecrescente();

/**
*  Cria ficheiro binário dos meios
*/
int ficheiroBinario(Meio* inicio);

/**
*  Alugar meio e retirar o custo do veiculo ao saldo da conta do cliente
*/
void alugarMeio(Meio* inicio, Cliente* begin, int nif);

/**
*  Procurar meios numa determinada localização 
*/
void localizacao(Meio* inicio);