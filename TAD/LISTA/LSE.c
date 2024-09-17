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