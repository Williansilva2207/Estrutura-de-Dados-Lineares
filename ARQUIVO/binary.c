#include <stdio.h>
#include <string.h>
//FILE *nome do arquivo 
//FILE *fopen(nomeDoArquivo, modoAertura)
FILE *prepararArquivo(char* nome){
    FILE* aux;
    aux = fopen(nome, "r+b");
    if(aux == NULL){
        aux = fopen (nome, "w+b");
    }
    return aux;
}

void liberarArquivo(FILE* arquivo, char* nome){
    int status;
    status =fclose(arquivo);
    if(status == 0){
        printf("Arquivo %s fechadocm sucesso\n", nome);
    }else{
        printf("Deu ruim\n");
    } 
}
void retirarEnter(char* str){
    int number = strlen(str);
    if(str[number-1]== '\n'){
        str[number-1] = '\0';
    }
}
int main(){
    char nomeArq[100];
    FILE *arq;
    int i, retorno;

    printf("Informe o nome do arquivo: ");
    fgets(nomeArq, 100, stdin);
    arq = prepararArquivo(nomeArq);
    if(arq == NULL){
        printf("Erro ao tentar criar/abrir o arquivo %s \n", nomeArq);
    }else{
        printf("Arquivo crado com sucesso\n");
        liberarArquivo(arq, nomeArq);
    }
    return 0;
}
