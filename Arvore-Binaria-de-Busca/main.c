#include <stdio.h>
#include <stdlib.h>
#include "arvb.h"

int main(int argc, char *argv[]) {
	ArvB* arvA = arvb_cria_vazia();
	arvA = arvb_insere(arvA, 43);
	arvA = arvb_insere(arvA, 51);
	arvA = arvb_insere(arvA, 21);
	arvA = arvb_insere(arvA, 4);
	arvA = arvb_insere(arvA, 45);
	arvA = arvb_insere(arvA, 29);
	arvA = arvb_insere(arvA, 3);
	arvA = arvb_insere(arvA, 23);
	arvA = arvb_remove(arvA, 4);
	
	printf("\n Numero de nos que possuem o campo esq e dir diferentes de NULL: %d\n"+ subarvs_difnull(arvA));
	printf("\nNumero de nos que possuem as subarvores esquerda e direita com a mesma altura: %d\n"+subarvs_ig_alt(arvA));
	printf("\n Quantidade de folhas que possuem elementos primos: %d\n"+folhas_primo(arvA));
	
	printf("\nImpressao dos elementos da arvore por nivel: ");
	impressao_arv_niveis(arvA);
	printf("\n");
	
	arvb_libera(arvA);
	
	system("PAUSE");
	return 0;
	}
