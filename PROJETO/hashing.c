#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 57
typedef struct carro {
	char placa[8];
	char marca[15];
	char modelo[15];
	char cor[15];
	int status;  
} CARRO;

typedef struct noTabela {
	char placa[8];
	int posicao;
	struct noTabela* prox;
	struct noTabela* ant;
} No;

FILE* prepararArquivo(char nome[]);
void fecharArquivo(FILE* arq);
int buscar(No* tabelaHashing[], char placa[]);
void cadastrar(FILE* arq, No* tabelaHashing[]);
void consultar(FILE* arq, No* tabelaHashing[]);
void alterar(FILE* arq, No* tabelaHashing[]);
void remover(FILE* arq, No* tabelaHashing[]);
void exibirCadastro(FILE* arq);
void criarIndice(FILE* arq, No* tabelaHashing[]);
void inserirTabelaHash(No* tabelaHashing[], char placa[], int pos);
int hashing(char placa[]);
void liberarArquivo(FILE* arq);
void desalocarIndice(No* tabelaHashing[]);
void exibirOpcoes();
void alterarMarca(char str[]);
void alterarModelo(char str[]);
void alterarCor(char str[]);

int main() {
	char nomeArq[] = "carros.dat";
	int op;
	FILE* cadastro;
	No* tabelaHashing[N];
	cadastro = prepararArquivo(nomeArq);
	if (cadastro == NULL)
		printf("Erro na abertura do arquivo. Programa encerrado \n");
	else {
		criarIndice(cadastro, tabelaHashing);
		do {
			exibirOpcoes();
			scanf("%d",&op); 
			getchar();
			switch (op) {
			case 1: cadastrar(cadastro, tabelaHashing);
		                              break;
			case 2: consultar(cadastro, tabelaHashing);
			             break;
			case 3: alterar(cadastro, tabelaHashing);
			             break;
			case 4: remover(cadastro, tabelaHashing);
			             break;
			case 5: exibirCadastro(cadastro);
			             break;
			case 0: liberarArquivo(cadastro);
			             desalocarIndice(tabelaHashing);
			             break;
			default: printf("Opcao invalida \n");
			}
		} while (op != 0);
	}
	return 0;
}

FILE* prepararArquivo(char nome[]) {
    FILE* arquivo = fopen(nome, "r+b");
    if (arquivo == NULL) {
        arquivo = fopen(nome, "w+b");
        if (arquivo == NULL) {
            printf("Erro ao criar ou abrir o arquivo: %s\n", nome);
            return NULL;
        }
    
	}
	
    return arquivo;
}

void liberarArquivo(FILE* arq) {
	
	FILE* novo = prepararArquivo("temp.dat");
	if(arq == NULL){
		printf("Não é possível abrir o arquivo.\n");
		return;
	}
	rewind(arq);
	CARRO carro;
    while ( fread(&carro, sizeof(CARRO), 1, arq)) {
        
        if (carro.status == 1) {
            fwrite(&carro, sizeof(CARRO),1,novo);
        }
    }
	fclose(arq);
	fclose(novo);
	remove("carros.dat");
	rename("temp.dat", "carros.dat");
}

void criarIndice(FILE* arq, No* tabelaHashing[]) {
	/* Preencher a tabela de hashing com as chaves dos registros que estão armazenados no arquivo
	       1.1 - Ler o arquivo registro a registro até o final.
	       1.2 - Para cada registro lido, aplicar a função de hashing à chave (ou seja, a placa).
	       1.3 - O resultado da função indica a posição na tabela onde a chave será inserida.
	       1.4 - Criar nó, preencher com a chave e a posição dela no arquivo e inserir na tabela, 
	                na lista encadeada correspondente, de forma que a lista permaneça ordenada 
                                 por ordem crescente de placa.
	*/
	
	for(int i = 0; i < N; i++){
		tabelaHashing[i] = NULL;
	}
	
	CARRO carro;
	int posicao = 0;
	rewind(arq);
 
    while (fread(&carro, sizeof(CARRO), 1, arq) == 1) {
    	if (carro.status == 1) {
           		
        	inserirTabelaHash(tabelaHashing, carro.placa, posicao);
    	}
    	posicao++;
	}
}
	


void desalocarIndice(No* tabelaHashing[]) {
	
 	for (int i = 0; i < N; i++) {
        No* atual = tabelaHashing[i];
        while (atual != NULL) {
            No* anterior = atual;
            atual = atual->prox;
            free(anterior);
        }
        tabelaHashing[i] = NULL;  
    }
}

