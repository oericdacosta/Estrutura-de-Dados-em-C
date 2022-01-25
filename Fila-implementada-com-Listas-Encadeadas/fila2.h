#include "lista.h"
#include "pilha.h"
typedef struct fila Fila;

/*Fução que cria uma fila*/
Fila* fila_cria(void);

/*Função que adiciona um elemento em uma fila*/
void fila_insere(Fila *f, int info);

/*Testa se uma Fila é vazia*/
int fila_vazia(Fila *f);

/*Função que remove um elemento de uma fila*/
int fila_remove(Fila *f);

/*Função que imprime os elementos de uma fila*/
void fila_imprime(Fila *f);

/*Libera o espaço alocado para uma fila*/
void fila_libera(Fila *f);

/*Função retorna a quantidade de elementos que são primos*/
int qtd_primos(Fila *f);

/*retorna uma nova fila com os elementos na ordem inversa*/
Fila* inverte_fila(Fila *f);
