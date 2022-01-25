typedef struct arvb ArvB;
typedef struct fila Fila;
typedef struct lista Lista;

/*Fução que cria uma fila*/
Fila* fila_cria(void);

/*Testa se uma Fila é vazia*/
int fila_vazia(Fila *f);

/*Função que adiciona um endereço de uma árvore em uma fila*/
void fila_insere(Fila *f, ArvB *info);

/*Função que remove um elemento de uma fila*/
ArvB* fila_remove(Fila *f);
