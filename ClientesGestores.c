#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ClientesGestores.h"

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
	else  return(inicio);
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



Cliente* RemoverCliente(Cliente *inicio, int nif) {
	Cliente* anterior = inicio, *atual = inicio, *aux;
	
	if (inicio == NULL) return(NULL);
	else if (inicio->nif == nif) {  //remove o primeiro node caso este tenha o codigo desejado
		aux = inicio;
		inicio = inicio->seguinte;
		free(aux);  
		return(inicio);  

	}
	else {
		while ((inicio != NULL) && (inicio->nif != nif)) {  //percorre a lista ligada até encontrar o codigo do meio
			anterior = inicio;
			inicio = inicio->seguinte; 
		}

		if (inicio == NULL) return(inicio);
		else {
			anterior->seguinte = inicio->seguinte; //mete o pointer do campo "seguinte" do node "anterior"
			free(inicio);                          // a apontar para o node a seguir ao node "atual" e elimina o node central
			return(anterior);
		}
	}

}


Cliente* alterarDadosCl(Cliente* inicio, int nif) {
	Cliente* atual = inicio;
	int opcao;
	float saldo;
	char nome[50], morada[50];

	
	if (atual == NULL) return(NULL);
	else if (atual->nif == nif) {   // caso o header tenha o codigo introduzido


		do {
			printf("1 - Saldo\n2 - nome\n3 - Morada\n0 - Sair\n");
			printf("Escolha a opcao: \n");
			scanf("%d", &opcao);
			switch (opcao) {

			case 1: printf("Insira o novo saldo: \n");
				scanf("%d", &saldo);
				atual->saldo = saldo;
				break;
			case 2: printf("Insira o novo nome: \n");
				getchar();
				gets(nome);
				strcpy(atual->nome, nome);
				break;
			case 3: printf("Insira a nova morada: \n");
				getchar();
				gets(morada);
				strcpy(atual->morada, morada);
				break;
			}
		} while (opcao != 0);
	}
	else {
		while ((atual != NULL) && (atual->nif != nif)) {   // para encontrar o codigo introduzido
			atual = atual->seguinte;
		}
		if (atual == NULL) return(inicio);
		else {

			do {
				printf("1 - Saldo\n2 - nome\n3 - Morada\n0 - Sair\n");
				printf("Escolha a opcao: \n");
				scanf("%d", &opcao);

				switch (opcao) {
				case 1: printf("Insira o novo saldo: ");
					scanf("%d", &saldo);
					atual->saldo = saldo;
					break;
				case 2: printf("Insira o novo nome: ");
					getchar();
					gets(nome);
					strcpy(atual->nome, nome);
					break;
				case 3: printf("Insira a nova morada: ");
					getchar();
					gets(morada);
					strcpy(atual->morada, morada);
					break;
				}
			} while (opcao != 0);
		}
	}
	FicheiroClientes(atual); 
	return (atual);
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
		printf("%s \n", inicio->nome);
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

