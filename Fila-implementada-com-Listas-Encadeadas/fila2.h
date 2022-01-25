#include "lista.h"
#include "pilha.h"
typedef struct fila Fila;

/*Fu��o que cria uma fila*/
Fila* fila_cria(void);

/*Fun��o que adiciona um elemento em uma fila*/
void fila_insere(Fila *f, int info);

/*Testa se uma Fila � vazia*/
int fila_vazia(Fila *f);

/*Fun��o que remove um elemento de uma fila*/
int fila_remove(Fila *f);

/*Fun��o que imprime os elementos de uma fila*/
void fila_imprime(Fila *f);

/*Libera o espa�o alocado para uma fila*/
void fila_libera(Fila *f);

/*Fun��o retorna a quantidade de elementos que s�o primos*/
int qtd_primos(Fila *f);

/*retorna uma nova fila com os elementos na ordem inversa*/
Fila* inverte_fila(Fila *f);
