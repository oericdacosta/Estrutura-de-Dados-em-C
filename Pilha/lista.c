#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista{
	int info;
	Lista *Prox;
};

/*Cria uma lista vazia*/
Lista* lst_cria(){
	return NULL;
}

/*Testa se uma lista é vazia*/
int lst_vazia(Lista *l){
	return (l==NULL);//retorna 0 F e 1 para V
}

/*Insere um elemento no início da lista*/
Lista* lst_insere(Lista *l, int info){
	Lista* ln = (Lista*)malloc(sizeof(Lista));
	ln->info = info;
	ln->Prox = l;
	return ln;
}

/*Insere um elemento na ordem crescente*/
Lista * lst_insere_ordenado(Lista *l, int info){
	Lista *lNew = (Lista*)malloc(sizeof(Lista));
	lNew->info = info;
	if(l==NULL){
		lNew->Prox = NULL;
		return lNew;
	}else if(l->info>=info){
		lNew->Prox = l;
		return lNew;
	}else{
		Lista *lAnt = l;
		Lista *lProx = l->Prox;
		while(lProx!=NULL && lProx->info<info){
			lAnt = lProx;
			lProx = lProx->Prox;
		}
		lAnt->Prox = lNew;
		lNew->Prox = lProx;
		return l;
	}
}

/*Busca um elemento em uma lista*/
Lista* lst_busca(Lista *l, int info){
	Lista* lAux = l;
	while(lAux!=NULL){
		if(lAux->info == info){
			return lAux;
		}
		lAux = lAux->Prox;
	}
	return NULL;
}

/*Imprime uma lista*/
void lst_imprime(Lista *l){
	Lista* lAux = l;
	while(lAux!=NULL){
		printf("info = %d\n",lAux->info);
		lAux = lAux->Prox;
	}
}

/*Imprime uma lista de forma recursiva*/
void lst_imprime_rec(Lista *l){
	if(lst_vazia(l)){
		return;
	}else{
		printf("info: %d\n", l->info);
		lst_imprime_rec(l->Prox);
	}
}

/*Imprime uma lista na ordem inversa e recursiva*/
void lst_imprime_invertida_rec(Lista *l){
	if(lst_vazia(l)){
		return;
	}else{
		lst_imprime_invertida_rec(l->Prox);
		printf("info = %d\n", l->info);
	}
}

/*Remove um elemento de uma lista*/
Lista* lst_remove(Lista *l, int info){
	if(l!=NULL){
		Lista* lAux = l->Prox;
		if(l->info==info){
			free(l);
			return lAux;
		}else{
			Lista* lAnt = l;
			while(lAux!=NULL){
				if(lAux->info==info){
					lAnt->Prox = lAux->Prox;
					free(lAux);
					break;
				}else{
					lAnt = lAux;
					lAux = lAux->Prox;
				}
			}
		}
	}
	return l;
}

/*Remove um elemento da lista de forma recursiva*/
Lista* lst_remove_rec(Lista *l, int info){
	if(!(lst_vazia(l)))
		if(l->info==info){
			Lista* lAux = l;
			l = l->Prox;
			free(lAux);
	}
	else{
		l->Prox = lst_remove_rec(l->Prox,info);
	}
	return l;
}

/*Libera o espaço alocado por uma lista*/
void lst_libera(Lista *l){
	Lista* lProx;
	while(l!=NULL){
		lProx = l->Prox;
		free(l);
		l = lProx;
	} 
}

/*Libera o espaço alocado de forma recursiva*/
void lst_libera_rec(Lista *l){
	if(!lst_vazia(l)){
		lst_libera_rec(l->Prox);
		free(l);
	}
}

/*Retorna o numero de nós que cada lista tem*/
int conta_nos(Lista *l){
	int num_nos = 0;
	while(l!=NULL){
		num_nos++;
		l = l->Prox;
	}
	return num_nos;
}

/*Retorna o número de nós da lista que possuem o campo "info" menor que n*/
int menores(Lista *l, int n){
	int i=0;
	while(l!=NULL){
		if(l->info<n){
			i++;
		}
		l = l->Prox;
	}
	return i;
}

/*Retorna a soma de todos os valores do campo "info"*/
int soma(Lista *l){
	int soma;
	while(l!=NULL){
		soma+=l->info;
		l = l->Prox;
	}
	return soma;
}

/*Retorna o número de nós da lista que possuem o campo "info" com n divisores*/
int num_ndivp(Lista *l, int n){
	int numDivP = 0;
	while(l!=NULL){
		int i=1, contaDiv = 0;
		do{
			if(l->info % i == 0){
				contaDiv++;
			}
			i++;
		}while(i<=l->info);
		if(contaDiv == n){
			numDivP++;
		}
		l = l->Prox;
	}
	return numDivP;
}

/*Concatena duas listas em uma só*/
Lista* lst_conc(Lista *l1, Lista *l2){
	Lista *l3 = lst_cria();
	
	int contaNosL1 = conta_nos(l1), contaNosL2 = conta_nos(l2), i = 1, j = 1;
	
	while(i<=contaNosL1){
		l3 = lst_insere_ordenado(l3, l1->info);
		l1 = l1->Prox;
		i++;
	}
	while(j<=contaNosL2){
		l3 = lst_insere_ordenado(l3, l2->info);
		l2 = l2->Prox;
		j++;
	}
	
	return l3;	
}

/*Retira da lista 1, os elementos que estão na lista 2*/
Lista* lst_diferenca(Lista *l1, Lista *l2){
	int contaNosL1 = conta_nos(l1), contaNosL2 = conta_nos(l2);
	if(contaNosL2>contaNosL1){
		while(l1!=NULL){
			while((lst_busca(l2,l1->info))!=NULL){
				l2 = lst_remove_rec(l2, l1->info);
			}
			l1 = l1->Prox;
	}
	return l2;
	}else
		while(l2!=NULL){
			while((lst_busca(l1,l2->info))!=NULL){
			l1 = lst_remove_rec(l1, l2->info);
		}
		l2 = l2->Prox;
	}
	return l1;
}

/*Retorna os elementos em comum entre duas lista*/
Lista* lst_igual(Lista *l1, Lista *l2){
	int contaNosL1 = conta_nos(l1), contaNosL2 = conta_nos(l2);
	Lista *l3 = lst_cria(); Lista *lAux = lst_cria();
	int i=1;
	
	if(contaNosL2>contaNosL1){
		l3 = lst_conc(l1,l2);
		lAux = lst_diferenca(l1,l2);
		l3 = lst_diferenca(l3,lAux);
		while(i<=contaNosL1){
			l3 = lst_remove(l3,l1->info);
			l1 = l1->Prox;
			i++;
		}
		return l3;	
	}else if(contaNosL1>contaNosL2){
		l3 = lst_conc(l1,l2);
		lAux = lst_diferenca(l1,l2);
		l3 = lst_diferenca(l3,lAux);
		while(i<=contaNosL2){
			l3 = lst_remove(l3,l2->info);
			l2 = l2->Prox;
			i++;
		}
		return l3;
	}else{
		l3 = lst_conc(l1,l2);
		lAux = lst_diferenca(l2,l1);
		l3 = lst_diferenca(l3,lAux);
		l3 = lst_diferenca(l3,l2);
		while(i<=contaNosL1){
			l3 = lst_remove(l3,l1->info);
			l1 = l1->Prox;
			i++;
		}
		return l3;
	}
}
