#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define TRUE 1;
#define FALSE 0;

typedef struct listnode{
    int info;
    struct listnode *prox;
    
}ListNode;

typedef struct lnn{
    ListNode *inicio;
    ListNode *Fim;
    int qtd;
}LNN;

int isEmpty(LNN l){
    if(l.qtd == 0){
        return TRUE;
    }else{
        return FALSE;
    }
}

void inicializar(LNN *l){
    l->inicio = NULL;
    l->Fim = NULL;
    l->qtd = 0;
}

void Inserir(LNN *l, int valor){
    ListNode *novo = (ListNode*) malloc(sizeof(ListNode));
    novo->info = valor;
    novo->prox = NULL;
    if(isEmpty(*l) == 1){
        l->inicio = novo;
        l->Fim = novo;
        l->qtd ++;
    }else{
        if(Busca(*l,valor)==1){
            printf("Esse valor já existe na fila.\n");
            return;
        }else{
            novo->prox = l->inicio;
            l->inicio = novo;
            l->qtd++;
        }
    }
}

int Busca(LNN l, int valor){
    
    if(isEmpty(l) == 1){
        return 0;
    }else if(valor <= 0){
        printf("Valor deve ser maior que zero.\n");
        return TRUE;
    }else{
        ListNode *aux = l.inicio;
    
        while(aux != NULL){
            if(aux->info == valor){
            
                return TRUE;
            }else{
                aux = aux->prox;
            }
        }

        return FALSE;
    }
    
}

void Produtorio(LNN l, int *n){
    if(isEmpty(l)==1){
        printf("NÃO HÁ VALORES.\n");
        *n = 0;
    }else{
        ListNode *aux = l.inicio;
        *n = 1;
        while(aux != NULL){
            *n *= aux->info;
            aux = aux->prox ;
        }
        
    }
}
void list(LNN l){
    ListNode *aux = l.inicio;
    while(aux != NULL){
        printf("%d\n", aux->info);
        aux = aux->prox;
    }
}
void Esvaziar(LNN *l){
    if(isEmpty(*l)==1){
        printf("Lista já está vázia.\n");
        return;
    }else{
        free(l);
        l->inicio = NULL;
        l->Fim = NULL;
        l->qtd = 0;
    }
}