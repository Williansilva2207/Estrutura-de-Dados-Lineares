#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0
typedef struct listNode {
    int info;
    struct listNode* prox;
} ListNode;

typedef struct lse {
    ListNode* inicio;
    ListNode* fim;
    int qtd;
} LSE;

void inicializar (LSE* l) {
    l->inicio = NULL;
    l->fim = NULL;
    l->qtd = 0;
}

int isEmpty(LSE l) {
   if(l.qtd == 0){
    return TRUE;
   }else{
    return FALSE;
   }

}

void inserirFinal (LSE* l, int valor) {
    ListNode *novo = (ListNode*) malloc(sizeof(ListNode));
    novo->info = valor;
    novo->prox = NULL;
    if(isEmpty(*l)== TRUE){
        l->inicio = novo;
    }else{
        l->fim->prox = novo;
    }
    l->fim = novo;
    l->qtd++;
}

void inserirInicio (LSE* l, int valor) {
    // Procedimento: recebe a lista como parâmetro (passado por referência)
    // e o valor a ser inserido. Insere o valor no início da lista.

}

void removerInicio (LSE* l) {
    // Procedimento: recebe a lista como parâmetro (passado por referência)
    // remove o valor situado no início da lista.

}

void removerUltimo (LSE* l) {
    if(isEmpty(*l)==TRUE){
        printf("NÃO HÁ ELEMENTO PARA SER REMOVIDO\n");
        return;
    }else if(l->inicio == l->fim){
        l->inicio = NULL;
        l->fim = NULL;
        l->qtd--;
    }
    else{
        ListNode *aux = l->inicio;
        while(aux->info != l->fim->info){
            aux = aux->prox;
        }
        l->fim = aux;
        printf("O elemento final foi removido.");
        l->qtd--;
    }

}

void list (LSE l) {
    ListNode *aux = l.inicio;
    if(isEmpty(l)==TRUE){
        printf("Lista Vázia\n");
        return;
    }else{
        while(aux != NULL){
            printf("%d ", aux->info);
            aux = aux->prox;
        }
    }

}

void remover (LSE* l, int valor) {
    // Procedimento: recebe a lista como parâmetro (passado por referência)
    // e o valor a ser removido. Procura pelo valor na lista e remove, caso encontre.
    // Se não encontrar, emite mensagem informando o ocorrido.
    
}