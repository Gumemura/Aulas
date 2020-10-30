#include "interface_usuario.h"

int ExibirDados(FILE* f, USUARIOSIMPLES usuariosArray[MAX]){
	char nomeUsuario[MAX];
	int idadeUsuario;
	char preferenciaUsuario[MAX];
	int index = 0;

	while(fscanf(f, "%s %d %s", nomeUsuario, &idadeUsuario, preferenciaUsuario) == VARS){
		// printf("Nome: %s\n", nomeUsuario);
		// printf("Idade: %d\n", idadeUsuario);
		// printf("Preferencia: %s\n\n", preferenciaUsuario);

		strcpy(usuariosArray[index].nome, nomeUsuario);
		usuariosArray[index].idade = idadeUsuario;
		strcpy(usuariosArray[index].pref, preferenciaUsuario);

		index++;
	}

	return index;
}

void InserirDados(FILE* f, char nomeArq[MAX], char dados[MAX]){
	f = freopen(nomeArq, "a", f);
	fprintf(f, "\n%s", dados);
}

int main(){
	USUARIOSIMPLES usuarios[MAX];

	char nomeArquivo[MAX];

	printf("Insira o nome do arquivo: ");
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

	FILE* arquivo;
	arquivo = fopen(nomeArquivo, "r");

	if(arquivo == NULL){
		printf("Documento nao encontrado\n");
		exit(1);
	}

	int limitWhile = ExibirDados(arquivo, usuarios);

	int i = 0;
	while(i < limitWhile){
		printf("Nome: %s\n", usuarios[i].nome);
		printf("Idade: %d\n", usuarios[i].idade);
		printf("Preferencia: %s\n", usuarios[i].pref);
		i++;
	}


	// char linha[MAX];
	// while(fgets(linha, MAX, arquivo) != NULL){
	// 	printf("%s\n", linha);
	// }


	fclose(arquivo);
}

