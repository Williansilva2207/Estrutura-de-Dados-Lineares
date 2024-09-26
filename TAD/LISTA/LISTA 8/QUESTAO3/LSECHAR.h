#define TRUE 1
#define FALSE 0
#define TAM 100
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct listNode {
    char info[TAM];
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

int buscar (LSE l, char valor[TAM]) { // busca sequencial simples
    ListNode* aux;
    if (isEmpty(l) == TRUE) {
        return FALSE;
    }
    else {
        aux = l.inicio;
        while (aux != NULL) {
            if (strcmp(aux->info, valor)==0) {
                return TRUE;
            }
            aux = aux->prox;
        }
        return FALSE;
    }
}

void inserirFinal (LSE* l, char valor[TAM]) {
    ListNode* novo;
    int achou;
    novo = (ListNode*) malloc (sizeof(ListNode));
    strcpy(novo->info, valor);
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

void inserirInicio (LSE* l, char valor[TAM]) {
    ListNode* novo;
    int achou;
    novo = (ListNode*) malloc (sizeof(ListNode));
    strcpy(novo->info, valor);
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
void cancel(LSE *f, char valor[100]){
    ListNode *atual, *anterior;
    if(isEmpty(*f)==1){
        printf("FILA VAZIA. \n");
    }
    else if(f->inicio = f->fim){//tem um nó
        if(strcmp(f->inicio->info, valor)==0){
            free(f->inicio);
            f->inicio = NULL;
            f->fim = NULL;
        }else{
            printf("Valor não encontrado! \n");
        }
    }else{//mais de um nó
        if(strcmp(f->inicio->info, valor)==0){ //remoção do inicio
            atual = f->inicio;
            f->inicio = f->inicio->prox; //ou f->inicio = aux->prox
            free(atual);
            printf("Cancelamento efetuado!");
        }else{
            atual = f->inicio->prox;
            anterior = f->inicio;
            while(atual != NULL){
                if(strcmp(atual->info, valor)==0){//achei
                    anterior->prox = atual->prox;
                    if(atual->prox == NULL){
                        f->fim = anterior;
                    }
                    free(atual);
                    printf("Cancelamento efetuado! \n");
                    return;
                }else{
                    anterior = atual;
                    atual = atual->prox;
                }
            }
            printf("Arquivo não encontrado! \n");
        }
    }

}
