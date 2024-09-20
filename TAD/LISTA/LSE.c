#include <stdlib.h>

typedef struct listNode {
    int info;
    struct listNode *prox;
    
}ListNode;

typedef struct lse{
    ListNode *inicio;
    ListNode *fim;
    int qtd;
}LSE;

void inicializar(LSE *l){
    l->inicio = NULL;
    l->fim = NULL;
    l->qtd = 0;
}

int isEmpty( LSE *l){
    return l->inicio == NULL;
}

void inserirFinal(LSE *l,int valor){
    ListNode *novo = malloc(sizeof(ListNode));
    novo->info = valor;
    novo->prox = NULL;
    if (isEmpty(l)) {
        l->inicio = novo;
    } else {
        l->fim->prox = novo;
    }
    l->fim = novo;
    l-> qtd++;
}

void inserirInicio(LSE *l, int valor){
    ListNode *novo = malloc(sizeof(ListNode));
    novo->info = valor;
    novo->prox = NULL;
    if(isEmpty(l)){
        l = novo;
    }else{
        novo->prox = l;
        l = novo;

    }
}

void removerInicio(LSE *l){
    ListNode* aux = l;
    int valor;
    l = l->inicio->prox;
    valor = aux->info;
    free(aux);
    l->qtd--;
    return valor;
}

void removerUltimo(LSE *l){
    if (isEmpty(l)) {
        printf("Fila vazia. Nao eh possivel desenfileirar.\n");
        exit(1);
    }
    ListNode *aux = l->inicio;
    int *valor = (int*)malloc(sizeof(int)*100);
    l->inicio = aux->prox;
    if (l->inicio == NULL) {
        l->fim = NULL;
    }
    valor = aux->info;
    free(aux);
    l->qtd --;
    return valor;
}

void list(LSE l){
    ListNode* aux;
    if(isEmpty(&l)==1){
        printf("Fila vazia!\n");
    }
    else{
        aux = l.inicio;
        while(aux != NULL){
            printf("%s \n", aux->info);
            aux = aux->prox;
            //aux pega o endereço do aux->prox, ou seja, ele não vai mudar o valor, ele vai ver o que está naquele endereço meu lindo.
        }
    }
}