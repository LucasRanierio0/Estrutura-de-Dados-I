#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

#define tam 4

typedef struct {
	char m[tam];
	int com,fim,total;
} fila;

void qinit(fila *f) {
	f->com = 0;
	f->fim = 0;
	f->total = 0;
}

void enqueue(fila *f,char x) {
	if (f->total < tam) {
		f->m[f->fim] = x;
		f->fim++;
	if (f->fim == tam)
		f->fim = 0;
	f->total++;
	}
}

char dequeue(fila *f) {
	if (f->total > 0) {
		char x = f->m[f->com];
		f->com++;
	if (f->com == tam)
		f->com = 0;
	f->total--;
	return x;
	}
}

char qisempty(fila *f) {
	if (f->total == 0)
		return 1;
	else
		return 0;
}

void mostra(fila *f) {
	printf("[");
	int i = f->com;
	int c;
	for (c=0;c<f->total;c++) {
		printf("%c",f->m[i]);
		i++;
		if (i == tam)
			i=0;
		if (c < f->total-1)
			printf(",");
	}
	printf("]");
}

int main(void) {
	setlocale(LC_ALL,"Portuguese");
	
	fila f1;
	qinit(&f1);
	enqueue(&f1,'a');
	enqueue(&f1,'b');
	enqueue(&f1,'c');
	enqueue(&f1,'d');
	enqueue(&f1,'e');
	
	printf("F1:");
	mostra(&f1);
	dequeue(&f1);
	dequeue(&f1);
	enqueue(&f1,'f');
	enqueue(&f1,'g');
	enqueue(&f1,'h');
	printf("\nF1:");
	mostra(&f1);
	
//	while (not qisempty(&f1)) {
//		printf("%c\n",dequeue(&f1));
//	}
	
	return 1;
}
