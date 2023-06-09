#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int menuGestor() {
	int opcao;

	printf("\nM E N U   G E S T O R\n");
	printf("1 - Adicionar novo meio\n");
	printf("2 - Remover meio\n");
	printf("3 - Guardar meios num ficheiro de texto e binario\n");
	printf("4 - Guardar clientes num ficheiro de texto e binario\n");
	printf("5 - Adicionar novo gestor\n");
	printf("6 - Guardar gestores num ficheiro de texto e binario\n");
	printf("7 - Listar gestores\n");
	printf("8 - Alterar dados de um dos meios\n");
	printf("9 - Lista dos clientes\n");
	printf("10 - Remover cliente\n");
	printf("11 - Ver localizacao\n");
	printf("12 - Listar meios\n");
	printf("13 - Novo vertice para o grafo\n");
	printf("14 - Nova aresta\n");
	printf("15 - Inserir meio numa localizacao\n");
	printf("16 - Listar meios contidos numa localizacao \n");
	printf("0 - Sair\n");
	printf("Introduza a opcao:");
	scanf("%d", &opcao);
	return(opcao);

}


int menuCliente() {
	int opcao;

	printf("\nM E N U   C L I E N T E\n");
	printf("1 - Listar meios\n");
	printf("2 - Listagem dos meios por ordem de decrescente de autonomia\n");
	printf("3 - Alugar meios\n");
	printf("4 - Ver localizacao\n");
	printf("5 - Alterar os seus dados\n");
	printf("6 - Listar caminhos a partir de uma localizacao\n");
	printf("7 - Listar localizacoes\n");
	printf("8 - Listar meios num determinado raio\n");
	printf("0 - Sair\n");
	printf("Introduza a opcao:");
	scanf("%d", &opcao);
	return(opcao);

}