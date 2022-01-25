#include <stdio.h>
#include<stdlib.h>
#include"fila.h"
#include "arvb.h"

struct arvb{
	int info;
	ArvB *esq;
	ArvB *dir;
};

/*Função que cria uma Árvore Binaria de Busca vazia*/
ArvB* arvb_cria_vazia(void){
	return NULL;
}

/*Testa se uma Árvore Binária é vazia*/
int arvb_vazia(ArvB *a){
	return a==NULL;
}

/*Função que busca a sub-árvore que contém um inteiro*/
ArvB* arvb_busca(ArvB *a, int c){
	if(arvb_vazia(a)){
	return NULL;
	}else if(a->info < c){
		return arvb_busca(a->dir,c);
	}else if(a->info > c){
		return arvb_busca(a->esq,c);
	}else{//(a->info == c)
		return a;
	}
}

/*Função que imprime os elementos de uma arvore*/
void arvb_imprime(ArvB *a){
	if(!arvb_vazia(a)){
		arvb_imprime(a->esq);
		printf("%d ",a->info);
		arvb_imprime(a->dir);
	}
}

/*Função que insere um inteiro em uma arvore*/
ArvB* arvb_insere(ArvB *a, int c){
	if(arvb_vazia(a)){
		a = (ArvB*)malloc(sizeof(ArvB));
		a->info = c;
		a->esq = NULL;
		a->dir = NULL;
	}else if(a->info > c){
		a->esq = arvb_insere(a->esq,c);
	}else if (a->info < c){
		a->dir = arvb_insere(a->dir,c);
	}else
		printf("Elemento %d Ja Pertence a Arvore\n", a->info);
	return a;
}

/*Função que remove um inteiro em uma árvore*/
ArvB* arvb_remove(ArvB *a, int c){
	if(!arvb_vazia(a)){
		if(a->info > c){
			a->esq = arvb_remove(a->esq,c);
		}else if (a->info < c){
			a->dir = arvb_remove(a->dir,c);
		}else{
			ArvB* t;
			if (a->esq == NULL){
				t = a; a = a->dir;
				free(t);
			}else if (a->dir == NULL){
				t = a; a = a->esq;
				free(t);
			}else{
				t = a->esq;
				while(t->dir!=NULL){
					t = t->dir;
				}
				a->info = t->info; t->info = c;
				a->esq = arvb_remove(a->esq,c);
			}
		}
	}
	return a;
}

/*Libera o espaço alocado em uma árvore*/
void arvb_libera(ArvB *a){
	if(!arvb_vazia(a)){
		arvb_libera(a->esq);
		arvb_libera(a->dir);
		free(a);
	}
}

/*Função retorna se um número é, ou não, primo*/
int eh_primo(int c){
	int i,numDiv = 0;
	for(i=1;i<=c;i++){
		if(c % i == 0){
			numDiv++;
		}
	}
	if(numDiv == 2){
		return 1;
	}else{
		return 0;
	}
}

/*função que retorne a quantidade de folhas que possuem o campo info com número
primo*/
int folhas_primo(ArvB* a){
	if(!arvb_vazia(a->esq) && !arvb_vazia(a->dir)){
		return folhas_primo(a->esq) + folhas_primo(a->dir);
	}else{
		if(!arvb_vazia(a->esq)){
			return folhas_primo(a->esq);
		}else if(!arvb_vazia(a->dir)){
			return folhas_primo(a->dir);
		}else{
			return eh_primo(a->info);
		}
	}
}

/*função que retorne a quantidade de nós que possuem campos dir e esq diferentes
de NULL.*/
int subarvs_difnull(ArvB* a){
	if(!arvb_vazia(a->esq) && !arvb_vazia(a->dir)){
		return 1 + subarvs_difnull(a->esq) + subarvs_difnull(a->dir);
	}else{
		return 0;
	}
}

/*função que retorna a altura da arvore.*/
int arvb_alt(ArvB *a){
	if(arvb_vazia(a))
		return -1;
	else{
		int hSAE = arvb_alt(a->esq);
		int hSAD = arvb_alt(a->dir);
		if(hSAE > hSAD){
			return 1+hSAE;
		}else{
			return 1+hSAD;
		}
	}
}

/*função que retorne a quantidade de nós cujas subárvores esquerda e direita tenham a
mesma altura.*/
int subarvs_ig_alt(ArvB* a){
	if(!arvb_vazia(a->esq) && !arvb_vazia(a->dir)){
		if(arvb_alt(a->esq) == arvb_alt(a->dir)){
			return 1 + subarvs_ig_alt(a->esq) + subarvs_ig_alt(a->dir);
		}else{
			return 0 + subarvs_ig_alt(a->esq) + subarvs_ig_alt(a->dir);
		}
	}else{
		return 0;
	}
}

/*função que imprima os elementos por níveis.*/
void impressao_arv_niveis(ArvB* a){
	if(!arvb_vazia(a)){
		Fila *f = fila_cria();
		fila_insere(f,a);
		ArvB *atual = arvb_cria_vazia();
		while(!fila_vazia(f)){
			atual = fila_remove(f);
			printf("%d ", atual->info);
			if(!arvb_vazia(atual->esq)){
				fila_insere(f,atual->esq);
			}
			if(!arvb_vazia(atual->dir)){
				fila_insere(f,atual->dir);
			}
		}
	}
}


