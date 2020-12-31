#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include "pilhas.h"

int main(void) {
	setlocale(LC_ALL,"Portuguese");
	
	char e[40];
	int i;
	char flag;
	pilha p;
	
	init(&p);
	
	printf("Entre com uma expressão:");
	scanf("%s",&e);
	
	//análise da expressão
	flag=1;
	for (i=0;e[i];i++) {
		if (e[i] == '(') {
			push(&p,1);
		}
		else
			if (e[i] == ')') {
				if (not empty(&p)) {
					pop(&p);
				}
				else {
					flag=0;
					break;
				}
			}
	}
	
	if (empty(&p) and flag)
		printf("Expressão correta!!!\n");
	else
		printf("Expressão incorreta!!!\n");
	
	return 1;
}
