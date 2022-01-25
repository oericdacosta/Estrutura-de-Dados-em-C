#include "fila.h"
typedef struct arvb ArvB;

/*Função que cria uma Árvore Binaria de Busca vazia*/
ArvB* arvb_cria_vazia(void);

/*Testa se uma Árvore Binária é vazia*/
int arvb_vazia(ArvB *a);

/*Função que busca a sub-árvore que contém um inteiro*/
ArvB* arvb_busca(ArvB *a, int c);

/*Função que imprime os elementos de uma arvore*/
void arvb_imprime(ArvB *a);

/*Função que insere um inteiro em uma arvore*/
ArvB* arvb_insere(ArvB *a, int c);

/*Função que remove um inteiro em uma árvore*/
ArvB* arvb_remove(ArvB *a, int c);

/*Libera o espaço alocado em uma árvore*/
void arvb_libera(ArvB *a);

/*Função retorna se um número é, ou não, primo*/
int eh_primo(int c);

/*função que retorne a quantidade de folhas que possuem o campo info com número
primo*/
int folhas_primo(ArvB* a);

/*função que retorne a quantidade de nós que possuem campos dir e esq diferentes
de NULL.*/
int subarvs_difnull(ArvB* a);

/*função que retorna a altura da arvore.*/
int arvb_alt(ArvB* a);

/*função que retorne a quantidade de nós cujas subárvores esquerda e direita tenham a
mesma altura.*/
int subarvs_ig_alt(ArvB* a);

/*função que imprima os elementos por níveis.*/
void impressao_arv_niveis(ArvB* a);

