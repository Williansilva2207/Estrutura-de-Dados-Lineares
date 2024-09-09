#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Stack5.h"
char *criar(char *string);
void liberar(char *s);
int main(){
    Stack pilha1;
    inicializar(&pilha1);

    char *num;
    num = criar(num);
    

    
    printf("Insira um numero maior que zero: ");
    fgets(num, sizeof(num), stdin);
    
    for(int i = 0; i < strlen(num); i++){
        int valor = num[i];
        push(&pilha1, valor);
    }
    while (isEmpty(pilha1) == 0){
        
        printf("%c", pop(&pilha1));
    }
    printf("\n");
    liberar(num);
    return 0;
}

char *criar( char* string){
    string = (char*) malloc(sizeof(char));
    if(string != NULL){
        return string;
    }
}

void liberar(char *s){
    free(s);
}