void exibirOpcoes() {
	printf("Opções \n");
	printf("1 - Cadastrar um carro \n");
	printf("2 - Consultar carro \n");
	printf("3 - Alterar dados do carro \n");
	printf("4 - Remover carro \n");
	printf("5 - Exibir carros cadastrados \n");
	printf("0 - Encerrar programa \n");
	printf("Informe a opcao: ");
}

int buscar(No* tabelaHashing[], char placa[]) {
	
	int indice = hashing(placa);
	No* aux = tabelaHashing[indice];
	while(aux != NULL){
		if(strcmp(aux->placa, placa)==0){
			return aux->posicao;
		}else{
			aux = aux->prox;
		}
	}
	return -1;
}

void inserirTabelaHash(No* tabelaHashing[], char placa[], int pos) {
	
	int indiceHash = hashing(placa);
	No* novo;
	novo = (No*) malloc(sizeof(No));
	strcpy(novo->placa, placa);
	novo->prox = NULL;
	novo->ant = NULL;
	novo->posicao = pos;
	No* atual = tabelaHashing[indiceHash];
	No* anterior = NULL;
	if(tabelaHashing[indiceHash] == NULL){
		tabelaHashing[indiceHash] = novo;
	}else if(strcmp(novo->placa, atual->placa)< 0){
		novo->prox = tabelaHashing[indiceHash];
		tabelaHashing[indiceHash]->ant = novo;
		novo->ant = NULL;
		tabelaHashing[indiceHash] = novo;
	}else{
		atual = tabelaHashing[indiceHash]->prox;
		anterior = tabelaHashing[indiceHash];
		while(1){
			if(strcmp(novo->placa, atual->placa) < 0){
				novo->prox = atual;
				novo->ant = anterior;
				anterior->prox = novo;
				atual->ant = novo;
				return;
			}else if(atual == NULL && strcmp(novo->placa,anterior->placa)>0){
				anterior->prox = novo;
				novo->ant = anterior;
				return;
			}else{
				anterior = atual;
				atual = atual->prox;
			}
				
		}
	}


}

void removerTabelaHash(No* tabelaHashing[], char placa[], int posTabela) {

	int indice = hashing(placa);
	No* aux = tabelaHashing[indice];
	if(strcmp(aux->placa, placa) == 0 && aux->prox == NULL){
		
		free(aux);
	}else{
		No* aux = tabelaHashing[indice]->prox;
		No* anterior = tabelaHashing[indice];
		while(1){
			if(strcmp(aux->placa, placa) == 0 && aux->prox != NULL){
				anterior->prox = aux->prox;
				aux->prox->ant = anterior;
				free(aux);
				return;
			}else if(strcmp(aux->placa, placa)== 0 && aux->prox == NULL){
				
				free(aux);
				return;
			}else{
				anterior = aux;
				aux = aux->prox;
			}
				
		}
	}
}

int hashing(char placa[]) {
	
	int i, soma = 0, tam = strlen(placa);
	for (i = 0; i < tam; i++) {
		soma = soma + placa[i];
	}
	return abs(soma) % N;
}


void cadastrar(FILE* arq, No* tabelaHashing[]) {
	
	CARRO carro;
	printf("Digite a placa do carro:\n");
	scanf("%s", carro.placa);
	getchar();
	
	//tirarEnter(carro.placa);
	int busca = buscar(tabelaHashing, carro.placa);
	if(busca != -1){
		printf("O carro já está cadastrado.\n");
	}else{
	    
		printf("Digite a marca:\n");
		scanf("%s", carro.marca);
		getchar();
		printf("Digite a modelo:\n");
		scanf("%s", carro.modelo);
		getchar();
		printf("Digite a cor:\n");
		scanf("%s", carro.cor);
		getchar();
		carro.status = 1;

		fseek(arq, 0, SEEK_END);
		fwrite(&carro, sizeof(CARRO), 1, arq);
		int posicion = ftell(arq)/sizeof(CARRO)-1;

		inserirTabelaHash(tabelaHashing, carro.placa,posicion);
		printf("Cadastro realizado com sucesso!\n");
	}
}

