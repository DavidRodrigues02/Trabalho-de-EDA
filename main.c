#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "meio.h"
#include "ClientesGestores.h"
#include "autenticacao.h"
#include "menu.h"
#include "grafo.h"


int main() {
	Meio* meios = NULL; // Lista ligada vazia 
	Gestores* gestores = NULL;
	Cliente* clientes = NULL;
	Grafo g = NULL;
	Matriz m = NULL;

	//meios = novoMeio(meios, 5, "carrinha", 95, 100, "disponivel");
	//meios = novoMeio(meios, 6, "skate", 28, 20, "disponivel");
	meios = lerMeios();

	//gestores = novoGestor(gestores, "Daniel", 1234); 
	//gestores = novoGestor(gestores, "Henrique", 5678);
	gestores = lerGestores();

	//clientes = novoCliente(clientes, 123456789, 50, "Paulo", "Lisboa");  
	//clientes = novoCliente(clientes, 987654321, 80, "Carolina", "Porto"); 
	clientes = lerClientes();


	/*novoVertice(&g, "palito-some-atum");
	novoVertice(&g, "moleza-avisou-boiar");
	novoVertice(&g, "cita-noite-cercam");
	novoVertice(&g, "farta-parou-ferro");

	criarAresta(g, "palito-some-atum", "moleza-avisou-boiar", 20);
	criarAresta(g, "palito-some-atum", "farta-parou-ferro", 15);
	criarAresta(g, "moleza-avisou-boiar", "farta-parou-ferro", 50);
	criarAresta(g, "moleza-avisou-boiar", "cita-noite-cercam", 40);
	criarAresta(g, "cita-noite-cercam", "palito-some-atum", 100);
	criarAresta(g, "farta-parou-ferro", "cita-noite-cercam", 30);*/

	//FicheiroGrafo(g); 
	//FicheiroAdjacentes(g);
	
	g = lerGrafo();  
	g = lerAdjacentes(g);
	g = lerCodigosGrafo(g, meios);
	listarAdjacentes(g, "palito-some-atum");
	listarVertices(g); 
	ficheiroBinario(g);

	struct registo array[100];
	int escolha, opcao, cod, pin, nif, bool, v;
	float bat, aut, saldo, custo, distancia, raio;
	char tipo[50], nomeGe[50], nomeCl[50], est[20], morada[50], loc[50], geocodigo[50], origem[50], destino[50];

	do {
		printf("\tA U T E N T I C A C A O\n");
		printf("1. Inicio de sessao para gestores\n");
		printf("2. Inicio de sessao para clientes\n");
		printf("3. Registo de novo cliente\n");
		printf("0. Sair\n");
		printf("Opcao: ");
		scanf("%d", &escolha);

		switch (escolha) {
			// LOGIN PARA GESTORES
		case 1:
			bool = loginGestores(gestores);
			if (bool) {
				do {
					opcao = menuGestor();
					switch (opcao) {
					case 1: printf("\nIntroduza o codigo:\n ");
						scanf("%d", &cod);
						printf("Tipo de meio: \n");
						getchar();
						gets(tipo);
						printf("Nivel de bateria:\n ");
						scanf("%f", &bat);
						printf("Autonomia:\n ");
						scanf("%f", &aut);
						printf("Custo:\n");
						scanf("%f", &custo); 
						printf("Disponivel ou Alugado ?\n");
						getchar();
						gets(est);
						printf("Localizacao ? (nome-nome-nome)\n");
						//getchar();
						gets(loc);

						meios = novoMeio(meios, cod, tipo, bat, aut, est, loc, custo);
						FicheiroMeios(meios);
						inserirMeioGrafo(g, meios, loc, cod);
						FicheiroCodigoGrafo(g);
						break;
					case 2: listarMeios(meios); 
						printf("Codigo do meio que pretende remover: ");
						scanf("%d", &cod);
						meios = RemoverMeio(meios, cod);
						break;
					case 3: FicheiroMeios(meios); 
					    ficheiroBinario(meios);
						break;
					case 4: FicheiroClientes(clientes);
						ficheiroBinarioCl(clientes);
						break;
					case 5: printf("Escreva o nome do novo gestor: ");
						getchar();
						gets(nomeGe);
						printf("Introduza o PIN que deseja utilizar: ");
						scanf("%d", &pin);
						gestores = novoGestor(gestores, nomeGe, pin);
						FicheiroGestores(gestores);
						break;
					case 6: FicheiroGestores(gestores);
						ficheiroBinarioGe(gestores);
						break;
					case 7: listarGestores(gestores); break;
					case 8: listarMeios(meios);
						meios = alterarDados(meios);  
						break;
					case 9: listarClientes(clientes); break;
					case 10: printf("Insira o NIF do cliente que pretende remover: \n");
						scanf("%d", &nif);
						clientes = RemoverCliente(clientes, nif); 
						break;
					case 11: localizacao(meios);break;
					case 12: listarMeios(meios); break;
					case 13: printf("Introduza a nova localizacao: \n");
						getchar();
						gets(geocodigo);
						novoVertice(&g, geocodigo);
						FicheiroGrafo(g);
						break;
					case 14: printf("Localizacao de origem: \n");
						getchar();
						gets(origem);
						printf("Localizacao de destino: \n");
						getchar();
						gets(destino);
						printf("Distancia: \n");
						scanf("%d", &distancia);
						if (existeVertice(g, origem) && existeVertice(g, destino)) criarAresta(g, origem, destino, distancia);
						else printf("Localizacao nao encontrada!");
						break;
					case 15: printf("Insira a localizacao: \n");
						getchar();
						gets(geocodigo);
						printf("Insira o codigo do meio: \n");
						scanf("%d", &cod);
						removerCodigo(g, cod);
						inserirMeioGrafo(g, meios, geocodigo, cod);
						FicheiroMeios(meios);
						FicheiroCodigoGrafo(g);
						break;
					case 16: printf("Insira a localizacao: \n");
						getchar();
						gets(geocodigo);
						listarMeiosGrafo(g, meios, geocodigo);
						break;
					case 17: v = contaVertices(g); 

						matrizInicial(m, v);
						matrizPeso(g, m); 
						printMatriz(m); 
						break;
					}
				} while (opcao != 0);
			}
			else printf("PIN errado!\n");
			break;

			//LOGIN PARA CLIENTES
		case 2: printf("Introduza o NIF: \n");
			scanf("%d", &nif);
			bool = loginCliente(clientes, nif); 
			if (bool) {
				do {
					opcao = menuCliente();
					switch (opcao) {
					case 1:listarMeios(meios); break;
					case 2:ordemDecrescente(meios); break;
					case 3:listarMeios(meios); 
						printf("Introduza o codigo do meio que pretende alugar: \n");
						scanf("%d", cod);
						alugarMeio(meios, clientes, nif, cod); break; 
					case 4: localizacao(meios); break;
					case 5: clientes = alterarDadosCl(clientes, nif); break;
					case 6: printf("Introduza a localizacao: \n");
						getchar();
						gets(geocodigo);
						if (existeVertice(g, geocodigo)) listarAdjacentes(g, geocodigo);
						else printf("Localizacao nao encontrada!");
						break;
					case 7: listarVertices(g); break;
					case 8: printf("Introduza a localizacao onde se encontra: \n");
						getchar();
						gets(geocodigo);
						printf("Introduza o meio que pretende utilizar: \n");
						//getchar();
						gets(tipo);
						printf("Introduza o raio: \n");
						scanf("%f", &raio);
						meiosPerto(g, meios, geocodigo, raio, tipo);
						break;
					}
				} while (opcao != 0);
			}
			else printf("NIF errado!\n");
			break;

			// REGISTO DE CLIENTES
		case 3: printf("Introduza o seu NIF: ");
			scanf("%d", &nif);
			printf("Introduza a quantidade de saldo com que deseja carregar a conta: ");
			scanf("%f", &saldo);
			printf("Escreva o seu nome: ");
			getchar();
			gets(nomeCl); 
			printf("Escreva a sua morada: ");
			//getchar();
			gets(morada); 

			bool = existeCliente(clientes, nif);
			if (bool == 0) {
				clientes = novoCliente(clientes, nif, saldo, nomeCl, morada);
				FicheiroClientes(clientes);

				do {
					opcao = menuCliente();
					switch (opcao) {
					case 1: listarMeios(meios); break;
					case 2: ordemDecrescente(meios); break; 
					case 3: listarMeios(meios);
						printf("Introduza o codigo do meio que pretende alugar: \n");
						scanf("%d", cod);
						alugarMeio(meios, clientes, nif, cod); break;
					case 4: localizacao(meios); break;
					case 5: clientes = alterarDadosCl(clientes, nif); break;
					}
				} while (opcao != 0);
			}
			else printf("NIF ja existe!!\n");
			break;
		}
	} while (escolha != 0);
}

