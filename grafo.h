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
*  Criar novo v�rtice para o grafo
*/
int novoVertice(Grafo* g, char geocodigo[]);

/**
*  Verificar a exist�ncia de um v�rtice
*/
int existeVertice(Grafo g, char geocodigo[]);

/**
*  Criar aresta/liga��o para o grafo
*/
int criarAresta(Grafo g, char origem[], char destino[], float distancia);

/**
*  Listar v�rtices adjacentes a um determinado v�rtice
*/
void listarAdjacentes(Grafo g, char geocodigo[]);

/**
*  Listar os v�rtices existentes no grafo
*/
void listarVertices(Grafo g);

/**
*  Armazenar v�rtices do grafo num ficheiro de texto
*/
int FicheiroGrafo(Grafo inicio);

/**
*  Armazenar os v�rtices adjacentes do grafo num ficheiro de texto
*/
int FicheiroAdjacentes(Grafo inicio);

/**
*  Ler os v�rtices guardados em ficheiro para o grafo
*/
Grafo lerGrafo();

/**
*  Ler os v�rtices adjacentes guardados em ficheiro para o grafo
*/
Grafo lerAdjacentes(Grafo g);

/**
*  Inserir meio numa determinada localiza��o
*/
int inserirMeio(Grafo g, Meio* meios, char geocodigo[], int codigoMeio);

/**
*  Listar todos meios existentes numa localiza��o
*/
void listarMeiosGrafo(Grafo g, Meio* meios, char geocodigo[]);

/**
*  Alterar a localiza��o do meio na estrutura dos Meios 
*/
Meio* alterarLocalizacao(Meio* meios, char geocodigo[], int codigo);

int FicheiroCodigoGrafo(Grafo inicio);

Grafo lerCodigosGrafo(Grafo g, Meio* m);

void removerCodigo(Grafo g, int codigo);

int verificarCodigo(Grafo g, int codigo);

void meiosPerto(Grafo g, Meio* m, char localizacao[], int raio, char tipo[]);