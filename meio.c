#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include "meio.h"

void listarMeios(Meio* inicio)
{
	while (inicio != NULL)
	{
		printf("%d %s %.2f %.2f %s\n", inicio->codigo, inicio->tipo,
			inicio->bateria, inicio->autonomia, inicio->estado);
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


Meio* novoMeio(Meio* inicio, int cod, char tipo[], float bat, float aut, char est[])
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



/*void changeNode(int element, int index)
{
    struct list *current = head;
    int count = 0;
    while(count != index)
    {
        if(current->next)
            current = current->next;
        count++;
    }
    current->data = element;
}*/


// procurar o node pretendido e alterar os dados dentro dele
Meio* alterarDados(Meio* inicio, int cod, char tipo[], float bat, float aut, char est[]) {
	Meio* atual = inicio;

	if (atual == NULL) return(NULL);
	else if (atual->codigo == cod) {   // caso o header tenha o codigo introduzido
		strcpy(atual->tipo, tipo);
		atual->bateria = bat;
		atual->autonomia = aut;
		strcpy(atual->estado, est);
	}
	else {
		while ((atual != NULL) && (atual->codigo != cod)) {   // para encontrar o codigo introduzido
			atual = atual->seguinte;
		}
		if (atual == NULL) return(inicio);
		else {
			strcpy(atual->tipo, tipo);
			atual->bateria = bat;
			atual->autonomia = aut;
			strcpy(atual->estado, est);
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
			fprintf(fp, "%d;%s;%f;%f;%s\n", aux->codigo, aux->tipo, aux->bateria, aux->autonomia, aux->estado);
			aux = aux->seguinte;
		}
		fclose(fp);
		return(1);
		
	}
	else return(0);
}

/*Meio* lerMeios()
{
 	FILE* fp; 
	int cod; 
 	float bat, aut;
 	char tipo[50], est[30];
 	Meio* aux = NULL;
	Meio* novo =malloc(sizeof(struct registo));  
 	fp = fopen("meios.txt", "r");
 	if (fp != NULL)
	{
		while (fscanf(fp, "%d;%f;%f;%[^;];%s\n", &cod, &bat, &aut, tipo, est) == 5)
		{
			novo->codigo = cod;
			strcpy(novo->tipo, tipo);
			novo->bateria = bat;
			novo->autonomia = aut;
			strcpy(novo->estado, est);
			novo->seguinte = aux;
			aux = novo;

		}
		 
	}
	else {
		printf("Erro ao abrir ficheiro.");
	}
	fclose(fp);
	return aux;
}*/


Meio* lerMeios()
{
	FILE* fp;
	int cod;
	float bat, aut;
	char tipo[50], est[30];
	Meio* aux = NULL;
	Meio* novo;
	
	fp = fopen("meios.txt", "r");
	if (fp == NULL) {
		printf("Erro ao abrir ficheiro.");
		return NULL;
	}

	while (fscanf(fp, "%d;%[^;];%f;%f;%s\n", &cod, tipo, &bat, &aut, est) == 5)   
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
		strcpy(novo->estado, est);
		novo->seguinte = aux;
		aux = novo;
	}
	fclose(fp);
	return aux;
}


/*void reverseOrder() {
	struct temp aux;
	int size, i = 0, j;
	char ch;

	FILE* fp;
	fp = fopen("meios.txt", "r");

	if (fp != NULL) {
		while (!feof(fp)) {
			fscanf(fp, "%d;%s;%f;%f", &arr[i].codigo, arr[i].tipo, arr[i].bateria, arr[i].autonomia);
			ch = fgetc(fp);
			i++;
		}
		size = i - 1;

		for (i = 0; i < (size - 1); i++) {
			for (j = 0; j < size - i - 1; j++) {
				if (arr[j].autonomia < arr[j + 1].autonomia) {
					aux = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = aux;
				}
			}
		}
	}
	for (i = 0; i < size; i++) {
		printf("%d;%s;%f;%f\n", arr[i].codigo, arr[i].tipo, arr[i].bateria, arr[i].autonomia);
	}
}*/


void ordemDecrescente() {
	
	struct registo array[100];
	struct registo temp;

	int size = 0, i = 0, j;
	char ch;

	FILE* fp;
	fp = fopen("meios.txt", "r");

	if (fp != NULL) {
		while (!feof(fp)) {
			fscanf(fp, "%d;%f;%f;%[^;];%s", &array[i].codigo, &array[i].bateria, &array[i].autonomia, array[i].tipo, array[i].estado);
			ch = fgetc(fp);
			i++;
		}
		size = i - 1;

		for (i = 0; i < (size - 1); i++) {
			for (j = 0; j < size - i - 1; j++) {
				if (array[j].autonomia < array[j + 1].autonomia) {
					temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
				}
			}
		}
		fclose(fp);
	}
	else printf("Erro ao abrir ficheiro");


	for (i = 0; i < size; i++) {
		printf("%d;%s;%02.f;%02.f;%s\n", array[i].codigo, array[i].tipo, array[i].bateria, array[i].autonomia, array[i].estado);
	}
}


int ficheiroBinario(Meio* inicio) {
	FILE* fp;
	fp = fopen("meiosBinario", "wb");

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


void alugarMeio(Meio*  inicio) {
	Meio* atual = inicio; 
 	int cod;
  
	listarMeios(atual);   
	printf("Introduza o codigo do meio que pretende alugar: ");
	scanf("%d", &cod);

	if (existeMeio(atual, cod)) {
		if (atual == NULL) return(NULL); 
		else if (atual->codigo == cod) {   // caso o header tenha o codigo introduzido
			strcpy(atual->estado, "Alugado");
			
		}
		else {
			while ((atual != NULL) && (atual->codigo != cod)) {   // para encontrar o codigo introduzido
				atual = atual->seguinte; 
			}
			if (atual == NULL) return(inicio);
			else {
				strcpy(atual->estado, "Alugado");
				
			}
		}
		
	}
	else printf("Codigo Errado!");
	
}