void consultar(FILE* arq, No* tabelaHashing[]) {

	char placa[8];
	printf("Informe a placa do carro:\n");
	scanf("%s", placa);
	getchar();
	int busca = buscar(tabelaHashing, placa);
	if(busca == -1){
		printf("Carro não está no cadastro.\n");
	}else{
		CARRO carro;
		
		fseek(arq, busca*sizeof(CARRO), SEEK_SET);
		fread(&carro, sizeof(CARRO),1,arq);
		printf("Placa: %s |\t", carro.placa); 
		printf("Modelo: %s |\t", carro.modelo); 
		printf("Marca: %s |\t", carro.marca); 
		printf("Cor: %s |\t", carro.cor); 
		printf("Status: %d\n", carro.status); 

	}

}

void alterar(FILE* arq, No* tabelaHashing[]) {

	char placa[8];
	printf("Informe a placa do carro a ser alterada:\n");
	scanf("%s", placa);
	getchar();
	int busca = buscar(tabelaHashing, placa);
	if(busca == -1){
		printf("Carro não está no cadastro.\n");
	}else{
		CARRO carro;
		
		fseek(arq, busca*sizeof(CARRO), SEEK_SET);
		fread(&carro, sizeof(CARRO),1,arq);
		
		printf("Modelo: %s |\t", carro.modelo); 
		printf("Marca: %s |\t", carro.marca); 
		printf("Cor: %s |\t", carro.cor); 
		
		int op;
		do{
			printf("\nQuais dados pretende alterar:\n");
			
			printf("Modelo (digite 1) \n"); 
			printf("Marca (digite 2) \n"); 
			printf("Cor (digite 3) \n"); 
			
			printf("SAIR (digite 0)\n");
			scanf("%d", &op);
			getchar();
			switch(op){

				case 1:
					alterarModelo(carro.modelo);
					break;
				case 2:
					alterarMarca(carro.marca);
					break;
				case 3:
					alterarCor(carro.cor);
					break;
				
				default:
					printf("Essa opção não é possível.\n");
					break;
			}
		}while(op!=0);
		fseek(arq, busca*sizeof(CARRO), SEEK_SET);
		fwrite(&carro, sizeof(CARRO),1, arq);
		printf("Informacoes alteradas.\n");
	}
}

void remover(FILE* arq, No* tabelaHashing[]) {

	char placa[8];
	printf("Informe a placa do carro:\n");
	scanf("%s", placa);
	int busca = buscar(tabelaHashing, placa);
	if(busca == -1){
		printf("Carro não está no cadastro.\n");
	}else{
		int op;
		CARRO carro;
		
		fseek(arq, busca*sizeof(CARRO), SEEK_SET);
		fread(&carro, sizeof(CARRO),1,arq);
		printf("Placa: %s |\t", carro.placa); 
		printf("Modelo: %s |\t", carro.modelo); 
		printf("Marca: %s |\t", carro.marca); 
		printf("Cor: %s |\t", carro.cor); 
		printf("Status: %d\n\n", carro.status);
		printf("Digite 1: Realmente quer remover este carro.\nDigite 2: Abortar remocao.\n");
		scanf("%d", &op);
		getchar();
		if(op == 1){
			carro.status = 0;
			removerTabelaHash(tabelaHashing,carro.placa,busca);
			fseek(arq, busca*sizeof(CARRO), SEEK_SET);
			fwrite(&carro, sizeof(CARRO), 1, arq);
		}else{
			printf("Remocao abortada.\n");
		}
	}
}

void exibirCadastro(FILE* arq) {
	if(arq == NULL){
		printf("Não é possível abrir o arquivo.\n");
		return;
	}
	rewind(arq);
	CARRO carro;
    while ( fread(&carro, sizeof(CARRO), 1, arq)) {
        
        if (carro.status == 1) {
            
            printf("Placa: %s\n", carro.placa);
            printf("Marca: %s\n", carro.marca);
            printf("Modelo: %s\n", carro.modelo);
            printf("Cor: %s\n", carro.cor);
            printf("Status: %d\n", carro.status);
            printf("-----------------------------\n");
        }
    }
}


void alterarMarca(char str[]){
	scanf("%s", str);
	getchar();
	printf("Marca alterada.\n");
}
void alterarModelo(char str[]){
	scanf("%s", str);
	getchar();
	printf("Modelo alterado.\n");
}
void alterarCor(char str[]){
	scanf("%s", str);
	getchar();
	printf("Cor alterada.\n");
}



