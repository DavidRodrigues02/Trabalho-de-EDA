#pragma once
#include "meio.h"

typedef struct registo2
{
	char geocodigo[40];
	float peso;
	struct registo2* seguinte;
} *Adjacente;

typedef struct registo3
{
	int codigo;
	struct registo3* seguinte;
} *MeiosCodigo;

typedef struct registo1
{
	char geocodigo[40];
	Adjacente adjacentes;
	MeiosCodigo meios;
	struct registo1* seguinte;
} *Grafo;

/**
*  Criar novo vértice para o grafo
*/
int novoVertice(Grafo* g, char geocodigo[]);

/**
*  Verificar a existência de um vértice
*/
int existeVertice(Grafo g, char geocodigo[]);

/**
*  Criar aresta/ligação para o grafo
*/
int criarAresta(Grafo g, char origem[], char destino[], float distancia);

/**
*  Listar vértices adjacentes a um determinado vértice
*/
void listarAdjacentes(Grafo g, char geocodigo[]);

/**
*  Listar os vértices existentes no grafo
*/
void listarVertices(Grafo g);

/**
*  Armazenar vértices do grafo num ficheiro de texto
*/
int FicheiroGrafo(Grafo inicio);

/**
*  Armazenar os vértices adjacentes do grafo num ficheiro de texto
*/
int FicheiroAdjacentes(Grafo inicio);

/**
*  Ler os vértices guardados em ficheiro para o grafo
*/
Grafo lerGrafo();

/**
*  Ler os vértices adjacentes guardados em ficheiro para o grafo
*/
Grafo lerAdjacentes(Grafo g);

/**
*  Inserir meio numa determinada localização
*/
int inserirMeio(Grafo g, Meio* meios, char geocodigo[], int codigoMeio);

/**
*  Listar todos meios existentes numa localização
*/
void listarMeiosGrafo(Grafo g, Meio* meios, char geocodigo[]);

/**
*  Alterar a localização do meio na estrutura dos Meios 
*/
Meio* alterarLocalizacao(Meio* meios, char geocodigo[], int codigo);

int FicheiroCodigoGrafo(Grafo inicio);

Grafo lerCodigosGrafo(Grafo g, Meio* m);

void removerCodigo(Grafo g, int codigo);

int verificarCodigo(Grafo g, int codigo);

void meiosPerto(Grafo g, Meio* m, char localizacao[], int raio, char tipo[]);