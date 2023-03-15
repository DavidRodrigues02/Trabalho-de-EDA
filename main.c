#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include "meio.h"
#include "clientes.h"
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
	float bat, aut, saldo;
	char tipo[50], nomeGe[50], nomeCl[50], est[20], morada[50];

	do {
		printf("A U T E N T I C A C A O\n");
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
					case 1: printf("Introduza o codigo:\n ");
						scanf("%d", &cod);
						printf("Tipo de meio: \n");
						getchar();
						gets(tipo);
						printf("Nivel de bateria:\n ");
						scanf("%f", &bat);
						printf("Autonomia:\n ");
						scanf("%f", &aut);
						printf("Disponivel ou Alugado ?");
						getchar();
						gets(est); 

						meios = novoMeio(meios, cod, tipo, bat, aut, est);
						break;
					case 2:  printf("Codigo do meio que pretende remover: ");
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
						break;
					case 6: FicheiroGestores(gestores);
						ficheiroBinarioGe(gestores);
						break;
					case 7: listarGestores(gestores); break;
					case 8: listarMeios(meios);
						printf("Introduza o codigo:\n ");
						scanf("%d", &cod);
						printf("Tipo de meio: \n");
						getchar();
						gets(tipo);
						printf("Nivel de bateria:\n ");
						scanf("%f", &bat);
						printf("Autonomia:\n ");
						scanf("%f", &aut);
						printf("Disponivel ou Alugado ?");
						getchar();
						gets(est); 

						alterarDados(meios, cod, tipo, bat, aut, est);
					case 9: listarClientes(clientes);
					}
				} while (opcao != 0);
			}
			else printf("PIN errado!\n");
			break;

		case 2: bool = loginCliente(clientes); 
			if (bool) {
				do {
					opcao = menuCliente();
					switch (opcao) {
					case 1:listarMeios(meios); break;
					case 2: ordemDecrescente(); break;
					case 3: alugarMeio(meios); break;
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
			getchar();
			gets(morada); 

			clientes = novoCliente(clientes, nif, saldo, nomeCl, morada); 
			
				do {
					opcao = menuCliente();
					switch (opcao) {
					case 1: listarMeios(meios); break;
					case 2: ordemDecrescente(); break;
					case 3: alugarMeio(meios); break;
					}
				} while (opcao != 0);
			
			break;
		}
	} while (escolha != 0);
}

