/* Arquivo com acesso direto via hashing */
#include <stdio.h>
#include <string.h>
#define N 57
typedef struct carro {
	char placa[8];
	char marca[15];
	char modelo[15];
	char cor[15];
	int status;  // 1 - ativo ou 0 - removido
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
void exibirOpcoes();

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
			scanf("%d",&op); fflush(stdin);
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
    FILE* arquivo = fopen(nome, "rb");
    if (arquivo == NULL) {
        arquivo = fopen(nome, "wb");
        if (arquivo == NULL) {
            printf("Erro ao criar ou abrir o arquivo: %s\n", nome);
            return NULL;
        }
    
	}
	
    return arquivo;
}

void liberarArquivo(FILE* arq) {
	/* Apagar, fisicamente, os registros que foram deletados logicamente e fechar o arquivo.
	*      1.1 - Criar um arquivo novo (vazio).
	*      1.2 - Copiar todos os registros de STATUS igual a 1 do arquivo de carros para o arquivo novo.
	*      1.3 - Fechar os dois arquivos.
	*      1.4 - Remover o arquivo de carros ("carros.dat").
	*      1.5 - Renomear o arquivo novo com o nome "carros.dat".
	*/
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
	if(arq == NULL){
		for(int i = 0; i < N; i++){
			tabelaHashing[i] = NULL;
		}
	}else{

	}
	
}

void desalocarIndice(No* tabelaHashing[]) {
	/* Desalocar os nós que compõem as listas da tabela de hashing.
	*/
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
		No* atual = tabelaHashing[indiceHash]->prox;
		No* anterior = tabelaHashing[indiceHash];
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
	/* Remover da tabela de hashing o nó que contem a placa passada como parâmetro. 
	* Recebe como parâmetro também a posição na tabela onde a chave se encontra.
	*/
}

int hashing(char placa[]) {
	
	int i, soma = 0, tam = strlen(placa);
	for (i = 0; i < tam; i++) {
		soma = soma + placa[i] << (i % 8);
	}
	return abs(soma) % N;
}


void cadastrar(FILE* arq, No* tabelaHashing[]) {
	
	CARRO carro;
	printf("Digite a placa do carro:\n");
	fgets(carro.placa, 8, stdin);
	int busca = buscar(tabelaHashing, carro.placa);
	if(busca != -1){
		printf("O carro já está cadastrado.\n");
	}else{
		printf("Digite a marca:\n");
		fgets(carro.marca, 15, stdin);
		
		printf("Digite a modelo:\n");
		fgets(carro.modelo, 15, stdin);
		
		printf("Digite a cor:\n");
		fgets(carro.cor, 15, stdin);

		carro.status = 1;

		fseek(arq, 0, SEEK_END);
		fwrite(&carro, sizeof(CARRO), 1, arq);
		int posicion = ftell(arq);

		inserirTabelaHash(tabelaHashing, carro.placa,posicion);
		printf("Cadastro realizado com sucesso!\n");
	}
}

void consultar(FILE* arq, No* tabelaHashing[]) {
	/* Consultar o registro do carro no arquivo
                  * 1 - Solicita a placa do carro a ser consultado.
                  * 2 - Procura pela placa na tabela de hashing.
                  * 3 - Caso não encontre, informa que o carro não está no cadastro.
                  * 4 - Caso encontre, vai ao arquivo, na posição indicada, 
	 *     lê o registro do carro e exibe seus dados.
                  */
	char placa[8];
	printf("Informe a placa do carro:\n");
	fgets(placa, 15, stdin);
	int busca = buscar(tabelaHashing, placa);
	if(busca == -1){
		printf("Carro não está no cadastro.\n");
	}else{
		CARRO carro;
		fseek(arq, busca, SEEK_SET);
		fread(&carro, sizeof(CARRO),1,arq);
		printf("Placa: %s |\t", carro.placa); 
		printf("Modelo: %s |\t", carro.modelo); 
		printf("Marca: %s |\t", carro.marca); 
		printf("Cor: %s |\t", carro.cor); 
		printf("Status: %d\n", carro.status); 

	}

}

void alterar(FILE* arq, No* tabelaHashing[]) {
	/* Alterar o registro do carro no arquivo.
	 * 1 - Solicita a placa do carro a ser alterado.
	 * 2 - Procura pela placa na tabela de hashing.
	 * 3 - Caso não encontre, informa que o carro não está no cadastro.
	 * 4 - Caso encontre, vai ao arquivo, na posição indicada, lê o registro do carro e 
                         exibe seus dados.
	 * 5 - Pergunta ao usuário quais dados deseja alterar. Efetiva a alteração dos dados no arquivo.
	*/
	char placa[8];
	printf("Informe a placa do carro a ser alterada:\n");
	fgets(placa, 15, stdin);
	int busca = buscar(tabelaHashing, placa);
	if(busca == -1){
		printf("Carro não está no cadastro.\n");
	}else{
		CARRO carro;
		fseek(arq, busca, SEEK_SET);
		fread(&carro, sizeof(CARRO),1,arq);
		printf("Placa: %s |\t", carro.placa); 
		printf("Modelo: %s |\t", carro.modelo); 
		printf("Marca: %s |\t", carro.marca); 
		printf("Cor: %s |\t", carro.cor); 
		printf("Status: %d\n", carro.status); 

	}
}

void remover(FILE* arq, No* tabelaHashing[]) {
	/* Remover o registro do carro do arquivo
	 * 1 - Solicita a placa do carro a ser removido.
	 * 2 - Procura pela placa na tabela de hashing.
	 * 3 - Caso não encontre, informa que o carro não está no cadastro.
	 * 4 - Caso encontre, vai ao arquivo, na posição indicada, lê o registro do carro e exibe seus dados.
	 * 5 - Pergunta ao usuário se deseja realmente removê-lo. Efetiva a remoção que consiste 
                         em alterando no arquivo o STATUS do registro do carro para 0 (removido).
	 * 5 - Remove o nó que contém a chave, juntamente com sua posição no arquivo, 
                          da tabela de hashing. Utilize para isso o procedimento "removerTabelaHash".
	*/
}

void exibirCadastro(FILE* arq) {
	/* Exibe todos os registros de carros ATIVOS constantes no arquivo. */
}