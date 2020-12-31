#include <string.h>
#define tam 100

typedef char elem[30];

typedef struct {
	elem m[tam];
	int fim;
} lista;

void linit(lista *l) {
	l->fim = 0;
}

void lins(lista *l,elem x) {
	if (l->fim < tam) {
		int i = l->fim;
		while (i > 0 && strcmp(x,l->m[i-1]) < 0) {
			strcpy(l->m[i],l->m[i-1]);
			i--;
		}
		strcpy(l->m[i],x);
		l->fim++;
	}
}

void lmostra(lista *l) {
	printf("[");
	int i;
	for (i=0;i<l->fim;i++) {
		printf("%s",l->m[i]);
		if (i < l->fim-1)
			printf(",");
	}
	printf("]");
}

int lconta(lista *l,elem x) {
	int i=0,no=0;
	while (i < l->fim && strcmp(x,l->m[i]) > 0)
		i++;
	while (i < l->fim && strcmp(x,l->m[i]) == 0) {
		no++;
		i++;
	}
	return no;
}

void lmostra_intervalo(lista *l,elem xi,elem xf) {
	int i=0;
	while (i < l->fim && strcmp(xi,l->m[i]) > 0)
		i++;
	while (i < l->fim && strcmp(xf,l->m[i]) >= 0) {
		printf("%s ",l->m[i]);
		i++;
	}
}

char lrem(lista *l,elem x) {
	int i=0;
	while (i < l->fim && strcmp(x,l->m[i]) > 0)
		i++;
	if (i < l->fim && strcmp(x,l->m[i]) == 0) { // ou usar !strcmp ao invés de == 0;
		while (i < l->fim-1) {
			strcpy(l->m[i],l->m[i+1]);
			i++;
		}
		l->fim--;
		return 1;
	}
	else
		return 0;
}
