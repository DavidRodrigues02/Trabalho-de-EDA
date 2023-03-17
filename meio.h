#pragma once
#include<stdio.h>

typedef struct registo
{
	int codigo; // c�digo do meio de mobilidade el�trica
	char tipo[50], estado[20];
	float bateria;
	float autonomia;
	char localizacao[50];
	struct registo* seguinte; // endere�o de mem�ria para o pr�ximo elemento da lista
} Meio;



// Listar todos meios existentes
void listarMeios(Meio* inicio);

// Verifica se j� existe meio 
int existeMeio(Meio* inicio, int codigo);

// Acrescentar novos meios
Meio* novoMeio(Meio* inicio, int cod, char tipo[], float bat, float aut, char est[], char loc[]);

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

// Criar ficheiro bin�rio dos meios
int ficheiroBinario(Meio* inicio);

void alugarMeio(Meio* inicio);

void localizacao(Meio* inicio);