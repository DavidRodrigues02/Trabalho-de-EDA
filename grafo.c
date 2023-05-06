#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "grafo.h"

int novoVertice(Grafo* g, char geocodigo[]) {
	Grafo novo = malloc(sizeof(struct registo1));  

	if (novo != NULL) {
		strcpy(novo->geocodigo, geocodigo);
		novo->adjacentes = NULL;
		novo->seguinte = *g;
		*g = novo;

		return 1;
	}
	else return 0;
}

int existeVertice(Grafo g, char geocodigo[]) {
	while (g != NULL) {
	 	if (strcmp(g->geocodigo, geocodigo) == 0) return 1;    
		else g = g->seguinte; 
	}
	return 0;
}

int criarAresta(Grafo g, char origem[], char destino[], float distancia) {
	Adjacente novo;

	if (existeVertice(g, origem) && existeVertice(g, destino)) {
		while (strcmp(g->geocodigo, origem) != 0) g = g->seguinte;
		novo = malloc(sizeof(struct registo1));

		if (novo != NULL) {
			strcpy(novo->geocodigo, destino);
			novo->peso = distancia;  
			novo->seguinte = g->adjacentes;  
			g->adjacentes = novo;
			return 1;
		}
		else return 0;
	}
	else return 0;
}

void listarAdjacentes(Grafo g, char geocodigo[]) {
	Adjacente aux;

	if (existeVertice(g, geocodigo)) {
		while (strcmp(g->geocodigo, geocodigo) != 0) g = g->seguinte; 
		aux = g->adjacentes;

		while (aux != NULL) {
			printf("%s %.2f\n", aux->geocodigo, aux->peso); 
			aux = aux->seguinte;
		}
	}
}


int FicheiroGrafo(Grafo inicio) {
	FILE* fp;
	fp = fopen("vertices.txt", "w");

	if (fp != NULL) {
		Grafo aux = inicio; 

		while (aux != NULL) {
			fprintf(fp, "%s\n", aux->geocodigo); 
			aux = aux->seguinte; 
		}
		fclose(fp);
		return(1);

	}
	else return(0);
}


int FicheiroAdjacentes(Grafo inicio) {
	FILE* fp;
	fp = fopen("adjacentes.txt", "w");

	if (fp != NULL) {
		Grafo g = inicio;

		while (g != NULL) {  

			Adjacente aux = g->adjacentes; 
			while (aux != NULL) { 
				fprintf(fp, "%s; %s; %.2f\n", g->geocodigo, aux->geocodigo, aux->peso); 
				aux = aux->seguinte;
			}
			g = g->seguinte;  
		}
		fclose(fp);
		return(1);

	}
	else return(0);
}


Grafo lerGrafo()
{
	FILE* fp;
	float peso;
	char geocodigo[50];
	char origem[50];
	Grafo aux = NULL;
	Grafo novo; 
	Adjacente aux2 = NULL;
	Adjacente adj;

	fp = fopen("vertices.txt", "r");
	if (fp == NULL) {
		printf("Erro ao abrir ficheiro.");
		return NULL;
	}

	while (fscanf(fp, "%s\n", geocodigo) == 1)
	{
		novo = malloc(sizeof(struct registo1)); 
		if (novo == NULL) { 
			printf("Erro ao alocar memoria.");
			return NULL;
		}
		
		strcpy(novo->geocodigo, geocodigo);
		novo->seguinte = aux;
		novo->adjacentes = NULL;
		aux = novo;
	}
	fclose(fp);

	FILE* fp2 = fopen("adjacentes.txt", "r");

	if (fp2 == NULL) {
		printf("Erro ao abrir ficheiro.");
		return NULL;
	}

	while (fscanf(fp2, "%[^;]; %[^;]; %.2f\n", origem, geocodigo, &peso) == 3)
	{	
		while (strcmp(aux->geocodigo, origem) != 0) aux = aux->seguinte;

		adj = malloc(sizeof(struct registo1));     
		if (adj == NULL) { 
			printf("Erro ao alocar memoria."); 
			return NULL; 
		}

		strcpy(adj->geocodigo, geocodigo);
		adj->peso = peso; 
		adj->seguinte = aux->adjacentes; 
		aux->adjacentes = adj; 
	}
	fclose(fp2);

	return aux;
}