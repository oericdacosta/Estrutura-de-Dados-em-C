#include "fila.h"
typedef struct arvb ArvB;

/*Fun��o que cria uma �rvore Binaria de Busca vazia*/
ArvB* arvb_cria_vazia(void);

/*Testa se uma �rvore Bin�ria � vazia*/
int arvb_vazia(ArvB *a);

/*Fun��o que busca a sub-�rvore que cont�m um inteiro*/
ArvB* arvb_busca(ArvB *a, int c);

/*Fun��o que imprime os elementos de uma arvore*/
void arvb_imprime(ArvB *a);

/*Fun��o que insere um inteiro em uma arvore*/
ArvB* arvb_insere(ArvB *a, int c);

/*Fun��o que remove um inteiro em uma �rvore*/
ArvB* arvb_remove(ArvB *a, int c);

/*Libera o espa�o alocado em uma �rvore*/
void arvb_libera(ArvB *a);

/*Fun��o retorna se um n�mero �, ou n�o, primo*/
int eh_primo(int c);

/*fun��o que retorne a quantidade de folhas que possuem o campo info com n�mero
primo*/
int folhas_primo(ArvB* a);

/*fun��o que retorne a quantidade de n�s que possuem campos dir e esq diferentes
de NULL.*/
int subarvs_difnull(ArvB* a);

/*fun��o que retorna a altura da arvore.*/
int arvb_alt(ArvB* a);

/*fun��o que retorne a quantidade de n�s cujas sub�rvores esquerda e direita tenham a
mesma altura.*/
int subarvs_ig_alt(ArvB* a);

/*fun��o que imprima os elementos por n�veis.*/
void impressao_arv_niveis(ArvB* a);

