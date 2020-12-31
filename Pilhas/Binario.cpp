#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include "pilhas.h"

int main(void) {
	setlocale(LC_ALL,"Portuguese");
	
	pilha p;
	int n,r;
	
	init(&p); // inicializar a pilha p;
	
	printf("Entre com um número inteiro:");
	scanf("%d",&n);
	
	while (n > 0) {
		r = n % 2;
		if (!isfull(&p)) {
			push(&p,r);
		}
		else {
			printf("Pilha cheia!!");
			return 1; // exit(1);
		}
		n = n / 2;
	}
	
	printf("Correspondente em binário:");
	while (!empty(&p))
	//while (p.topo > 0)
	{
		printf("%d",pop(&p));
	}
	
	return 1;
}
