#define TRUE 1
#define FALSE 0
#include <stdlib.h>
#include <stdio.h>
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
   if (l.qtd == 0) {
    return TRUE;
   }
   else {
    return FALSE;
   }
}

int buscar (LSE l, int valor) { // busca sequencial simples
    ListNode* aux;
    if (isEmpty(l) == TRUE) {
        return FALSE;
    }
    else {
        aux = l.inicio;
        while (aux != NULL) {
            if (aux->info == valor) {
                return TRUE;
            }
            aux = aux->prox;
        }
        return FALSE;
    }
}

void inserirFinal (LSE* l, int valor) {
    ListNode* novo;
    int achou;
    novo = (ListNode*) malloc (sizeof(ListNode));
    novo->info = valor;
    novo->prox = NULL;
    if (isEmpty(*l) == TRUE) {
        l->inicio = novo;
        l->fim = novo;
        l->qtd++;
        printf ("Inserção efetuada! \n");
    }
    else {
        achou = buscar(*l, valor);
        if (achou == FALSE) {
            l->fim->prox = novo;
            l->fim = novo;
            l->qtd++;
            printf ("Inserção efetuada! \n");
        }
        else {
            free (novo);
            printf("Valor repetido! Inserção não efetuada! \n");
        }
    }
}

void inserirInicio (LSE* l, int valor) {
    ListNode* novo;
    int achou;
    novo = (ListNode*) malloc (sizeof(ListNode));
    novo->info = valor;
    novo->prox = NULL;
    if (isEmpty(*l) == TRUE) {
        l->inicio = novo;
        l->fim = novo;
        l->qtd++;
        printf ("Inserção efetuada! \n");
    }
    else {
        achou = buscar (*l, valor);
        if (achou == FALSE) {   
            novo->prox = l->inicio;
            l->inicio = novo;
            l->qtd++;
            printf ("Inserção efetuada! \n");
        }
        else {
            free (novo);
            printf("Valor repetido! Inserção não efetuada! \n");
        }
    } 
}

void removerInicio (LSE* l) {
    ListNode* aux;
    if (isEmpty(*l) == TRUE) {
        printf ("Lista vazia! \n");
    }
    else {
        aux = l->inicio;
        if (l->qtd == 1) {
            l->inicio = NULL;
            l->fim = NULL;
        }
        else {
            l->inicio = l->inicio->prox;
        }
        l->qtd--;
        free(aux);
        printf ("Remoção efwtuada! \n");
    }
}

void removerUltimo (LSE* l) {
    ListNode* aux;
    if (isEmpty(*l) == TRUE) {
        printf ("Lista vazia! \n");
    }
    else {
        aux = l->inicio;
        if (l->qtd == 1) {
            l->inicio = NULL;
            l->fim = NULL;
            free(aux);
        }
        else {
            while (aux->prox != l->fim) {
                aux = aux->prox;
            }
            free(aux->prox);
            aux->prox = NULL;
            l->fim = aux;
        }
        l->qtd--;
        printf ("Remoção efwtuada! \n");
    }
}

void list (LSE l) {
    ListNode* aux;
    if (isEmpty(l) == TRUE) {
        printf ("Lista vazia! \n");
    }
    else {
        aux = l.inicio;
        while (aux != NULL) {
            printf ("%d ", aux->info);
            aux = aux->prox;
        }
        printf ("\n");
    }
}

void copiar(LSE lista1, LSE *lista2){
    ListNode *aux;
    
    if(isEmpty(lista1) ==TRUE){
        return;
    }
    else{
        aux = lista1.inicio;
        while(aux != NULL){
            inserirFinal(lista2, aux->info);
            aux = aux->prox;
            
        }
        
    }
}