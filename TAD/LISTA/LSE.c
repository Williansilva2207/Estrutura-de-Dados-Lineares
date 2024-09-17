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
}

void inserirInicio(LSE *l, int valor){
    ListNode *novo = malloc(sizeof(ListNode));
    novo->info = valor;
    novo->prox = NULL;
    if(isEmpty )
}

void removerInicio(LSE *l){

}

void removerUltimo(LSE *l){

}

void list(LSE l){

}