#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include "pilhas.h"

int main(void) {
	setlocale(LC_ALL,"Portuguese");
	
	int n,x,i;
	pilha pp,pi;
	
	init(&pp);
	init(&pi);
	
	printf("Quantidade de n�meros:");
	scanf("%d",&n);
	printf("\n");
	
	for (i=0;i<n;i++) {
		printf("%d� n�mero:",i+1);
		scanf("%d",&x);
		
		if (x % 2 == 0)
			push(&pp,x);
		else
			push(&pi,x);
	}
	
	printf("\nImpares:");
	while (!empty(&pi)) {
		printf("%d ",pop(&pi));
	}
	
	printf("\nPares:");
	while (!empty(&pp)) {
		printf("%d ",pop(&pp));
	}
	
	return 1;
}
