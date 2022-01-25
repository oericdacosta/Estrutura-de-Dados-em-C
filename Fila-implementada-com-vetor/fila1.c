#include <stdio.h>
#include <stdlib.h>
#include "fila1.h"
#define N 15
typedef struct fila{
	int n;
	int ini;
	int v[N];
}Fila;

/*Fução que cria uma fila*/
Fila* fila_cria(void){
	Fila *f = (Fila*)malloc(sizeof(Fila));
	if(f==NULL){
		printf("memoria insuficiente!!!\n");
		exit(1);
	}
	f->n = 0;
	f->ini = 0;
	return f;
}

/*Função que adiciona um elemento em uma fila*/
void fila_insere(Fila *f, int info){
	int fim;
	if(f->n == N){
		printf("Capacidade de fila estorou!!!\n");
		exit(1);
	}
	fim = (f->ini+f->n) % N;
	f->v[fim] = info;
	f->n++;
}

/*Testa se uma Fila é vazia*/
int fila_vazia(Fila *f){
	return f->n == 0;
}

/*Função que remove um elemento de uma fila*/
int fila_remove(Fila *f){
	int a;
	if(fila_vazia(f)){
		printf("Fila vazia!!!\n");
		exit(1);
	}
	a = f->v[f->ini];
	f->ini = (f->ini+1) % N;
	f->n--;
	return a;
}

/*Função que imprime os elementos de uma fila*/
void fila_imprime(Fila *f){
	int i, k;
	for(i=0;i<f->n;i++){
		k = (f->ini+i) % N;
		printf("%d\n",f->v[k]);
	}
}

/*Libera o espaço alocado para uma fila*/
void fila_libera(Fila *f){
	free(f);
}

/*Função retorna a quantidade de elementos que são primos*/
int qtd_primos(Fila *f){
	if(fila_vazia(f)){
		printf("A fila esta vazia!!!\n");
		exit(1);
	}
	int i, j, contaDiv, contaPrimos = 0;
	for(i=0;i<f->n;i++){
		for(j=1;j<=f->v[i];j++){
			if(f->v[i] % j == 0){
				contaDiv++;
			}
		}
		if(contaDiv==2){
			contaPrimos++;
		}
		contaDiv = 0;
	}
	return contaPrimos;
}

/*Retorna o ultimo indice do vetor, contando com os elementos retirados*/
int ultimo_indice_fila(Fila *f){
	int i, k;
	for(i=0;i<f->n;i++){
		k = (f->ini+i) % N;
	}
	return k;
}

/*retorna uma nova fila com os elementos na ordem inversa*/
Fila* inverte_fila(Fila *f){
	if(fila_vazia(f)){
		printf("A fila esta vazia!!!\n");
		exit(1);
	}
	Fila* f2 = fila_cria();
	int i;	
	int ultimoIndice = ultimo_indice_fila(f);
	for(i=ultimoIndice;i>=(f->ini);i--){
		fila_insere(f2,f->v[i]);
	}
	return f2;
}
