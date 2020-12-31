#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include "pilhas.h"

int main(void) {
	setlocale(LC_ALL,"Portuguese");
	
	pilha p;
	int n1,n2,i;
	
	printf("Entre com um número inteiro:");
	scanf("%d",&n1);
	n2 = n1;
	
	init(&p);
	while (n1 > 0) {
		push(&p,n1 % 2);
		n1 = n1 / 2;
	}
	printf("Binário:");
	while (not empty(&p)) {
		printf("%d",pop(&p));
	}
	printf("\n");
	
	while (n2 > 0) {
		push(&p,n2 % 8);
		n2 = n2 / 8;
	}
	printf("Octal:");
	while (not empty(&p)) {
		printf("%d",pop(&p));
	}
	
	return 1;
}
