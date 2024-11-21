#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LDECircOrdenad.h"
void exibirOpcoes(){
    printf("Opções: \n");
    printf("1 - Inserir informacoes: .\n");
    printf("2 - Passar informacoes de aprovados e  reprovados.\n");
    printf("3 - Listar Informacoes.\n");
    printf("0 - Encerrar.\n");
    printf("Informe a opção desejada:");
}
void excluirEnter(char name[]);
int main(){
    LDECirc list;
    LDECirc listAp;
    LDECirc listReprovMed;
    LDECirc listFalta;
    inicializar(&list);
    inicializar(&listAp);
    inicializar(&listReprovMed);
    inicializar(&listFalta);
    int op;
    int falta;
    int matricula;
    char name[100];
    double media;
    int igualdade;
     do{
        exibirOpcoes();
        scanf("%d",&op);
        getchar();
        switch (op)
        {
        case 1:
            
            printf("Nome:\n");
            fgets(name, 100, stdin);
            excluirEnter(name);
            printf("Matricula:\n");
            scanf("%d", &matricula);
            getchar();
            printf("Media:\n");
            scanf("%lf", &media);
            getchar();
            printf("Faltas: \n");
            scanf("%d", &falta);
            getchar();
            inserirOrdenado(name, matricula, media, falta, &list);
            
            break;
        case 2:
            aprovados(list, &listAp, &listReprovMed, &listFalta);
            printf("Transicao realizada com sucesso.\n");
            break;
        case 3:
            
            printf("Aprovados:\n");
            listar(listAp);
            printf("\n");
            printf("Reprovados por Media:\n");
            listar(listReprovMed);
            printf("\n");
            printf("Reprovados por falta:\n");
            listar(listFalta);
            printf("\n");
            break;
        case 0:
            printf("Bye,bye\n");
            break;
        }
        
    }while(op != 0);
    printf("Programa encerrado com sucesso.\n");
    return 0;
}

void excluirEnter(char name[]){
    int num = strlen(name);
    if(name[num-1] == '\n'){
        name[num-1] = '\0';

    }
}
