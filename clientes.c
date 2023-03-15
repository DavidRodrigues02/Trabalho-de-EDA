#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"

// FUNÇÕES PARA OS CLIENTES

void listarClientes(Cliente* inicio)
{
	while (inicio != NULL)
	{
		printf("%s %d %.2f %s\n", inicio->nome, inicio->nif, inicio->saldo, inicio->morada);
		inicio = inicio->seguinte;
	}
}

int existeCliente(Cliente* inicio, int nif)
{
	while (inicio != NULL)
	{
		if (inicio->nif == nif) return(1);
		inicio = inicio->seguinte;
	}
	return(0);
}


Cliente* novoCliente(Cliente* inicio, int nif, float saldo, char nome[], char morada[])
{
	if (!existeCliente(inicio, nif))
	{
		Cliente* novo = malloc(sizeof(struct cliente));
		if (novo != NULL)
		{
			novo->nif = nif;
			novo->saldo = saldo;
			strcpy(novo->nome, nome);
			strcpy(novo->morada, morada);
			novo->seguinte = inicio;
			return(novo);
		}
	}
	else return(inicio);
}


Cliente* lerClientes()
{
	FILE* fp;
	int nif;
	float saldo;
	char nome[50], morada[30];
	Cliente* aux = NULL;
	Cliente* novo;

	fp = fopen("clientes.txt", "r");
	if (fp == NULL) {
		printf("Erro ao abrir ficheiro.");
		return NULL;
	}

	while (fscanf(fp, "%[^;];%d;%f;%s\n", nome, &nif, &saldo, morada) == 4)
	{
		novo = malloc(sizeof(Cliente));
		if (novo == NULL) {
			printf("Erro ao alocar memoria.");
			return NULL;
		}
		novo->nif = nif;
		novo->saldo = saldo;
		strcpy(novo->nome, nome);
		strcpy(novo->morada, morada);
		novo->seguinte = aux;
		aux = novo;
	}
	fclose(fp);
	return aux;
}


int FicheiroClientes(Cliente* inicio) {
	FILE* fp;
	fp = fopen("clientes.txt", "w");

	if (fp != NULL) {
		Cliente* aux = inicio;

		while (aux != NULL) {
			fprintf(fp, "%s;%d;%f;%s\n", aux->nome, aux->nif, aux->saldo, aux->morada);
			aux = aux->seguinte;
		}
		fclose(fp);
		return(1);

	}
	else return(0);
}

int ficheiroBinarioCl(Cliente* inicio) {
	FILE* fp;
	fp = fopen("clientesBinario", "wb");

	if (fp != NULL) {
		Cliente* aux = inicio;

		while (aux != NULL) {
			fwrite(&aux, sizeof(struct cliente), 1, fp);
			aux = aux->seguinte;
		}
		fclose(fp);
		return(1);
	}
	else return(0);
}



// FUNÇÕES PARA GESTORES

Gestores* novoGestor(Gestores* inicio, char nome[], int pin) {
	Gestores* novo = malloc(sizeof(struct gestores));
	if (novo != NULL)
	{
		strcpy(novo->nome, nome);
		novo->pin = pin;
		novo->seguinte = inicio;
		return(novo);
	}
	else return(inicio);
}


int existeGestor(Gestores* inicio, int pin)
{
	while (inicio != NULL)
	{
		if (inicio->pin == pin) return(1); 
		inicio = inicio->seguinte; 
	}
	return(0);
}


int FicheiroGestores(Gestores* inicio) {
	FILE* fp;
	fp = fopen("gestores.txt", "w");

	if (fp != NULL) {
		Gestores* aux = inicio;

		while (aux != NULL) {
			fprintf(fp, "%s;%d\n", aux->nome, aux->pin);
			aux = aux->seguinte; 
		}
		fclose(fp);
		return(1);

	}
	else return(0);
}

int ficheiroBinarioGe(Gestores* inicio) {
	FILE* fp;
	fp = fopen("gestoresBinario", "wb");

	if (fp != NULL) {
		Gestores* aux = inicio; 
		 
		while (aux != NULL) {
			fwrite(&aux, sizeof(struct gestores), 1, fp); 
			aux = aux->seguinte; 
		}
		fclose(fp);
		return(1);
	}
	else return(0);
}


void listarGestores(Gestores* inicio)
{
	while (inicio != NULL)
	{
		printf("%s %d\n", inicio->nome, inicio->pin);
		inicio = inicio->seguinte;
	}
}

Gestores* lerGestores()
{
	FILE* fp;
	int pin;
	char nome[50]; 
	Gestores* aux = NULL; 
	Gestores* novo; 

	fp = fopen("gestores.txt", "r");
	if (fp == NULL) {
		printf("Erro ao abrir ficheiro.");
		return NULL;
	}

	while (fscanf(fp, "%[^;];%d\n", nome, &pin) == 2)
	{
		novo = malloc(sizeof(Gestores)); 
		if (novo == NULL) {
			printf("Erro ao alocar memoria.");
			return NULL;
		}
		strcpy(novo->nome, nome);  
		novo->pin = pin; 

		novo->seguinte = aux;
		aux = novo;
	}
	fclose(fp);
	return aux;
}