#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(int argc, char *argv[]) {
	
	int a, b, c;
	
	Lista* l1 = lst_cria();
	l1 = lst_insere_ordenado(l1,14);
	l1 = lst_insere_ordenado(l1,8);
	l1 = lst_insere_ordenado(l1,29);
	l1 = lst_insere_ordenado(l1,12);
	l1 = lst_insere_ordenado(l1,6);
	l1 = lst_insere_ordenado(l1,18);
	l1 = lst_remove_rec(l1,29);
	printf("Lista 1:\n");
	lst_imprime(l1);
	printf("Lista 1 invertida:\n");
	lst_imprime_invertida_rec(l1);
	
	a = soma(l1); b = menores(l1,9); c = num_ndivp(l1,4);
	printf("soma dos valores dos nos: %d\n", a);
	printf("Num. nos c/ info < que 9: %d\n", b);
	printf("Num. nos c/ info c/ 4 div. positivos.: %d\n", c);
	
	Lista* l2 = lst_cria();
	l2 = lst_insere_ordenado(l2,8);
	l2 = lst_insere_ordenado(l2,12);
	l2 = lst_insere_ordenado(l2,7);
	
	Lista* l3=lst_conc(l1,l2);
	printf("lista 3:\n");
	lst_imprime(l3);
	
	l1=lst_diferenca(l1,l2);
	printf("Elementos que estao apenas na lista 1:\n");
	lst_imprime(l1);
	
	lst_libera(l1);
	lst_libera(l2);
	lst_libera(l3);
	
	system("PAUSE");
	return 0;
}
