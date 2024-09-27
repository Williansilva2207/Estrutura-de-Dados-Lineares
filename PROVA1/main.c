#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LNN.h"
#define TRUE 1;
#define FALSE 0;

void exibirOpcoes(){
    printf("Opções: \n");
    printf("1 - Inserir um número.\n");
    printf("2 - Produtório dos números.\n");
    printf("0 - Encerrar.\n");
    printf("Informe a opção desejada:");
}

int main(){
    LNN numeros;
    int op;
    int num = 0;
    int prod = 0;
    inicializar(&numeros);

    do{
        exibirOpcoes();
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            
            printf("Insira o valor:\n");
            scanf("%d",&num);
            
            Inserir(&numeros, num);
            list(numeros);
            break;
        case 2:
            Produtorio(numeros, &prod);
            printf("O produtório e: %d\n", prod);
            break;
        case 0:
            Esvaziar(&numeros);
            printf("Encerrando...");
            break;
        }
        
    }while(op != 0);
    printf("Programa encerrado com sucesso.\n");
    return 0;
}