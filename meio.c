#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "meio.h"
#include "ClientesGestores.h"

void listarMeios(Meio* inicio)
{
	while (inicio != NULL)
	{
		printf("%d %s %.2f %.2f %.2f %s %s\n", inicio->codigo, inicio->tipo,
			inicio->bateria, inicio->autonomia, inicio->custo, inicio->localizacao, inicio->estado);
		inicio = inicio->seguinte;
	}
}


int existeMeio(Meio* inicio, int cod)
{
	while (inicio != NULL)
	{
		if (inicio->codigo == cod) return(1);
		inicio = inicio->seguinte;
	}
	return(0);
}


Meio* novoMeio(Meio* inicio, int cod, char tipo[], float bat, float aut, char est[], char loc[], float custo)
{
	if (!existeMeio(inicio, cod))
	{
		Meio* novo = malloc(sizeof(struct registo));
		if (novo != NULL)
		{
			novo->codigo = cod;
			strcpy(novo->tipo, tipo);
			novo->bateria = bat;
			novo->autonomia = aut;
			novo->custo = custo;
			strcpy(novo->localizacao, loc);
			strcpy(novo->estado, est);
			novo->seguinte = inicio;
			return(novo);
			
		}
	}
	else return(inicio);
}


Meio* RemoverMeio(Meio* inicio, int cod) {
	Meio *anterior = inicio, *atual = inicio, *aux;

	if (atual == NULL) return(NULL);
	else if (atual->codigo == cod) {  //remove o primeiro node caso este tenha o codigo desejado
		aux = atual->seguinte;
		free(atual);
		return(aux);
	}
	else {
		while ((atual != NULL) && (atual->codigo != cod)) {  //percorre a lista ligada até encontrar o codigo do meio
			anterior = atual;
			atual = atual->seguinte;
		}

		if (atual == NULL) return(inicio);
		else {
			anterior->seguinte = atual->seguinte; //mete o pointer do campo "seguinte" do node "anterior"
			free(atual);                          // a apontar para o node a seguir ao node "atual" e elimina o node central
			return(inicio);
		}
	}
}




// procurar o node pretendido e alterar os dados dentro dele
Meio* alterarDados(Meio* inicio) {
	Meio* atual = inicio;

	int cod, opcao; 
	float bat, aut, custo;
	char tipo[50], est[50], loc[50];

	printf("Insira o codigo do meio que prentende alterar dados: \n");
	scanf("%d", &cod); 

	
	if (atual == NULL) return(NULL);
	//else if (atual->codigo == cod) {   // caso o header tenha o codigo introduzido
	//	do {
	//		printf("1 - Tipo\n2 - Bateria\n3 - Autonomia\n 4 - Custo\n5 - Estado\n6 - Localizacao\n0 - Sair\n");
	//		printf("Escolha a opcao : \n");
	//		scanf("%d", &opcao);

	//		switch (opcao) {
	//		case 1: printf("Novo tipo: ");
	//			getchar();  
	//			gets(tipo); 
	//			strcpy(atual->tipo, tipo);
	//			break;
	//		case 2: printf("Bateria: ");
	//			scanf("%f", &bat);
	//			atual->bateria = bat;
	//			break;
	//		case 3: printf("Autonomia: ");
	//			scanf("%f", &aut);
	//			atual->autonomia = aut;
	//			break;
	//		case 4: printf("Custo: ");
	//			scanf("%f", &custo);
	//			atual->custo = custo;
	//			break;
	//		case 5: printf("Novo estado do meio: ");
	//			getchar();
	//			gets(est);
	//			strcpy(atual->estado, est);
	//			break;
	//		case 6: printf("Nova localizacao do meio: ");
	//			getchar();
	//			gets(loc);
	//			strcpy(atual->localizacao, loc);
	//			break;
	//		}
	//	} while (opcao != 0);
	//	
	//}
	else {
		while ((atual != NULL) && (atual->codigo != cod)) {   // para encontrar o codigo introduzido
			atual = atual->seguinte;
		}
		if (atual == NULL) return(inicio);
		else {
			do {
				printf("1 - Tipo\n2 - Bateria\n3 - Autonomia\n4 - Custo\n5 - Estado\n6 - Localizacao\n0 - Sair\n");
				printf("Escolha a opcao : \n");
				scanf("%d", &opcao);

		 		switch (opcao) {
		 		case 1: printf("Novo tipo: ");
		 			getchar();
		 			gets(tipo);
		 			strcpy(atual->tipo, tipo);
					break;
		 		case 2: printf("Bateria: ");
		 			scanf("%f", &bat);
		 			atual->bateria = bat;
					break;
				case 3: printf("Autonomia: ");
		 			scanf("%f", &aut);
		 			atual->autonomia = aut;
					break;
				case 4: printf("Custo: "),
					scanf("%f", &custo);
					atual->custo = custo;
					break;
		 		case 5: printf("Novo estado do meio: ");
		 			getchar();
		 			gets(est);
		 			strcpy(atual->estado, est);
					break;
		 		case 6: printf("Nova localizacao do meio: ");
		 			getchar();
	  				gets(loc);
	 				strcpy(atual->localizacao, loc);
					break;
	 			}
	 		} while (opcao != 0);

		}
	}
	FicheiroMeios(atual);
	return (atual);
}


int FicheiroMeios(Meio* inicio) {
	FILE* fp;
	fp = fopen("meios.txt", "w");

	if (fp != NULL) {
		Meio* aux = inicio;

		while (aux != NULL) {
			fprintf(fp, "%d;%s;%f;%f;%.2f;%s;%s\n", aux->codigo, aux->tipo, aux->bateria, aux->autonomia, aux->custo, aux->localizacao, aux->estado);
			aux = aux->seguinte;
		}
		fclose(fp);
		return(1);
		
	}
	else return(0);
}



