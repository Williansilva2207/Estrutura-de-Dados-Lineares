#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0
typedef struct ldenode{
    struct ldenode* ant;
    int info;
    struct ldenode* prox;    
    
}LDENode;

typedef struct lde{
    LDENode *inicio;
    LDENode *fim;
    int qtd; 
} LDE;

void inicializar(LDE *l){
    l->inicio = NULL;
    l->fim = NULL;
    l->qtd = 0;
}

int isEmpty(LDE l){
    if(l.qtd == 0){
        return TRUE;
    }else{
        return FALSE;
    }
}

void inserirInicio(LDE *l, int valor){
    LDENode *novo = (LDENode*) malloc(sizeof(LDENode));
    novo->ant = NULL;
    novo->prox = NULL;
    novo->info = valor;
    if(isEmpty(*l) == TRUE){
        l->inicio = novo;
        l->fim = novo;
    }else{
        novo->prox = l->inicio;
        l->inicio->ant = novo;
        l->inicio = novo;
    }
    l->qtd++;
}

void deTrasPraFrente(LDE l){
    LDENode *aux = l.fim;
    if(isEmpty(l) == TRUE){
        printf("Está vazia.\n");
    }else{
        while (aux != NULL){
            printf("%d ", aux->info);
            aux = aux->ant;
        }
        printf("\n");
    }
}
void list(LDE l){
    LDENode *aux = l.inicio;
    if(isEmpty(l) == TRUE){
        printf("Está vazia.\n");
    }else{
        while (aux != NULL){
            printf("%d ", aux->info);
            aux = aux->prox;
        }
        printf("\n");
    }
}
void inserirFinal(LDE *l, int valor){
    LDENode *novo = (LDENode*) malloc(sizeof(LDENode));
    novo->ant = NULL;
    novo->prox = NULL;
    novo->info = valor;
    if(isEmpty(*l) == TRUE){
        l->inicio = novo;
        l->fim = novo;
    }else{
        novo->ant = l->fim;
        l->fim->prox = novo;
        l->fim = novo;
    }
    l->qtd++;
}

void removerPrimeiro(LDE *l){
    LDENode *aux = l->inicio;
    
    if(isEmpty(*l) == TRUE){
        printf("Está vazia.\n");
        
    }else if(l->qtd == 1){
        l->inicio = NULL;
        l->fim = NULL;
        l->qtd --;
        free(aux);
    }else{
        l->inicio = l->inicio->prox;
        l->inicio->ant = NULL;
        l->qtd --;
        free(aux);
    }
}

void removerUltimo(LDE *l){
    LDENode *aux = l->fim;
    
    if(isEmpty(*l) == TRUE){
        printf("Está vazia.\n");
        
    }else if(l->qtd == 1){
        l->inicio = NULL;
        l->fim = NULL;
        l->qtd --;
        free(aux);
    }else{
        l->fim = l->fim->ant;
        l->fim->prox = NULL;
        l->qtd --;
        free(aux);
    }
}