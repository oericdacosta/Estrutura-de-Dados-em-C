typedef struct arvb ArvB;
typedef struct fila Fila;
typedef struct lista Lista;

/*Fu��o que cria uma fila*/
Fila* fila_cria(void);

/*Testa se uma Fila � vazia*/
int fila_vazia(Fila *f);

/*Fun��o que adiciona um endere�o de uma �rvore em uma fila*/
void fila_insere(Fila *f, ArvB *info);

/*Fun��o que remove um elemento de uma fila*/
ArvB* fila_remove(Fila *f);
