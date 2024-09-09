#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack5.h"
int pali(Stack *s, char *c );

char *criar( char* string);

void liberar(char *s);

int main()
{
    Stack pilha1;
    inicializar(&pilha1);

    char *num;
    num = criar(num);
    

    
    printf("Insira uma palavra:\n");
    fgets(num, sizeof(num), stdin);
    
    for(int i = 0; i < strlen(num)-1; i++){
        int valor = num[i];
        push(&pilha1, valor);
    }
    if(pali(&pilha1, num)==0){
        printf("Não é palindromo");
    }
    else{
        printf("É um palindromo");
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

 
int pali(Stack *s, char *c ){
    for(int i = 0; i < strlen(c)-1;i++){
        
        if(c[i] != pop(s)){
            return 0;
        }
    }
       
        
}