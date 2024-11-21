#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LDECirc.h"
void exibirOpcoes(){
    printf("Opções: \n");
    printf("1 - Inserir informacoes: \n");
    printf("2 - Passar informacoes 2: \n");
    printf("3 - Intercalar as listas.\n");
    printf("0 - Encerrar.\n");
    printf("Informe a opção desejada:");
}

int main(){
    LDECirc list;
    LDECirc list2;
    LDECirc list3;
    
    incializar(&list);
    incializar(&list2);
    incializar(&list3);
    
    int op;
    int num;
    int igualdade;
     do{
        exibirOpcoes();
        scanf("%d",&op);
        getchar();
        switch (op)
        {
        case 1:
            printf("Digite um numero: \n");
            scanf("%d", &num);
            getchar();
            inserirOrdenado(&list,num);
            
            break;
        case 2:
            printf("Digite um numero: \n");
            scanf("%d", &num);
            getchar();
            inserirOrdenado(&list2,num);
            
            break;
        case 3:
            
            listaIntercalada(list, list2, &list3);
            listar(list3);
            break;
        case 0:
            printf("Bye,bye\n");
            break;
        }
        
    }while(op != 0);
    printf("Programa encerrado com sucesso.\n");
    return 0;
}


