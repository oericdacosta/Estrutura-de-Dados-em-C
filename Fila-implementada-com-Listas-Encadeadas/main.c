#include <stdio.h>
#include <stdlib.h>
#include "fila2.h"

int main(int argc, char *argv[]) {
	int a, qtd;
	Fila* f1 = fila_cria();
	fila_insere(f1,3);
	fila_insere(f1,5);
	fila_insere(f1,9);
	fila_insere(f1,12);
	fila_insere(f1,17);
	a = fila_remove(f1);
	printf("Valor removido da fila f1: %d\n",a);
	printf("fila 1:\n");
	fila_imprime(f1);
	
	Fila* f2=inverte_fila(f1);
	printf("fila 2:\n");
	fila_imprime(f2);
	qtd=qtd_primos(f1);
	printf("Qtd. elem. primos na fila f1: %d\n",qtd);
	
	fila_libera(f1); fila_libera(f2);
	
	system("PAUSE");
 	
	return 0;
}
