#include <stdlib.h>
#define TRUE 1
#define FALSE 0

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

int isEmpty( LSE l){
    if(l.qtd == 0){
        return TRUE;
    }else{
        return FALSE;
    }
}

void inserirFinal(LSE *l,int valor){
    ListNode *novo =(ListNode*) malloc(sizeof(ListNode));
    novo->info = valor;
    novo->prox = NULL;
    if (isEmpty(*l)== TRUE) {
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
    if(isEmpty(*l)==TRUE){
        l->inicio = novo;
        l->fim = novo;
    }else{
        novo->prox = l->inicio;
        l->inicio = novo;

    }
    l->qtd++;
}

void removerInicio(LSE *l){
    if(isEmpty(*l) == TRUE){
        return;
    }else{
        ListNode* aux = l->inicio;
        
        l->inicio = l->inicio->prox;
        
        free(aux);
        l->qtd--;
        if(l->inicio == NULL){
            l->fim = NULL;
        }
        free(aux);
    }
}

void removerUltimo(LSE *l){
    if (isEmpty(*l)) {
        if(l->inicio->prox == NULL){
            free(l->inicio);
            l->fim = NULL;
            l->inicio = NULL;
        }
    }else{

        ListNode *aux = l->inicio;
        while(aux->prox != l->fim){
            aux = aux->prox;
        }
        
        l->fim = aux->prox;
        free(aux);
        aux->prox= NULL;
    }
   l->qtd --;
}

void list(LSE l){
    ListNode* aux;
    if(isEmpty(l)==1){
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