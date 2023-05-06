#pragma once

typedef struct registo2
{
	char geocodigo[40];
	float peso;
	struct registo2* seguinte;
} *Adjacente;

typedef struct registo1
{
	char geocodigo[40];
	Adjacente adjacentes;
	struct registo1* seguinte;
} *Grafo;


int novoVertice(Grafo* g, char geocodigo[]);

int existeVertice(Grafo g, char geocodigo[]);

int criarAresta(Grafo g, char origem[], char destino[], float distancia);

void listarAdjacentes(Grafo g, char geocodigo[]);

int FicheiroGrafo(Grafo inicio);

int FicheiroAdjacentes(Adjacente inicio);

Grafo lerGrafo();