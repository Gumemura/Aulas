#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE 1
#define MAX 50

typedef struct{
	char nome[MAX];
	int idade;
	char preferencia[MAX];
	
}PESSOA, *PES;