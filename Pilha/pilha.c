#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct pilha{
	Lista *prim;
};

struct lista{
	int info;
	Lista *Prox;
};

/*Cria uma pilha*/
Pilha* pilha_cria(void){
	Pilha *p = (Pilha*)malloc(sizeof(Pilha));
	if(p == NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	p->prim = NULL;
	return p;
}

/*Função que adciona um elemento no topo de uma pilha*/
void pilha_push(Pilha *p, int info){
	Lista* l = (Lista*)malloc(sizeof(Lista));
	if(l == NULL){
		printf("memoria insuficiente!!!\n");
	}
	l->info = info;
	l->Prox = p->prim;
	p->prim = l;
}

/*Testa se uma pilha é vazia*/
int pilha_vazia(Pilha *p){
	return p->prim==NULL;
}

/*Função que remove um elemento do topo de uma pilha*/
int pilha_pop(Pilha *p){
	int a;
	Lista *l;
	if(pilha_vazia(p)){
		printf("Pilha vazia!!!\n");
		exit(1);
	}
	l = p->prim;
	a = l->info;
	p->prim = l->Prox;
	free(l);
	return a;
}

/*Função que imprime os elementos de uma pilha*/
void pilha_imprime(Pilha *p){
	Lista *lAux = p->prim;
	while(lAux!=NULL){
		printf("%d\n", lAux->info);
		lAux = lAux->Prox;
	}
}

/*Libera o espaço alocado para uma pilha*/
void pilha_libera(Pilha *p){
	Lista *l = p->prim;
	Lista* lAux;
	while(l!=NULL){
		lAux = l->Prox;
		free(l);
		l = lAux;
	}
	free(p);
}

/*Função que gera uma nova pilha, com os elementos de uma pilha P na ordem inversa*/
Pilha* inverte_pilha(Pilha *p){
	if(pilha_vazia(p)){
		printf("Pilha esta vazia!!!\n");
		exit(1);
	}
	Lista *l = p->prim;
	Pilha *p1 = pilha_cria();
	while(l!=NULL){
		pilha_push(p1,l->info);
		l = l->Prox;
	}
	return p1;
}

/*Verifica elementos comuns em duas listas e os empilha, em ordem crescente, em uma pilha*/
Pilha* empilha_elem_comuns(Lista *l1, Lista *l2){
	Lista *l = lst_cria(); l = lst_igual(l1,l2);
	Pilha *p = pilha_cria();
	int numNosL = conta_nos(l), i = 1;
	while(i<=numNosL){
		pilha_push(p,l->info);
		l = l->Prox;
		i++;
	}
	return p;
}
