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



// Listar todos meios existentes
void listarMeios(Meio* inicio);

// Verifica se já existe meio 
int existeMeio(Meio* inicio, int codigo);

// Acrescentar novos meios
Meio* novoMeio(Meio* inicio, int cod, char tipo[], float bat, float aut, char est[], char loc[], float custo);

// Remover meio
Meio* RemoverMeio(Meio* inicio, int cod);

// Alterar dados
Meio* alterarDados(Meio* inicio);

// Criar ficheiro
int FicheiroMeios(Meio* inicio);

// Ler ficheiro
Meio* lerMeios();

// Ordem decrescente
void ordemDecrescente();

// Criar ficheiro binário dos meios
int ficheiroBinario(Meio* inicio);

void alugarMeio(Meio* inicio, Cliente* begin, int nif);

void localizacao(Meio* inicio);