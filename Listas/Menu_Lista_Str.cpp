#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include "listasstr.h"

int main(void) {
	setlocale(LC_ALL,"Portuguese");
	lista l1;
	int OP;
	elem x,xi,xf;
	linit(&l1);
	do {
		system("cls");
		printf("============Listas ordenadas============\n");
		printf("1.Inserir\n");
		printf("2.Remover\n");
		printf("3.Contar ocorr�ncias\n");
		printf("4.Mostra intervalo\n");
		printf("5.\n");
		printf("6.Sair do programa\n");
		printf("========================================\n");
		printf("Lista:");
		lmostra(&l1);
		printf("\n========================================\n");
		printf("Digite sua op��o:");
		scanf("%d",&OP);
		fflush(stdin);
		switch (OP) {
			case 1:
				printf("Entre com o elemento:");
				gets(x);
				lins(&l1,x);
				break;
			case 2:
				printf("Entre com o elemento:");
				gets(x);
				if (lrem(&l1,x))
					printf("Elemento removido com sucesso!\n");
				else
					printf("Elemento inexistente!\n");
				system("pause");
				break;
			case 3:
				printf("Entre com o elemento:");
				gets(x);
				printf("N�mero de ocorr�ncias: %d\n",lconta(&l1,x));
				system("pause");
				break;
			case 4:
				printf("Entre com o elemento inicial:");
				gets(xi);
				printf("Entre com o elemento final:");
				gets(xf);
				lmostra_intervalo(&l1,xi,xf);
				printf("\n");
				system("pause");
				break;
		}
	} while (OP != 6);
	return 1;
}
