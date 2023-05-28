#pragma once
#include "meio.h"

typedef struct {
	int vertices;
	float matrizAdj[100][100];
} *Matriz; 

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
*  Armazenar informa��o do grafo num ficheiro bin�rio
*/
int ficheiroBinario(Grafo inicio);

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
int inserirMeioGrafo(Grafo g, Meio* meios, char geocodigo[], int codigoMeio);

/**
*  Listar todos meios existentes numa localiza��o
*/
void listarMeiosGrafo(Grafo g, Meio* meios, char geocodigo[]);

/**
*  Armazena os c�digos dos meios e as respetivas localiza��es
*/
int FicheiroCodigoGrafo(Grafo inicio);

/**
*  L� os c�digos para o grafo
*/
Grafo lerCodigosGrafo(Grafo g, Meio* m);

/**
*  Remove o c�digo de uma localiza��o
*/
void removerCodigo(Grafo g, int codigo);

/**
*  Recebe a localiza��o do cliente, o meio que pretende procurar e o raio. Lista o tipo de meio que encontra nesse raio 
*/
void meiosPerto(Grafo g, Meio* m, char localizacao[], float raio, char tipo[]);

int contaVertices(Grafo g);

void matrizInicial(Matriz matrizAdjacencia, int vertices);

void matrizPeso(Grafo g, Matriz matrizAdj);

void printMatriz(Matriz m);

void matrizFinal(Grafo g, Matriz matriz);