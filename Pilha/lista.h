typedef struct lista Lista;

/*Cria uma lista vazia*/
Lista* lst_cria();

/*Testa se uma lista é vazia*/
int lst_vazia(Lista *l);

/*Insere um elemento no inicio da lista*/
Lista* lst_insere(Lista *l, int info);

/*Insere um elemento na ordem crescente*/
Lista * lst_insere_ordenado(Lista *l, int info);

/*Busca um elemento em uma lista*/
Lista* lst_busca(Lista *l, int info);

/*Imprime uma lista*/
void lst_imprime(Lista *l);

/*Imprime uma lista de forma recursiva*/
void lst_imprime_rec(Lista *l);

/*Imprime uma lista na ordem inversa e recursiva*/
void lst_imprime_invertida_rec(Lista *l1);

/*Remove um elemento de uma lista*/
Lista* lst_remove(Lista *l, int info);

/*Remove um elemento da lista de forma recursiva*/
Lista* lst_remove_rec(Lista *l, int info);

/*Libera o espaço alocado por uma lista*/
void lst_libera(Lista *l);

/*Libera o espaço alocado de forma recursiva*/
void lst_libera_rec(Lista *l);

/*Retorna o numero de nós que cada lista tem*/
int conta_nos(Lista *l);

/*Retorna o número de nós da lista que possuem o campo "info" menor que n*/
int menores(Lista *l, int n);

/*Retorna a soma de todos os valores do campo "info"*/
int soma(Lista *l);

/*Retorna o número de nós da lista que possuem o campo "info" com n divisores*/
int num_ndivp(Lista *l, int n);

/*Concatena duas listas em uma só*/
Lista* lst_conc(Lista *l1, Lista *l2);

/*Retira da maior lista, os elementos que estão na lista menor*/
Lista* lst_diferenca(Lista *l1, Lista *l2);

/*Retorna os elementos em comum entre duas lista
Ps.:Essa função é usada para resolver a letra B da questão 2*/
Lista* lst_igual(Lista *l1, Lista *l2);
