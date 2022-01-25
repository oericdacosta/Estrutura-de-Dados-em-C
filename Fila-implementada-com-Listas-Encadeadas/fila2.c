#include <stdio.h>
#include <stdlib.h>
#include "fila2.h"
#include "pilha.h"

struct fila{
	Lista *ini;
	Lista *fim;
};

struct lista{
	int info;
	Lista *Prox;
};

struct pilha{
	Lista *prim;
};

/*Fução que cria uma fila*/
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

/*Função que adiciona um elemento em uma fila*/
void fila_insere(Fila *f, int info){
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

/*Testa se uma Fila é vazia*/
int fila_vazia(Fila *f){
	return f->ini==NULL;
}

/*Função que remove um elemento de uma fila*/
int fila_remove(Fila *f){
	Lista *l; int a;
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

/*Função que imprime os elementos de uma fila*/
void fila_imprime(Fila *f){
	Lista *lAux = f->ini;
	while(lAux!=NULL){
		printf("%d\n",lAux->info);
		lAux = lAux->Prox;
	}
}

/*Libera o espaço alocado para uma fila*/
void fila_libera(Fila *f){
	Lista *l = f->ini;
	Lista *lAux;
	while(l!=NULL){
		lAux = l->Prox;
		free(l);
		l = lAux;
	}
	free(f);
}

/*Função retorna a quantidade de elementos que são primos*/
int qtd_primos(Fila *f){
	if(fila_vazia(f)){
		printf("a fila esta vazia!!!\n");
		exit(1);
	}
	Lista *l = f->ini;
	int i, contaPrimo = 0;
	while(l!=NULL){
		int contaDiv = 0;
		for(i=1;i<=l->info;i++){
			if(l->info % i == 0){
				contaDiv++;
			}
		}
		if(contaDiv == 2){
			contaPrimo++;
		}
		l= l->Prox;
	}
	return contaPrimo;
}

/*retorna uma nova fila com os elementos na ordem inversa*/
Fila* inverte_fila(Fila *f){
	if(fila_vazia(f)){
		printf("A fila esta vazia!!!\n");
		exit(1);
	}
	Lista *l = f->ini; Lista *lAux = lst_cria();
	Pilha *p = pilha_cria();
	Fila *f2 = fila_cria();
	int numNosL = conta_nos(l), i = 1;
	while(i<=numNosL){
		pilha_push(p,l->info);
		l = l->Prox;
		i++;
	}
	lAux = p->prim;
	while(lAux!=NULL){
		fila_insere(f2,lAux->info);
		lAux = lAux->Prox;
	}
	return f2;
}
