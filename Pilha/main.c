#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(int argc, char *argv[]) {
	int a;
 	Pilha* p1 = pilha_cria();

 	pilha_push(p1,10);
 	pilha_push(p1,20);
 	pilha_push(p1,25);
 	pilha_push(p1,30);
 	a = pilha_pop(p1);
	printf("Elemento removido da pilha p1: %d\n",a);
	
	Lista *l1 = lst_cria();
	l1 = lst_insere(l1,2);
	l1 = lst_insere(l1,3);
	l1 = lst_insere(l1,4);
	l1 = lst_insere(l1,5);
	
	Lista *l2 = lst_cria();
	l2 = lst_insere(l2,3);
	l2 = lst_insere(l2,4);
	l2 = lst_insere(l2,5);
	l2 = lst_insere(l2,6);
	
	
	Pilha *p2 = empilha_elem_comuns(l1,l2);
	printf("Pilha 2:\n");
	pilha_imprime(p2);
	
	Pilha *p3 = inverte_pilha(p2);
	printf("Pilha 3:\n");
	pilha_imprime(p3);
	
	lst_libera(l1); lst_libera(l2);
	pilha_libera(p1); pilha_libera(p2); pilha_libera(p3);
	
 	system("PAUSE");
 	
	return 0;
}
