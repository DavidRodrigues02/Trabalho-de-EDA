#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include "meio.h"
#include "ClientesGestores.h"
#include "autenticacao.h"
#include "menu.h"


int main() {
	Meio* meios = NULL; // Lista ligada vazia 
	Gestores* gestores = NULL;
	Cliente* clientes = NULL;

	//meios = novoMeio(meios, 5, "carrinha", 95, 100, "disponivel");
	//meios = novoMeio(meios, 6, "skate", 28, 20, "disponivel");
	meios = lerMeios();

	//gestores = novoGestor(gestores, "Daniel", 1234); 
	//gestores = novoGestor(gestores, "Henrique", 5678);
	gestores = lerGestores();

	//clientes = novoCliente(clientes, 123456789, 50, "Paulo", "Lisboa");  
	//clientes = novoCliente(clientes, 987654321, 80, "Carolina", "Porto"); 
	clientes = lerClientes();
	
	

	int escolha, opcao, cod, pin, nif, bool;
	float bat, aut, saldo, custo;
	char tipo[50], nomeGe[50], nomeCl[50], est[20], morada[50], loc[50];

	do {
		printf("\tA U T E N T I C A C A O\n");
		printf("1. Inicio de sessao para gestores\n");
		printf("2. Inicio de sessao para clientes\n");
		printf("3. Registo de novo cliente\n");
		printf("0. Sair\n");
		printf("Opcao: ");
		scanf("%d", &escolha);

		switch (escolha) {
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
					case 11: localizacao(meios);
						break;
					case 12: listarMeios(meios); break;
					}
				} while (opcao != 0);
			}
			else printf("PIN errado!\n");
			break;

		case 2: printf("Introduza o NIF: \n");
			scanf("%d", &nif);
			bool = loginCliente(clientes, nif); 
			if (bool) {
				do {
					opcao = menuCliente();
					switch (opcao) {
					case 1:listarMeios(meios); break;
					case 2: ordemDecrescente(); break;
					case 3: alugarMeio(meios, clientes, nif); break;
					case 4: localizacao(meios); break;
					case 5: clientes = alterarDadosCl(clientes, nif); break;
					}
				} while (opcao != 0);
			}
			else printf("NIF errado!\n");
			break;
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
					case 2: ordemDecrescente(); break;
					case 3: alugarMeio(meios, clientes, nif); break;
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

