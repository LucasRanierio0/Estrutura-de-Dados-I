#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include "pilhas.h"

int main(void) {
	setlocale(LC_ALL,"Portuguese");
	
	pilha p;
	int n,r,c,i;
	
	init(&p); // inicializar a pilha p;
	
	printf("Entre com um número em decimal:");
	scanf("%d",&n);
	c = n;
	
	while (n > 0) {
		r = n % 16;
		if (!isfull(&p))
		{
			push(&p,r);
		}
		else
		{
			printf("Pilha cheia!!");
			return 1; // exit(1);
		}
		n = n / 16;
	}
	
	printf("Correspondente em hexadecimal:");
	for (i=p.topo-1;i>=0;i--) {
		switch (p.m[i]) {
			case 10:
				printf("A");
				break;
			case 11:
				printf("B");
				break;
			case 12:
				printf("C");
				break;
			case 13:
				printf("D");
				break;
			case 14:
				printf("E");
				break;
			case 15:
				printf("F");
				break;
			default:
				printf("%d",p.m[i]);
		}
	}
	init(&p);	
	
	n = c;
	while (n > 0) {
		r = n % 8;
		if (!isfull(&p)) {
			push(&p,r);
		}
		else {
			printf("\nCorrespondente em octal:Pilha cheia!!");
			return 1; // exit(1);
		}
		n = n / 8;
	}
	
	printf("\nCorrespondente em octal:");
	while (!empty(&p))
	//while (p.topo>0)
	{
		printf("%d",pop(&p));
	}
	
	n = c;
	while (n > 0) {
		r = n % 2;
		if (!isfull(&p)) {
			push(&p,r);
		}
		else {
			printf("\nCorrespondente em binário:Pilha cheia!!");
			return 1; // exit(1);
		}
		n = n / 2;
	}
	
	printf("\nCorrespondente em binário:");
	while (!empty(&p))
	//while (p.topo>0)
	{
		printf("%d",pop(&p));
	}
	
	return 1;
}
