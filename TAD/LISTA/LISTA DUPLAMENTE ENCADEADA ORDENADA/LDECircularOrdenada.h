#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0
typedef struct ldenode{
    struct ldenode* ant;
    int info;
    struct ldenode* prox;    
    
}LDENode;

typedef struct ldeCirc{
    LDENode *inicio;
    LDENode *fim;
    int qtd; 
} LDECirc;

void incializar(LDECirc *l){
    l->inicio = NULL;
    l->fim = NULL;
    l->qtd = 0;
}

int isEmpty(LDECirc l){
    if(l.qtd == 0){
        return TRUE;
    }else{
        return FALSE;
    }
}

LDENode* criarNo(int valor){
    LDENode *novo = (LDENode*) malloc(sizeof(LDENode));
    novo->ant = NULL;
    novo->info = valor;
    novo->prox = NULL;
    return novo;
}

void inserirOrdenado(LDECirc *lista, int valor){
    LDENode* novo;
    if(isEmpty(*lista)==TRUE){
        novo = criarNo(valor);
        lista->inicio = novo;
        lista->fim = novo;
        lista->qtd = 1;
        novo->prox = novo;
        novo->ant = novo;

    }
    else if(valor == lista->inicio->info){
        printf("Valor repetido. Inserção não efetuada!\n");
    }
    else if(valor < lista->inicio->info){
        novo = criarNo(valor);
        novo->prox = lista->inicio;
        lista->inicio->ant = novo;
        lista->inicio = novo;
        lista->fim->prox = lista->inicio;
        lista->inicio->ant = lista->fim;
        lista->qtd ++;
    }
}