#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct fila{
	Lista *ini;
	Lista *fim;
};

struct lista{
	ArvB *info;
	Lista *Prox;
};

/*Fu��o que cria uma fila*/
Fila* fila_cria(void){
	Fila *f = (Fila*)malloc(sizeof(Fila));
	if(f==NULL){
		printf("memoria insuficiente!!!\n");
		exit(1);
	}
	f->ini = NULL;
	f->fim = NULL;
	return f;
}

/*Testa se uma Fila � vazia*/
int fila_vazia(Fila *f){
	return f->ini==NULL;
}

/*Fun��o que adiciona um endere�o de uma �rvore em uma fila*/
void fila_insere(Fila *f, ArvB *info){
	Lista *l = (Lista*)malloc(sizeof(Lista));
	if(l==NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	l->info = info;
	l->Prox = NULL;
	if(!fila_vazia(f)){
		f->fim->Prox = l;
	}else{
		f->ini = l;
	}
	f->fim = l;
}

/*Fun��o que remove um elemento de uma fila*/
ArvB* fila_remove(Fila *f){
	Lista *l; ArvB *a;
	if(fila_vazia(f)){
		printf("fila vazia!!!\n");
		exit(1);
	}
	a = f->ini->info;
	l = f->ini;
	f->ini = f->ini->Prox;
	free(l);
	if(fila_vazia(f)){
		f->fim = NULL;
	}
	return a;
}
