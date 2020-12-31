#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include "filas.h"

int main(void)
{
	setlocale(LC_ALL,"Portuguese");
	fila f1;
	int OP,x;
	qinit(&f1);
	do {
		system("cls");
		printf("==============Filas==============\n");
		printf("1.Inserir\n");
		printf("2.Remover\n");
		printf("3.=======\n");
		printf("4.Contar ocorrências\n");
		printf("5.Inserir no início\n");
		printf("6.Remover do final da fila\n");
		printf("7.\n");
		printf("8.Sair\n");
		printf("=================================\n");
		printf("Fila:");
		mostra(&f1);
		printf("\n");
		printf("=================================\n");
		printf("Sua opção:");
		scanf("%d",&OP);
		switch (OP) {
			case 1:
				if (qisfull(&f1)) {
					printf("A fila está cheia!\n");
				}
				else {
					printf("Informe o elemento:");
					scanf("%d",&x);
					enqueue(&f1,x);	
				}
				system("pause");
				break;
			case 2:
				if (!qisempty(&f1)) {
					x = dequeue(&f1);
					printf("Elemento removido:%d\n",x);
				}
				else {
					printf("A fila está vazia!\n");
				}
				system("pause");
				break;
			case 4:
				printf("Informe o elemento:");
				scanf("%d",&x);
				printf("O elemento %d ocorre %d vez(es) na fila.\n",x,conta(&f1,x));
				system("pause");
				break;
			case 5:
				if (qisfull(&f1)) {
					printf("A fila está cheia!\n");
				}
				else {
					printf("Informe o elemento:");
					scanf("%d",&x);
					enqueue_inicio(&f1,x);	
				}
				system("pause");
				break;
			case 6:
				if (!qisempty(&f1)) {
					x = dequeue_fim(&f1);
					printf("Elemento removido:%d\n",x);
				}
				else {
					printf("A fila está vazia!\n");
				}
				system("pause");
				break;
		}
	} while (OP!=8);
	
	return 1;
}