Meio* lerMeios()
{
	FILE* fp;
	int cod;
	float bat, aut, custo;
	char tipo[50], est[30], loc[50];
	Meio* aux = NULL;
	Meio* novo;
	
	fp = fopen("meios.txt", "r");
	if (fp == NULL) {
		printf("Erro ao abrir ficheiro.");
		return NULL;
	}

	while (fscanf(fp, "%d;%[^;];%f;%f;%f;%[^;];%s\n", &cod, tipo, &bat, &aut, &custo, loc, est) == 7)     
	{	
		novo = malloc(sizeof(Meio));
		if (novo == NULL) {
			printf("Erro ao alocar memoria.");
			return NULL;
		}
		novo->codigo = cod;
		strcpy(novo->tipo, tipo);
		novo->bateria = bat;
		novo->autonomia = aut;
		novo->custo = custo;
		strcpy(novo->localizacao, loc);
		strcpy(novo->estado, est);
		novo->seguinte = aux;
		aux = novo;
	}
	fclose(fp);
	return aux;
}

void listarArray(struct registo array[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("%d;%s;%.2f;%.2f;%.2f;%s;%s\n", array[i].codigo, array[i].tipo, array[i].bateria, array[i].autonomia, array[i].custo, array[i].localizacao, array[i].estado);
	}
}


void ordemDecrescente(Meio* inicio) {
	
	Meio* atual = inicio;
	struct registo arr[100];
	struct registo temp;


	int i = 0, size = 0, j;

 	while (atual != NULL) {
		
		arr[i].codigo = atual->codigo;
		strcpy(arr[i].tipo, atual->tipo); 
		arr[i].bateria = atual->bateria; 
		arr[i].autonomia = atual->autonomia;
		arr[i].custo = atual->custo;
		strcpy(arr[i].localizacao, atual->localizacao);
		strcpy(arr[i].estado, atual->estado);  

       atual = atual->seguinte; 
	   i++;
	}
	size = i;

	for (i = 0; i < (size - 1); i++) { 
		for (j = 0; j < size - i - 1; j++) { 
			if (arr[j].autonomia < arr[j + 1].autonomia) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	listarArray(arr, size); 

}


int ficheiroBinario(Meio* inicio) {
	FILE* fp;
	fp = fopen("meiosBinario.bin", "wb");

	if (fp != NULL) {
		Meio* aux = inicio;

		while (aux != NULL) {
			fwrite(&aux, sizeof(struct registo), 1, fp);
			aux = aux->seguinte;
		}
		fclose(fp);
		return(1);
	}
	else return(0);
}


void alugarMeio(Meio*  inicio, Cliente* begin, int nif, int cod) {
	Meio* atual = inicio; 
     
	if (existeMeio(atual, cod)) {
		if (atual == NULL) return(NULL); 
		else {
			while ((atual != NULL) && (atual->codigo != cod)) {   // para encontrar o codigo introduzido
				atual = atual->seguinte; 
			}
			if (strcmp(atual->estado, "Alugado") == 1) {

				strcpy(atual->estado, "Alugado");

				if (begin == NULL) return(NULL);
				else {
					while ((begin != NULL) && (begin->nif != nif)) {  //percorre a lista ligada até encontrar o codigo do meio
						begin = begin->seguinte;
					}
					if (begin->saldo >= atual->custo) {
						begin->saldo = begin->saldo - atual->custo;
					}
					else printf("Saldo insuficiente para alugar o meio!");
				}

				FicheiroClientes(begin);
				FicheiroMeios(inicio);
			}
			else printf("Meio ja alugado!\n");
		}
	}
	else printf("Codigo Errado!");
}


void localizacao(Meio* inicio) {
	char loc[50], b = 1;

	printf("Introduza a localizacao que pretende: \n");
	getchar();
	gets(loc);

	while (inicio != NULL) {
		if (strcmp(inicio->localizacao, loc) == 0) {
			printf("%d %s %.2f %.2f %.2f %s %s\n", inicio->codigo, inicio->tipo, 
				inicio->bateria, inicio->autonomia, inicio->custo, inicio->localizacao, inicio->estado); 
			b = 0;
		}
		inicio = inicio->seguinte;
	}
	if (b == 1) printf("Nenhum meio encontrado na localizacao pretendida");
}

void listarCodigo(Meio* meios, int codigo, char transporte[]) {
	
	while (meios != NULL) {
		if ((meios->codigo == codigo) && (strcmp(meios->tipo, transporte) == 0)) {
			printf("%d; %s; %.2f; %.2f; %.2f; %s; %s\n", meios->codigo, meios->tipo,
				meios->bateria, meios->autonomia, meios->custo, meios->localizacao, meios->estado);
			
		}
		meios = meios->seguinte;
	}
	
}

int verificarMeio(Meio* meios, char transporte[], int codigo) {
	while (meios != NULL) {
		if (meios->codigo == codigo) {
			if (strcmp(meios->tipo, transporte) == 0) return 1;
		}

		meios = meios->seguinte;
	}
	return 0;
}

Meio* alterarLocalizacao(Meio* meios, char geocodigo[], int codigo) {
	Meio* atual = meios;

	while ((atual != NULL) && (atual->codigo != codigo)) atual = atual->seguinte;  // para encontrar o codigo introduzido pelo utilizador

	if (atual != NULL) {
		strcpy(atual->localizacao, geocodigo);

	}

	return atual;
}