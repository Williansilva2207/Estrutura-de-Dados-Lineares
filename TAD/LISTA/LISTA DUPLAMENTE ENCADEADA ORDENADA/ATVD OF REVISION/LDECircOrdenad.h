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
    LDENode* atual;
    LDENode* anterior;
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
    else if(valor == lista->fim->info){
        printf("Valor repetido. Inserção não efetuada! \n");

    }else if(valor > lista->fim->info){
        novo = criarNo(valor);
        novo->ant = lista->fim;
        lista->fim->prox = novo;
        lista->fim = novo;
        novo->prox = lista->inicio; //lista->fim->prox = lista->inicio;
        lista->inicio->ant = novo; // lista->inicio->ant = lista->fim;
        lista->qtd++;
    }else{//inserir no meio
        atual = lista->inicio->prox;
        while(TRUE){
            if(valor == atual->info){
                printf("Valor repetido. Inserção não efetuada!\n");
                break;
            }
            else if(valor < atual->info){
                anterior = atual->ant;
                novo = criarNo(valor);
                anterior->prox = novo;
                novo->ant = anterior;
                atual->ant = novo;
                novo->prox = atual;
                lista->qtd++;
                break;
            }
            else{
                atual = atual->prox;
            }
        }
    }
}

LDECirc dividir(LDECirc *L1){
    LDENode*aux = L1->inicio;
    LDECirc aux2;
    incializar(&aux2);
    int ctd = 0;
    if(L1->qtd == 1){
         return aux2;
    }else{
        while(TRUE){
            if(ctd > L1->qtd/2){
                aux2.inicio = aux;
                aux2.fim = L1->fim;
                aux2.fim->prox = aux2.inicio;
                aux2.inicio->ant = aux2.fim;
                aux2.qtd = (L1->qtd) - (L1->qtd/2);
                L1->fim = aux->ant;
                L1->fim->prox = L1->inicio;
                L1->inicio->ant = L1->fim;
                return aux2;  
            }else{
                aux = aux->prox;
                ctd ++;
            }
        }
    }
     
}    

