#include <stdio.h>
#include <stdlib.h>
#include "LDEEncadeada.h"
void exibirOpcoes(){
    printf("Opções: \n");
    printf("1 - Inserir um número na lsita 1.\n");
    printf("2 - Inserir na lista 2.\n");
    printf("3 - Comparar.\n");
    printf("0 - Encerrar.\n");
    printf("Informe a opção desejada:");
}

int main(){
    LDEEnca list;
    LDEEnca list2;
    inicializar(&list);
    inicializar(&list2);
    int op;
    int num;
    int igualdade;
     do{
        exibirOpcoes();
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            
            printf("Insira o valor:\n");
            scanf("%d",&num);
            
            inserir(&list, num);
            
            break;
        case 2:
            printf("Insira o valor:\n");
            scanf("%d",&num);
            
            inserir(&list2, num);
            
            break;
        case 3:
            igualdade = comparar(&list, &list2);
            printf("Ele é %d\n", igualdade);
            break;
        case 0:
            printf("Bye,bye\n");
            break;
        }
        
    }while(op != 0);
    printf("Programa encerrado com sucesso.\n");
    return 0;
}


