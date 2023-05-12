#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "grafo.h"
#include "meio.h"

int novoVertice(Grafo* g, char geocodigo[]) {
	Grafo novo = malloc(sizeof(struct registo1));  

	if (novo != NULL) {
		strcpy(novo->geocodigo, geocodigo);
		novo->adjacentes = NULL;
		novo->meios = NULL;
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

void listarVertices(Grafo g) {
	Grafo aux = g;

	while (aux != NULL) {
		printf("%s\n", aux->geocodigo);
		aux = aux->seguinte;
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
				fprintf(fp, "%s;%s;%.2f\n", g->geocodigo, aux->geocodigo, aux->peso); 
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
	//Adjacente aux2 = NULL;
	//Adjacente adj;

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
		novo->meios = NULL;
		aux = novo;
	}
	fclose(fp);

	return aux;
}

Grafo lerAdjacentes(Grafo g) {
	FILE* fp;
	char origem[50], destino[50];
	float distancia = 0;
	
	fp = fopen("adjacentes.txt", "r");

	if (fp == NULL) {
		printf("Erro ao abrir ficheiro.");
		return NULL;
	}

	while (fscanf(fp, "%[^;];%[^;];%f\n", origem, destino, &distancia) == 3) {
		
		criarAresta(g, origem, destino, distancia); 

	}
	fclose(fp);

	return g;  
}

int inserirMeio(Grafo g, Meio* m, char geocodigo[], int codigoMeio){

	while ((g != NULL) && (strcmp(g->geocodigo, geocodigo) != 0)) g = g->seguinte;

	if (g == NULL) return(0);
	else {
		
		MeiosCodigo novo = malloc(sizeof(struct registo3));
		novo->codigo = codigoMeio;
		novo->seguinte = g->meios;
		g->meios = novo;
		m = alterarLocalizacao(m, geocodigo, codigoMeio);
		
		return(1);
	}
}

void listarMeiosGrafo(Grafo g, Meio* meios, char geocodigo[]){

	while ((g != NULL) && (strcmp(g->geocodigo, geocodigo) != 0)) g = g->seguinte;

	if (g != NULL)
	{
		MeiosCodigo aux = g->meios;
		if (aux == NULL) printf("Sem meios de transporte!\n");
		else while (aux != NULL)
		{
			while ((meios != NULL) && (meios->codigo != aux->codigo)) meios = meios->seguinte;


				printf("------------\nCodigo do meio: %d\nTransporte: %s\nBateria: %.2f\nAutonomia: %.2f\nCusto: %.2f\nEstado: %s\n----------------\n", aux->codigo, meios->tipo, meios->bateria, meios->autonomia, meios->custo, meios->estado); 
				aux = aux->seguinte;
			
		}
	}
	else printf("Geocodigo inexistente!\n");
}

Meio* alterarLocalizacao(Meio* meios, char geocodigo[], int codigo) {
	Meio* atual = meios;

		while ((atual != NULL) && (atual->codigo != codigo)) atual = atual->seguinte;  // para encontrar o codigo introduzido pelo utilizador
		
		if (atual != NULL) {
			strcpy(atual->localizacao, geocodigo);
			
		}
		 
		return atual;
}

int FicheiroCodigoGrafo(Grafo inicio) {
	FILE* fp; 
	fp = fopen("MeiosCodigoGrafo.txt", "w");

	if (fp != NULL) {
		Grafo g = inicio;

		while (g != NULL) {

			MeiosCodigo aux = g->meios;
			while (aux != NULL) {
				fprintf(fp, "%s;%d\n", g->geocodigo, aux->codigo);
				aux = aux->seguinte;
			}
			g = g->seguinte;
		}
		fclose(fp);
		return(1);

	}
	else return(0);
}

Grafo lerCodigosGrafo(Grafo g, Meio* m) {
	FILE* fp; 
	char geocodigo[50];
	int codigo;

	fp = fopen("MeiosCodigoGrafo.txt", "r");

	if (fp == NULL) {
		printf("Erro ao abrir ficheiro.");
		return NULL;
	}

	while (fscanf(fp, "%[^;];%d\n", geocodigo, &codigo) == 2) {

		inserirMeio(g, m, geocodigo, codigo);

	}
	fclose(fp);

	return g;
}

void removerCodigo(Grafo g, int codigo) { 
	while (g != NULL) { 
		MeiosCodigo anterior = NULL;  
		MeiosCodigo atual = g->meios; 

		while (atual != NULL && atual->codigo != codigo) {  //ciclo para procurar o n� onde se encontra o codigo
			anterior = atual; 
			atual = atual->seguinte; 
		}

		if (atual != NULL) {
			if (anterior == NULL) {                          //caso o codigo esteja no primeiro n�
				g->meios = atual->seguinte;
			}
			else {                                           //caso o c�digo esteja noutro n�
				anterior->seguinte = atual->seguinte;        //mete o n� anterior a apontar para o n� a seguir ao atual
			}                                                // e de seguida elimina o atual 

			free(atual);
			return;
		}

		g = g->seguinte;
	}
}


int verificarCodigo(Grafo g, int codigo) {  
	MeiosCodigo aux = g->meios;

	while (g != NULL) {
		while (aux != NULL) {
			if (aux->codigo == codigo) return 1;
			else aux = aux->seguinte;
		}
		g = g->seguinte;
	} 
	return 0;
}

int meiosPerto(Grafo g, Meio* m, char localizacao[], int raio, char tipo[]) {

}