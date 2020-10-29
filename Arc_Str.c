#include "pessoa.h"

void ExibirDados(FILE* f, char nomeArq[MAX]){
	f = freopen(nomeArq, "r", f);
	char nome[MAX], pref[MAX];
	int idade;

	while(fscanf(f, "%s %d %s", nome, &idade, pref) == 3){
		printf("Nome: %s\n", nome);
		printf("Idade: %d\n", idade);
		printf("Preferencia: %s\n\n", pref);
	}
}

void InserirDados(FILE* f, char nomeArq[MAX], char nome[MAX], int idade, char pref[MAX]){
	f = freopen(nomeArq, "a", f);
	fprintf(f, "\n%s %d %s", nome, idade, pref);
}

PES InicializarPessoa(char nome[MAX], int idade, char pref[MAX]){
	PES pessoaX = (PES) malloc(sizeof(PESSOA));
	strcpy(pessoaX -> nome, nome);
	pessoaX -> idade = idade;
	strcpy(pessoaX -> preferencia, pref);

	return pessoaX;
}



int main(){
	char nomeArquivo[MAX];

	printf("Insira o nome do arquivo a ser lido\n");
	scanf("%s", nomeArquivo);
	printf("\n");

	for(int i = 0; i < MAX; i++){
		if(nomeArquivo[i] == '\0'){
			nomeArquivo[i] = '.';
			nomeArquivo[i + 1] = 't';
			nomeArquivo[i + 2] = 'x';
			nomeArquivo[i + 3] = 't';
			nomeArquivo[i + 4] = '\0';
			break;
		}
	}

	FILE* arquivo = fopen(nomeArquivo, "r");

	if(arquivo == NULL){
		printf("Erro! Documento nao encontrado");
		exit(1);
	}

	InserirDados(arquivo, nomeArquivo, "Guilherme_Umemura", 25, "Jogos_Programacao_Comida");
	ExibirDados(arquivo, nomeArquivo);

	fclose(arquivo);
}

