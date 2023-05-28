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
*  Armazenar informação do grafo num ficheiro binário
*/
int ficheiroBinario(Grafo inicio);

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
int inserirMeioGrafo(Grafo g, Meio* meios, char geocodigo[], int codigoMeio);

/**
*  Listar todos meios existentes numa localização
*/
void listarMeiosGrafo(Grafo g, Meio* meios, char geocodigo[]);

/**
*  Armazena os códigos dos meios e as respetivas localizações
*/
int FicheiroCodigoGrafo(Grafo inicio);

/**
*  Lê os códigos para o grafo
*/
Grafo lerCodigosGrafo(Grafo g, Meio* m);

/**
*  Remove o código de uma localização
*/
void removerCodigo(Grafo g, int codigo);

/**
*  Recebe a localização do cliente, o meio que pretende procurar e o raio. Lista o tipo de meio que encontra nesse raio 
*/
void meiosPerto(Grafo g, Meio* m, char localizacao[], float raio, char tipo[]);

int contaVertices(Grafo g);

void matrizInicial(Matriz matrizAdjacencia, int vertices);

void matrizPeso(Grafo g, Matriz matrizAdj);

void printMatriz(Matriz m);

void matrizFinal(Grafo g, Matriz matriz);