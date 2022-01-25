#include"lista.h"
typedef struct pilha Pilha;

/*Cria uma pilha*/
Pilha* pilha_cria(void);

/*Função que adciona um elemento no topo de uma pilha*/
void pilha_push(Pilha *p, int info);

/*Testa se uma pilha é vazia*/
int pilha_vazia(Pilha *p);

/*Função que remove um elemento do topo de uma pilha*/
int pilha_pop(Pilha *p);

/*Função que imprime os elementos de uma pilha*/
void pilha_imprime(Pilha *p);

/*Libera o espaço alocado para uma pilha*/
void pilha_libera(Pilha *p);

/*Função que gera uma nova pilha, com os elementos de uma pilha P na ordem inversa*/
Pilha* inverte_pilha(Pilha *p);

/*Verifica elementos comuns em duas listas e os empilha, em ordem crescente, em uma pilha*/
Pilha* empilha_elem_comuns(Lista *l1, Lista *l2);
